#include "EnemySpawnComponent.h"

#include <iostream>

#include "CollisionComponent.h"
#include "EnemyComponent.h"
#include "GameObject.h"
#include "MrEgg.h"
#include "Scene.h"
#include "SceneManager.h"

dae::EnemySpawnComponent::EnemySpawnComponent(GameObject* owner)
	:Component(owner)
{
	m_ELapsedTime = m_TimePerSpawn;
}

void dae::EnemySpawnComponent::Update(float deltaTime)
{
	m_ELapsedTime += deltaTime;
	if(m_ELapsedTime>=m_TimePerSpawn)
	{
		m_ELapsedTime = 0;
		//int random = rand() % 3;

		auto& scene = SceneManager::GetInstance().GetActiveScene();
		if(!m_Peter)
		{
			for(auto& obj:scene.GetObjects())
			{
				if (obj->GetTag() == "PETER")
					m_Peter = obj.get();
			}
			
		}

		auto& pos = m_GameObject->GetTransform()->GetPosition();
			

//		if(random == 0)
		if(true)
		{
			MrEgg{ scene,{pos.x,pos.y},m_Peter };
		}
	}

}
