#pragma once

#include <type_traits>
#include <memory>
#include <vector>
#include "Transform.h"
namespace dae
{
	class Component;
	class GameObject final
	{
	public:
		GameObject() { m_Transform = AddComponent<Transform>(); };
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		void Update(float deltaTime);
		void FixedUpdate(float timeStep);

		Transform* GetTransform() { return m_Transform; }

		template<typename T> T* AddComponent();
		template<typename T> T* GetComponent() const;
		template<typename T> void RemoveComponent();

		void SetParent(GameObject* parent);
		GameObject* GetParent() const;

		size_t GetChildCount() const;
		GameObject* GetChildAt(int index) const;
		void RemoveChild(int index);
		void AddChild(GameObject* go);

		void SetTag(std::string tag) { m_Tag = tag; }
		const std::string& GetTag() const { return m_Tag; }
	private:
		std::vector<std::shared_ptr<Component>> m_Components{};
		GameObject* m_Parent{};
		std::vector<GameObject*> m_Children{};
		Transform* m_Transform;
		std::string m_Tag{"NONE"};
	};
}

//TEMPLATED FUNCTIONS
template <typename T> 
T* dae::GameObject::AddComponent()
{
	if (std::is_base_of<Component, T>())
	{

		std::shared_ptr < T > ptr = std::make_shared<T>(this);
		m_Components.push_back(ptr);
		return ptr.get();
	}
	else return nullptr;
}

template <typename T> 
T* dae::GameObject::GetComponent() const
{
	for(std::shared_ptr<Component> comp : m_Components)
	{
		if (typeid(T) == typeid(*comp))
		{
			return (T*)comp.get();
		}
		
	}
	return nullptr;
}


template<typename T> 
void dae::GameObject::RemoveComponent()
{
	for (auto it = m_Components.begin(); it < m_Components.end();)
	{
		if (typeid(**it) == typeid(T))
		{
			it = m_Components.erase(it);
		}
		else
		{
			++it;
		}
	}
	
}

