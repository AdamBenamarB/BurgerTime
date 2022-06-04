#include "EnemyComponent.h"

#include <iostream>

#include "CollisionComponent.h"
#include "GameObject.h"
#include "PlatformComponent.h"
#include "Scene.h"
#include "SceneManager.h"

dae::EnemyComponent::EnemyComponent(GameObject* owner)
	:Component(owner)
{
}

void dae::EnemyComponent::Update(float deltaTime)
{
	HandleMovement(deltaTime);
	HandleCollision(deltaTime);
}

void dae::EnemyComponent::HandleMovement(float deltaTime)
{
	auto pos = m_GameObject->GetTransform()->GetPosition();
	if (m_State != State::falling)
	{
		const auto& peterpos = m_Peter->GetTransform()->GetPosition();

		m_Direction.x = peterpos.x - pos.x;
		m_Direction.y = peterpos.y - pos.y;

		m_OnPlatform = false;
		m_OnLadder = false;
		float ladderX{};
		float platformY{};

		float closestLadder = 9999;
		float ladderDir{};
		for (auto& obj : SceneManager::GetInstance().GetActiveScene().GetObjects())
		{
			if (obj->GetTag() == "LADDER")
			{
				const auto& posladder = obj->GetTransform()->GetPosition();
				if (posladder.y - pos.y < 10.f)
					if (abs(posladder.x - pos.x) < closestLadder)
						ladderDir = posladder.x - pos.x;
			}

			if (m_GameObject->GetComponent<CollisionComponent>()->IsOverlapping(obj.get()))
				if (obj->GetTag().compare("PLATFORM") == 0)
				{
					if (!m_GameObject->GetComponent<CollisionComponent>()->IsUnder(obj.get()))
					{
						m_OnPlatform = true;
						platformY = obj->GetComponent<PlatformComponent>()->GetFloorPos().y+76;
					}
				}
				else if (obj->GetTag().compare("LADDER") == 0)
				{
					ladderX = obj->GetTransform()->GetPosition().x+8;

					if (abs(ladderX - m_GameObject->GetTransform()->GetPosition().x) < 10.f)
					{
						m_OnLadder = true;

					}

				}
		}
		if (m_OnLadder && abs(m_Direction.y) > 2.f)
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

		else if (m_OnPlatform)
		{
			if (abs(m_Direction.y) > 2.f)
			{
				if (ladderDir > 0)
				{
					pos.x += m_Speed * deltaTime;
					pos.y = platformY;
					m_State = State::right;
				}
				if (ladderDir < 0)
				{
					pos.x -= m_Speed * deltaTime;
					pos.y = platformY;
					m_State = State::left;
				}
			}
			else if (m_Direction.x > 0.f)
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


		m_GameObject->GetTransform()->SetPosition(pos.x, pos.y, 0);
	}
	else
	{
		pos.y += m_FallSpeed * deltaTime;
		m_GameObject->GetTransform()->SetPosition(pos.x, pos.y, pos.z);
	}
}

void dae::EnemyComponent::HandleCollision(float deltaTime)
{
	auto pos = m_GameObject->GetTransform()->GetPosition();
	if (m_State != State::falling)
	{
		m_Colliding = false;
		bool underLadder = false;
		int ladders = 0;

		for (auto& obj : SceneManager::GetInstance().GetActiveScene().GetObjects())
		{
			if (m_GameObject->GetComponent<CollisionComponent>()->IsOverlapping(obj.get()))
			{
				if (obj->GetTag().compare("WALL") == 0)
					m_Colliding = true;
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

		if (m_Colliding || underLadder)
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
	else
	{
		for (auto& obj : SceneManager::GetInstance().GetActiveScene().GetObjects())
		{
			if (m_GameObject->GetComponent<CollisionComponent>()->IsOverlapping(obj.get()))
			{
				if (obj.get()!=m_CurrentPlatform && obj->GetTag().compare("PLATFORM") == 0)
				{
					if (!m_GameObject->GetComponent<CollisionComponent>()->IsUnder(obj.get()))
					{
						auto floorpos = obj->GetComponent<PlatformComponent>()->GetFloorPos();
						pos.y = floorpos.y + 76;
						m_GameObject->GetTransform()->SetPosition(pos.x, pos.y, pos.z);
						m_State = State::left;
						return;
					}
					
				}
				
			}
		}
	}
}

void dae::EnemyComponent::SetState(State state)
{
	m_State = state;
	if(m_State== State::falling)
	{
		auto& pos = m_GameObject->GetTransform()->GetPosition();
		m_GameObject->GetTransform()->SetPosition(pos.x,pos.y+1,pos.z);
	}
}
