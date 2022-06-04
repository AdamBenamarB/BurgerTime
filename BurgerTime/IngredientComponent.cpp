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

void dae::IngredientComponent::HandleCollision(float deltaTime)
{
	if (m_State == State::idle)
	{
		for (auto& obj : SceneManager::GetInstance().GetActiveScene().GetObjects())
		{

			for (int i{}; i < m_Collisions.size(); ++i)
			{
				if (m_Collisions[i]->IsOverlapping(obj.get()))
					if (obj->GetTag().compare("PETER") == 0)
					{
						m_DropStates[i] = true;
						m_Sprites[i]->SetOffsetY(5);
					}

			}
		}

		for (int i{}; i < 4; ++i)
		{
			if (m_DropStates[i] == false)
				return;
		}
		m_State = State::falling;
		for(int i{};i<4;++i)
		{
			m_DropStates[i] = false;
			m_Sprites[i]->SetOffsetY(0);
		}
	}
	if (m_State == State::falling)
	{
		auto pos = m_GameObject->GetTransform()->GetPosition();
		pos.y += m_FallSpeed * deltaTime;
		m_GameObject->GetTransform()->SetPosition(pos.x,pos.y,pos.z);

		for (auto& obj : SceneManager::GetInstance().GetActiveScene().GetObjects())
		{

			if (m_Collisions[1]->IsOverlapping(obj.get()))
			{
				if (obj->GetTag().compare("PLATFORM") == 0)
				{
					if (!m_Collisions[1]->IsUnder(obj.get()))
					{
						m_State = State::idle;
						m_CollidedIngredient = nullptr;
					}
				}

				if(obj.get()!=m_CollidedIngredient)
				if (auto comp = obj->GetComponent<IngredientComponent>())
				{
					m_CollidedIngredient = obj.get();
					comp->SetState(State::falling);
					auto posi = obj->GetTransform()->GetPosition();
					m_GameObject->GetTransform()->SetPosition(posi.x,posi.y,posi.z);
					m_State = State::idle;
				}
			}
		}

	}
}

void dae::IngredientComponent::SetCollisions(std::vector<CollisionComponent*>& cols)
{
	m_Collisions = cols;
}

void dae::IngredientComponent::SetSprites(std::vector<RenderComponent*>& sprites)
{
	m_Sprites = sprites;
}
