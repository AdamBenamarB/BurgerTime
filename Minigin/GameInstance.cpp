#include "GameInstance.h"

#include "SceneManager.h"
#include "LevelLoader.h"
void GameInstance::FillPlate()
{
	++m_FullPlates;
	if(m_FullPlates>=1)//m_Plates)
	{
		if(m_LevelIdx==1)
		{
			auto& scene = dae::SceneManager::GetInstance().GetActiveScene();
			dae::SceneManager::GetInstance().RemoveScene(scene);
			
			m_LevelIdx = 2;
		}
		else if (m_LevelIdx == 2)
		{

			m_LevelIdx = 3;
		}
		else if (m_LevelIdx == 3)
		{

			m_LevelIdx = 1;
		}
	}
}

void GameInstance::SetPlates(int amt)
{
	m_Plates = amt;
	m_FullPlates = 0;
}

