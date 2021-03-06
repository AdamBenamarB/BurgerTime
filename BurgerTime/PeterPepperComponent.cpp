#include "PeterPepperComponent.h"

#include <iostream>

#include "AnimatedRenderComponent.h"
#include "CollisionComponent.h"
#include "GameInstance.h"
#include "GameObject.h"
#include "HealthComponent.h"
#include "InputManager.h"
#include "PlatformComponent.h"
#include "PointsComponent.h"
#include "Scene.h"
#include "SceneManager.h"
#include "ServiceLocator.h"

dae::PeterPepperComponent::PeterPepperComponent(GameObject* owner)
	:Component(owner)
{
}

dae::PeterPepperComponent::~PeterPepperComponent()
{

}


void dae::PeterPepperComponent::Update(float deltaTime)
{
	if(m_Hit)
	{
		m_ElapsedInv += deltaTime;
		if(m_ElapsedInv>m_m_InvTime)
		{
			m_Hit = false;
			m_ElapsedInv = 0;
		}
	}

	HandleMovement(deltaTime);
	HandleCollision(deltaTime);
	HandleAnim();
}

void dae::PeterPepperComponent::HandleMovement(float deltaTime)
{
	auto pos = m_GameObject->GetTransform()->GetPosition();
	m_OnPlatform = false;
	m_OnLadder = false;
	float ladderX{};
	float platformY{};

	for (auto& obj : SceneManager::GetInstance().GetActiveScene().GetObjects())
		{
		if (m_GameObject->GetComponent<CollisionComponent>()->IsOverlapping(obj.get()))
			if (obj->GetTag().compare("PLATFORM") == 0)
			{
				if (!m_GameObject->GetComponent<CollisionComponent>()->IsUnder(obj.get()))
				{
					m_OnPlatform = true;
					platformY = obj->GetComponent<PlatformComponent>()->GetFloorPos().y;
				}
			}
			else if (obj->GetTag().compare("LADDER") == 0)
			{
				ladderX = obj->GetTransform()->GetPosition().x+16;

				if (abs(ladderX - m_GameObject->GetTransform()->GetPosition().x) < 10.f)
				{
					m_OnLadder = true;
					
				}
				
			}
		}

	switch(m_State)
	{
	case State::idle:
		break;
	case State::left:
		if (!m_OnPlatform)
			return;
		pos.x -= m_Speed * deltaTime;
		pos.y = platformY + 92;
		m_GameObject->GetTransform()->SetPosition(pos.x, pos.y, pos.z);
		break;
	case State::right:
		if (!m_OnPlatform)
			return;
		pos.x += m_Speed * deltaTime;
		pos.y = platformY + 92;
		m_GameObject->GetTransform()->SetPosition(pos.x, pos.y, pos.z);
		break;
	case State::up:
		if (!m_OnLadder)
			return;
		pos.y -= m_LadderSpeed * deltaTime;
		m_GameObject->GetTransform()->SetPosition(ladderX, pos.y, pos.z);
		break;
	case State::down:
		if (!m_OnLadder)
			return;
		pos.y += m_LadderSpeed * deltaTime;
		m_GameObject->GetTransform()->SetPosition(ladderX, pos.y, pos.z);
		break;
	}
}

void dae::PeterPepperComponent::HandleCollision(float deltaTime)
{
	auto pos = m_GameObject->GetTransform()->GetPosition();

	bool underLadder = false;
	int ladders = 0;
	int platforms = 0;
	bool offPlatform = false;
	for (auto& obj : SceneManager::GetInstance().GetActiveScene().GetObjects())
	{
		if (m_GameObject->GetComponent<CollisionComponent>()->IsOverlapping(obj.get()))
		{
			/*if (obj->GetTag().compare("WALL") == 0)
				m_Colliding = true;*/
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
		offPlatform = false;


	if (underLadder||offPlatform)
	{
		switch (m_State)
		{
		case State::idle:
			break;
		case State::left:
			pos.x += m_Speed * deltaTime;
			m_GameObject->GetTransform()->SetPosition(pos.x, pos.y, pos.z);
			break;
		case State::right:
			pos.x -= m_Speed * deltaTime;
			m_GameObject->GetTransform()->SetPosition(pos.x, pos.y, pos.z);
			break;
		case State::up:
			pos.y += m_LadderSpeed * deltaTime;
			m_GameObject->GetTransform()->SetPosition(pos.x, pos.y, pos.z);
			break;
		case State::down:
			pos.y -= m_LadderSpeed * deltaTime;
			m_GameObject->GetTransform()->SetPosition(pos.x, pos.y, pos.z);
			break;
		}
	}
}

void dae::PeterPepperComponent::InitAnimation(AnimatedRenderComponent* comp)
{
	if (comp == nullptr)
		return;

	m_Anim = comp;

	m_Idle = m_Anim->AddClip(1, false);
	m_RunLeft = m_Anim->AddClip(3, true);
	m_RunRight = m_Anim->AddClip(3, true);
	m_Climb = m_Anim->AddClip(3, true);
	m_ClimbDown = m_Anim->AddClip(3, true);
}

void dae::PeterPepperComponent::HandleAnim()
{
	switch (m_State)
	{
	case State::idle:
		m_Anim->SetClip(m_Idle);
		break;
	case State::left:
		if(m_OnPlatform)
		m_Anim->SetClip(m_RunLeft);
		break;
	case State::right:
		if (m_OnPlatform)
		m_Anim->SetClip(m_RunRight);
		break;
	case State::up:
		if(m_OnLadder)
		m_Anim->SetClip(m_Climb);
		break;
	case State::down:
		if(m_OnLadder)
		m_Anim->SetClip(m_ClimbDown);
		break;
	}
}

void dae::PeterPepperComponent::SetState(State state)
{
	m_State = state;
	switch (m_State)
	{
	case State::idle:
		break;
	case State::left:
		break;
	case State::right:
		break;
	case State::up:
		break;
	case State::down:
		break;
	}
}

void dae::PeterPepperComponent::Hit()
{
	if(!m_Hit)
	{
		m_Hit = true;
		auto hp = m_GameObject->GetComponent<HealthComponent>();
		hp->Hit();
		if (hp->GetLives() == 0)
			GameInstance::GetInstance().Died(m_GameObject->GetComponent<PointsComponent>()->GetPoints());
	}
}

void dae::PeterPepperComponent::AddPoints(GameObject* go)
{
	std::string tag = go->GetTag();

	if (tag == "MRHOTDOG")
		m_GameObject->GetComponent<PointsComponent>()->AddPoints(100);
	else if (tag == "MRPICKLE")
		m_GameObject->GetComponent<PointsComponent>()->AddPoints(200);
	else if (tag == "MREGG")
		m_GameObject->GetComponent<PointsComponent>()->AddPoints(300);
}

void dae::PeterPepperComponent::AddPoints(int amt)
{
	m_GameObject->GetComponent<PointsComponent>()->AddPoints(amt);
	
}

