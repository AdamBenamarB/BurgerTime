#include "MiniginPCH.h"
#include "Component.h"

dae::Component::Component(GameObject* owner)
	:m_GameObject{owner}
{
}

void dae::Component::SetOwner(GameObject* owner)
{
	m_GameObject = owner;
}

void dae::Component::Update(float) 
{
}

void dae::Component::FixedUpdate(float)
{
}