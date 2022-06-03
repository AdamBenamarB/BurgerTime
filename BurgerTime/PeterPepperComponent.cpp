#include "PeterPepperComponent.h"

#include "GameObject.h"

dae::PeterPepperComponent::PeterPepperComponent(GameObject* owner)
	:Component(owner)
{
}

void dae::PeterPepperComponent::Update(float deltaTime)
{
	auto pos = m_GameObject->GetTransform()->GetPosition();
	switch(m_State)
	{
	case State::idle:
		break;
	case State::left:
		pos.x -= m_Speed * deltaTime;
		m_GameObject->GetTransform()->SetPosition(pos.x,pos.y,pos.z);
		break;
	case State::right:
		pos.x += m_Speed * deltaTime;
		m_GameObject->GetTransform()->SetPosition(pos.x, pos.y, pos.z);
		break;
	case State::up:
		pos.y -= m_Speed * deltaTime;
		m_GameObject->GetTransform()->SetPosition(pos.x, pos.y, pos.z);
		break;
	case State::down:
		pos.y += m_Speed * deltaTime;
		m_GameObject->GetTransform()->SetPosition(pos.x, pos.y, pos.z);
		break;
	}
}
