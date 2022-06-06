#include "EnemyComponent.h"

#include <iostream>

#include "AnimatedRenderComponent.h"
#include "CollisionComponent.h"
#include "GameObject.h"
#include "IngredientComponent.h"
#include "PeterPepperComponent.h"
#include "PlatformComponent.h"
#include "Scene.h"
#include "SceneManager.h"
#include "ServiceLocator.h"

dae::EnemyComponent::EnemyComponent(GameObject* owner)
	:Component(owner)
{
	Initialize();
}

void dae::EnemyComponent::Update(float deltaTime)
{
	HandleMovement(deltaTime);
	HandleCollision(deltaTime);
	HandleAnim();
	HandleStun(deltaTime);
}

void dae::EnemyComponent::HandleMovement(float deltaTime)
{
	auto pos = m_GameObject->GetTransform()->GetPosition();
	if (m_State != State::falling && m_State != State::stunned)
	{
		const auto& peterpos = m_Peter->GetTransform()->GetPosition();
		

		m_OnPlatform = false;
		m_OnLadder = false;
		float ladderX{};
		float platformY{};
		int platforms{};

		PlatformComponent* platform = nullptr;
		std::vector<GameObject*> ladderObj{};

		for (auto& obj : SceneManager::GetInstance().GetActiveScene().GetObjects())
		{

			if (m_GameObject->GetComponent<CollisionComponent>()->IsOverlapping(obj.get()))
			{
				if (obj.get() == m_Peter)
					m_Peter->GetComponent<PeterPepperComponent>()->Hit();
				if (obj->GetTag().compare("PLATFORM") == 0)
				{
					if (!m_GameObject->GetComponent<CollisionComponent>()->IsUnder(obj.get()))
					{
						m_OnPlatform = true;
						platform = obj->GetComponent<PlatformComponent>();
						platformY = platform->GetFloorPos().y + 92;
						++platforms;
					}
				}
				else if (obj->GetTag().compare("LADDER") == 0)
				{
					ladderObj.push_back(obj.get());
					if (!m_GameObject->GetComponent<CollisionComponent>()->IsUnder(obj.get()))
					{
						ladderX = obj->GetTransform()->GetPosition().x + 16;
						if (abs(ladderX - m_GameObject->GetTransform()->GetPosition().x) < 10.f)
						{
							m_OnLadder = true;
						}
					}


				}
			}
		}
		if (m_OnLadder && !m_OnPlatform)
		{
			m_Direction.x = peterpos.x - pos.x;
			m_Switched = false;
			if (m_Direction.y > 0.f)
			{
				pos.y += m_ClimbSpeed * deltaTime;
				pos.x = ladderX;
				m_State = State::down;
			}
			else if (m_Direction.y < 0.f)
			{
				pos.y -= m_ClimbSpeed * deltaTime;
				pos.x = ladderX;
				m_State = State::up;
			}
		}
		else if (m_OnPlatform && !m_OnLadder)
		{
			m_Direction.y = peterpos.y - pos.y;
			m_Switched = false;
			if (m_Direction.x > 0.f)
			{
				pos.x += m_Speed * deltaTime;
				pos.y = platformY;
				m_State = State::right;

			}
			else if (m_Direction.x < 0.f)
			{
				pos.x -= m_Speed * deltaTime;
				pos.y = platformY;
				m_State = State::left;

			}
		}
		else if(m_OnLadder && m_OnPlatform)
		{
			m_Direction.x = peterpos.x - pos.x;
			m_Direction.y = peterpos.y - pos.y;

			m_Horizontal = true;
			if (ladderObj.size() == 1)
			{

				if (m_Direction.y > 0)
					m_Switched = ladderObj.at(0)->GetComponent<CollisionComponent>()->IsUnder(Rect{ pos.x,pos.y + m_ClimbSpeed * deltaTime ,32,34 });

			}
			
			if(abs(m_Direction.y)>10.f && !m_Switched)
				m_Horizontal = false;

			else
			{
				m_Horizontal = true;
			}
			

			if (!m_Horizontal)
			{
				if (m_Direction.y > 0.f)
				{
					pos.y += m_ClimbSpeed * deltaTime;
					pos.x = ladderX;
					m_State = State::down;
				}
				else if (m_Direction.y < 0.f)
				{
					pos.y -= m_ClimbSpeed * deltaTime;
					pos.x = ladderX;
					m_State = State::up;
				}
			}
			else
			{
				if (m_Direction.x > 0.f)
				{
					pos.x += m_Speed * deltaTime;
					pos.y = platformY;
					m_State = State::right;

				}
				else if (m_Direction.x < 0.f)
				{
					pos.x -= m_Speed * deltaTime;
					pos.y = platformY;
					m_State = State::left;

				}
			}
		}

		m_GameObject->GetTransform()->SetPosition(pos.x, pos.y, 0);
	}
	else if(m_State==State::falling)
	{
		pos.y += m_FallSpeed * deltaTime;
		m_GameObject->GetTransform()->SetPosition(pos.x, pos.y, pos.z);
	}
}

