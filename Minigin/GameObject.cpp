#include "MiniginPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"


void dae::GameObject::Update(float deltaTime)
{
	for (std::shared_ptr<Component> component : m_Components)
	{
		component->Update(deltaTime);
	}
}

void dae::GameObject::FixedUpdate(float timeStep)
{
	for (std::shared_ptr<Component> component : m_Components)
	{
		component->FixedUpdate(timeStep);
	}
}

void dae::GameObject::SetParent(GameObject* parent)
{
	m_Parent = parent;
}

dae::GameObject* dae::GameObject::GetParent() const
{
	return m_Parent;
}

size_t dae::GameObject::GetChildCount() const
{
	return m_Children.size();
}

dae::GameObject* dae::GameObject::GetChildAt(int index) const
{
	return m_Children.at(index);
}

void dae::GameObject::RemoveChild(int index)
{
	m_Children.at(index)->SetParent(nullptr);
	m_Children.erase(m_Children.begin() + index);
}

void dae::GameObject::RemoveChildren()
{
	for (auto& child : m_Children)
		child->SetParent(nullptr);

	m_Children.clear();
}


void dae::GameObject::AddChild(GameObject* go)
{
	go->SetParent(this);
	m_Children.push_back(go);
}


