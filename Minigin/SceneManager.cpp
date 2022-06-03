#include "MiniginPCH.h"
#include "SceneManager.h"
#include "Scene.h"

void dae::SceneManager::Update(float deltaTime)
{
	/*for(auto& scene : m_Scenes)
	{
		scene->Update(deltaTime);
	}*/
	if (m_ActiveScene)
		m_ActiveScene->Update(deltaTime);
}

void dae::SceneManager::FixedUpdate(float timeStep)
{
	/*for (auto& scene : m_Scenes)
	{
		scene->FixedUpdate(timeStep);
	}*/
	if (m_ActiveScene)
		m_ActiveScene->FixedUpdate(timeStep);
}

void dae::SceneManager::Render()
{
	/*for (const auto& scene : m_Scenes)
	{
		scene->Render();
	}*/
	if (m_ActiveScene)
		m_ActiveScene->Render();
}

dae::Scene& dae::SceneManager::CreateScene(const std::string& name)
{
	const auto& scene = std::shared_ptr<Scene>(new Scene(name));
	m_Scenes.push_back(scene);
	m_ActiveScene = scene.get();
	return *scene;
}

void dae::SceneManager::SetActiveScene(std::string sceneName)
{
	for (auto& scene : m_Scenes)
		if (scene->GetName().compare(sceneName)==0)
			m_ActiveScene = scene.get();
}

dae::Scene& dae::SceneManager::GetActiveScene() const
{
	return *m_ActiveScene;
}