void dae::EnemyComponent::HandleCollision(float deltaTime)
{
	auto pos = m_GameObject->GetTransform()->GetPosition();
	if (m_State != State::falling && m_State != State::dead)
	{
		bool underLadder = false;
		int ladders = 0;

		int platforms = 0;
		bool offPlatform = false;
		for (auto& obj : SceneManager::GetInstance().GetActiveScene().GetObjects())
		{
			if (m_GameObject->GetComponent<CollisionComponent>()->IsOverlapping(obj.get()))
			{
				if (obj->GetTag().compare("PLATFORM") == 0)
				{
					++platforms;
					if (m_GameObject->GetComponent<CollisionComponent>()->IsToSide(obj.get()))
					{
						offPlatform = true;
					}
				}
				else if (obj->GetTag().compare("LADDER") == 0)
				{
					++ladders;
					if (m_GameObject->GetComponent<CollisionComponent>()->IsUnder(obj.get()))
					{
						underLadder = true;
					}
				}
				
			}
		}
		if (ladders > 1)
			underLadder = false;

		if (platforms > 1)
		{
			offPlatform = false;
		}
		else if(offPlatform)
			m_Direction.x = -m_Direction.x;


		if (offPlatform || underLadder)
		{
			switch (m_State)
			{
			case State::left:
				pos.x += m_Speed * deltaTime;
				break;
			case State::right:
				pos.x -= m_Speed * deltaTime;
				break;
			case State::up:
				pos.y += m_ClimbSpeed * deltaTime;
				break;
			case State::down:
				pos.y -= m_ClimbSpeed * deltaTime;
				break;
			}
			m_GameObject->GetTransform()->SetPosition(pos.x, pos.y, pos.z);
		}
	}
	
}

void dae::EnemyComponent::SetState(State state)
{
	m_State = state;
	if(m_State== State::falling)
	{
		ServiceLocator::GetSoundSystem().Play(m_Fall, 100);
		auto& pos = m_GameObject->GetTransform()->GetPosition();
		m_GameObject->GetTransform()->SetPosition(pos.x,pos.y+3,pos.z);
	}
}

void dae::EnemyComponent::InitAnimation(AnimatedRenderComponent* animComp,std::string textureLoc)
{
	if (animComp == nullptr)
		return;
	animComp->SetTexture(textureLoc);

	m_Anim = animComp;
	
	m_RunLeft = m_Anim->AddClip(2, true);
	m_RunRight = m_Anim->AddClip(2, true);
	m_ClimbDown = m_Anim->AddClip(2, true);
	m_Climb = m_Anim->AddClip(2, true);
	m_Stunned = m_Anim->AddClip(2, false);
}

void dae::EnemyComponent::HandleAnim() const
{
	switch(m_State)
	{
	case State::left:
		m_Anim->SetClip(m_RunLeft);
		return;
	case State::right:
		m_Anim->SetClip(m_RunRight);
		return;
	case State::down:
		m_Anim->SetClip(m_ClimbDown);
		return;
	case State::up:
		m_Anim->SetClip(m_Climb);
		return;
	case State::stunned:
		m_Anim->SetClip(m_Stunned);
		return;
	}
}

void dae::EnemyComponent::SetPeter(GameObject* peterObj)
{
	if (!peterObj)
		return;
	m_Peter = peterObj;
	auto& pos = m_GameObject->GetTransform()->GetPosition();
	auto& peterpos = m_Peter->GetTransform()->GetPosition();

	m_Direction.x = peterpos.x - pos.x;
	m_Direction.y = peterpos.y - pos.y;
}

void dae::EnemyComponent::Kill()
{
	m_Peter->GetComponent<PeterPepperComponent>()->AddPoints(m_GameObject);

	ServiceLocator::GetSoundSystem().Play(m_Hit, 100);
	//m_State = State::dead;
	SceneManager::GetInstance().GetActiveScene().Remove(m_GameObject);
}

void dae::EnemyComponent::Initialize()
{
	m_Hit = dae::ServiceLocator::GetSoundSystem().AddSound("../Data/Sounds/enemyhit.wav");
	m_Fall = dae::ServiceLocator::GetSoundSystem().AddSound("../Data/Sounds/enemyfall.wav");
}

void dae::EnemyComponent::HandleStun(float deltaTime)
{
	if(m_State==State::stunned)
	{
		m_StunElapsed += deltaTime;
		if(m_StunElapsed>m_StunTime)
		{
			m_State = State::left;
			m_StunElapsed = 0;
		}
	}
}

void dae::EnemyComponent::Stun()
{
	m_State = State::stunned;
}
