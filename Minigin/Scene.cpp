#include "MiniginPCH.h"
#include "Scene.h"

#include "AnimatedRenderComponent.h"
#include "GameObject.h"
#include "RenderComponent.h"

using namespace dae;

unsigned int Scene::m_IdCounter = 0;

Scene::Scene(const std::string& name) : m_Name(name) {}

Scene::~Scene() = default;

void Scene::Add(const std::shared_ptr<GameObject>& object)
{
	m_Objects.push_back(object);
	m_ObjectsThird.push_back(object);
}

void Scene::Add(const std::shared_ptr<GameObject>& object, int renderLayer)
{
	if (renderLayer == 0)
		m_ObjectsFirst.push_back(object);
	if (renderLayer == 1)
		m_ObjectsSecond.push_back(object);
	if (renderLayer >= 2)
		m_ObjectsThird.push_back(object);
	m_Objects.push_back(object);
}


void Scene::Update(float deltaTime)
{
	DeleteObjects();
	for(auto& object : m_Objects)
	{
		object->Update(deltaTime);
	}
	
}

void dae::Scene::FixedUpdate(float timeStep)
{
	for (auto& object : m_Objects)
	{
		object->FixedUpdate(timeStep);
	}
}

void Scene::Render() const
{
	
	for (const auto& object : m_ObjectsThird)
	{
		for(auto render : object->GetComponents<RenderComponent>())
		{
			render->Render();
		}

	}

	for (const auto& object : m_ObjectsSecond)
	{
		for (auto render : object->GetComponents<RenderComponent>())
		{
			render->Render();
		}

	}
	
	for (const auto& object : m_ObjectsFirst)
	{
		for (auto render : object->GetComponents<RenderComponent>())
		{
			render->Render();
		}

	}
	
}

void Scene::Remove(dae::GameObject* obj)
{
	m_ToRemove.push_back(obj);
}

void Scene::DeleteObjects()
{
	for(auto& object:m_ToRemove)
	{
		for (int i{}; i < m_Objects.size(); ++i)
			if (m_Objects[i].get() == object)
				m_Objects.erase(m_Objects.begin()+i);

		for (int i{}; i < m_ObjectsFirst.size(); ++i)
			if (m_ObjectsFirst[i].get() == object)
				m_ObjectsFirst.erase(m_ObjectsFirst.begin() + i);

		for (int i{}; i < m_ObjectsSecond.size(); ++i)
			if (m_ObjectsSecond[i].get() == object)
				m_ObjectsSecond.erase(m_ObjectsSecond.begin() + i);

		for (int i{}; i < m_ObjectsThird.size(); ++i)
			if (m_ObjectsThird[i].get() == object)
				m_ObjectsThird.erase(m_ObjectsThird.begin() + i);

	}
	m_ToRemove.clear();
}