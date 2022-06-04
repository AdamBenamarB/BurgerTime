#include "IngredientComponent.h"

#include <iostream>

#include "CollisionComponent.h"
#include "GameObject.h"
#include "Scene.h"
#include "SceneManager.h"

dae::IngredientComponent::IngredientComponent(GameObject* owner)
	:Component(owner)
{
}

void dae::IngredientComponent::Update(float deltaTime)
{
	HandleMovement(deltaTime);
	HandleCollision(deltaTime);
}

void dae::IngredientComponent::HandleMovement(float)// deltaTime)
{
	
}

void dae::IngredientComponent::HandleCollision(float)// deltaTime)
{
	for (auto& obj : SceneManager::GetInstance().GetActiveScene().GetObjects())
	{

		for (int i{};i<m_Collisions.size();++i)
		{
			if (m_Collisions[i]->IsOverlapping(obj.get()))
				if (obj->GetTag().compare("PETER") == 0)
				{
					m_DropStates[i] = true;
					m_Sprites[i]->SetOffsetY(10);
					std::cout << "Overlap at: " << i << std::endl;
				}

		}
	}

	for(int i{};i<4;++i)
	{
		if (m_DropStates[i] == false)
			return;
	}
	m_State = State::falling;
}

void dae::IngredientComponent::SetCollisions(std::vector<CollisionComponent*>& cols)
{
	m_Collisions = cols;
}

void dae::IngredientComponent::SetSprites(std::vector<RenderComponent*>& sprites)
{
	m_Sprites = sprites;
}
