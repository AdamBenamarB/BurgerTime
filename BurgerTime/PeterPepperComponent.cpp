#include "PeterPepperComponent.h"

#include <iostream>

#include "CollisionComponent.h"
#include "GameObject.h"
#include "Scene.h"
#include "SceneManager.h"

dae::PeterPepperComponent::PeterPepperComponent(GameObject* owner)
	:Component(owner)
{
}

void dae::PeterPepperComponent::Update(float deltaTime)
{
	//auto pos = m_GameObject->GetTransform()->GetPosition();
	//bool onLadder = false;
	///*for(auto& obj :SceneManager::GetInstance().GetActiveScene().GetObjects())
	//{
	//	if (m_GameObject->GetComponent<CollisionComponent>()->IsOverlapping(obj.get()))
	//		if (obj->GetTag().compare("WALL")==0)
	//			std::cout << "WALL";
	//}*/
	//switch(m_State)
	//{
	//case State::idle:
	//	break;
	//case State::left:
	//	
	//	pos.x -= m_Speed * deltaTime;
	//	m_GameObject->GetTransform()->SetPosition(pos.x,pos.y,pos.z);
	//	break;
	//case State::right:
	//	pos.x += m_Speed * deltaTime;
	//	m_GameObject->GetTransform()->SetPosition(pos.x, pos.y, pos.z);
	//	break;
	//case State::up:
	//	for (auto& obj : SceneManager::GetInstance().GetActiveScene().GetObjects())
	//	{
	//		if (m_GameObject->GetComponent<CollisionComponent>()->IsOverlapping(obj.get()))
	//			if (obj->GetTag().compare("WALL") == 0)
	//				onLadder = true;
	//	}
	//	if (!onLadder)
	//		return;
	//	pos.y -= m_Speed * deltaTime;
	//	m_GameObject->GetTransform()->SetPosition(pos.x, pos.y, pos.z);
	//	break;
	//case State::down:
	//	pos.y += m_Speed * deltaTime;
	//	m_GameObject->GetTransform()->SetPosition(pos.x, pos.y, pos.z);
	//	break;
	//}
	HandleMovement(deltaTime);
	HandleCollision(deltaTime);
}

void dae::PeterPepperComponent::HandleMovement(float deltaTime)
{
	auto pos = m_GameObject->GetTransform()->GetPosition();
	bool onPlatform = false;
	bool onLadder = false;

	for (auto& obj : SceneManager::GetInstance().GetActiveScene().GetObjects())
		{
		if (m_GameObject->GetComponent<CollisionComponent>()->IsOverlapping(obj.get()))
			if (obj->GetTag().compare("PLATFORM") == 0)
			{
				if (!m_GameObject->GetComponent<CollisionComponent>()->IsUnder(obj.get()))
					onPlatform = true;
			}
			else if (obj->GetTag().compare("LADDER") == 0)
				if (abs(obj->GetTransform()->GetPosition().x - m_GameObject->GetTransform()->GetPosition().x)<5.f)
					onLadder = true;
		}

	switch(m_State)
	{
	case State::idle:
		break;
	case State::left:
		if (!onPlatform)
			return;
		pos.x -= m_Speed * deltaTime;
		m_GameObject->GetTransform()->SetPosition(pos.x, pos.y, pos.z);
		break;
	case State::right:
		if (!onPlatform)
			return;
		pos.x += m_Speed * deltaTime;
		m_GameObject->GetTransform()->SetPosition(pos.x, pos.y, pos.z);
		break;
	case State::up:
		if (!onLadder)
			return;
		pos.y -= m_Speed * deltaTime;
		m_GameObject->GetTransform()->SetPosition(pos.x, pos.y, pos.z);
		break;
	case State::down:
		if (!onLadder)
			return;
		pos.y += m_Speed * deltaTime;
		m_GameObject->GetTransform()->SetPosition(pos.x, pos.y, pos.z);
		break;
	}
}

void dae::PeterPepperComponent::HandleCollision(float deltaTime)
{
	auto pos = m_GameObject->GetTransform()->GetPosition();
	bool colliding = false;

	for (auto& obj : SceneManager::GetInstance().GetActiveScene().GetObjects())
	{
		if (m_GameObject->GetComponent<CollisionComponent>()->IsOverlapping(obj.get()))
			if (obj->GetTag().compare("WALL") == 0)
				colliding = true;
	}
	if (colliding)
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
