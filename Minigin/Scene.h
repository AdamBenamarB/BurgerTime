#pragma once
#include "SceneManager.h"
#include "Structs.h"

namespace dae
{
	class SceneObject;
	class GameObject;
	class Scene
	{
		friend Scene& SceneManager::CreateScene(const std::string& name);
	public:
		void Add(const std::shared_ptr<GameObject>& object);
		void Add(const std::shared_ptr<GameObject>& object,int renderPriority);
		void Remove(dae::GameObject* obj);

		std::vector<std::shared_ptr<GameObject>>&GetObjects() { return m_Objects; }
		std::string& GetName() { return m_Name; }


		void Update(float deltaTime);
		void FixedUpdate(float timeStep);
		void Render() const;
		void SetBounds(Bounds bounds) { m_Bounds = bounds; }
		Bounds GetBounds() const { return m_Bounds; }

		~Scene();
		Scene(const Scene& other) = delete;
		Scene(Scene&& other) = delete;
		Scene& operator=(const Scene& other) = delete;
		Scene& operator=(Scene&& other) = delete;

	private: 
		explicit Scene(const std::string& name);
		void DeleteObjects();
		std::string m_Name;
		std::vector < std::shared_ptr<GameObject>> m_ObjectsFirst{};
		std::vector < std::shared_ptr<GameObject>> m_ObjectsSecond{};
		std::vector < std::shared_ptr<GameObject>> m_ObjectsThird{};
		std::vector < std::shared_ptr<GameObject>> m_Objects{};
		std::vector<dae::GameObject*> m_ToRemove{};

		Bounds m_Bounds{};

		static unsigned int m_IdCounter; 
	};

}
