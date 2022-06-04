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
		for (auto render : object->GetComponents<AnimatedRenderComponent>())
		{
			render->Render();
		}

	}
}

