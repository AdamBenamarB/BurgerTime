#include "PeterPepperComponent.h"

#include <iostream>

#include "AnimatedRenderComponent.h"
#include "CollisionComponent.h"
#include "GameObject.h"
#include "PlatformComponent.h"
#include "Scene.h"
#include "SceneManager.h"

dae::PeterPepperComponent::PeterPepperComponent(GameObject* owner)
	:Component(owner)
{
}

void dae::PeterPepperComponent::Update(float deltaTime)
{
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
				ladderX = obj->GetTransform()->GetPosition().x;

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
		pos.y = platformY + 60;
		m_GameObject->GetTransform()->SetPosition(pos.x, pos.y, pos.z);
		break;
	case State::right:
		if (!m_OnPlatform)
			return;
		pos.x += m_Speed * deltaTime;
		pos.y = platformY + 60;
		m_GameObject->GetTransform()->SetPosition(pos.x, pos.y, pos.z);
		break;
	case State::up:
		if (!m_OnLadder)
			return;
		pos.y -= m_Speed * deltaTime;
		m_GameObject->GetTransform()->SetPosition(ladderX, pos.y, pos.z);
		break;
	case State::down:
		if (!m_OnLadder)
			return;
		pos.y += m_Speed * deltaTime;
		m_GameObject->GetTransform()->SetPosition(ladderX, pos.y, pos.z);
		break;
	}
}

void dae::PeterPepperComponent::HandleCollision(float deltaTime)
{
	auto pos = m_GameObject->GetTransform()->GetPosition();
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

	if (m_Colliding||underLadder)
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
			pos.y += m_Speed * deltaTime;
			m_GameObject->GetTransform()->SetPosition(pos.x, pos.y, pos.z);
			break;
		case State::down:
			pos.y -= m_Speed * deltaTime;
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
