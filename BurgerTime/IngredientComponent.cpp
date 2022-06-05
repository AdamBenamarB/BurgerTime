#include "IngredientComponent.h"

#include <iostream>

#include "CollisionComponent.h"
#include "EnemyComponent.h"
#include "GameInstance.h"
#include "GameObject.h"
#include "PeterPepperComponent.h"
#include "Scene.h"
#include "SceneManager.h"

dae::IngredientComponent::IngredientComponent(GameObject* owner)
	:Component(owner)
{
}

void dae::IngredientComponent::Update(float deltaTime)
{
	if(!m_Peter)
	{
		for (auto& obj : SceneManager::GetInstance().GetActiveScene().GetObjects())
		{
			if (obj->GetTag() == "PETER")
			{
				m_Peter = obj.get();
				break;
			}
		}
	}
	HandleMovement(deltaTime);
	HandleCollision(deltaTime);
}

void dae::IngredientComponent::HandleMovement(float deltaTime)
{
	if (m_State == State::falling)
	{
		auto pos = m_GameObject->GetTransform()->GetPosition();
		pos.y += m_FallSpeed * deltaTime;
		m_GameObject->GetTransform()->SetPosition(pos.x, pos.y, pos.z);
	}

}

void dae::IngredientComponent::HandleCollision(float)// deltaTime)
{
	if (m_State == State::idle)
	{
		m_Next = false;
		m_Enemies.clear();
		bool onPlatform = false;
		for (auto& obj : SceneManager::GetInstance().GetActiveScene().GetObjects())
		{

			for (int i{}; i < m_Collisions.size(); ++i)
			{
				if (m_Collisions[i]->IsOverlapping(obj.get()))
					if (obj->GetTag().compare("PETER") == 0)
					{
						m_Peter = obj.get();
						m_DropStates[i] = true;
						m_Sprites[i]->SetOffsetY(5);
					}
					else if (obj->GetComponent<EnemyComponent>())
					{
						bool exists = false;
						for (auto& enemy : m_Enemies)
							if (enemy == obj.get())
								exists = true;
						if (!exists)
							m_Enemies.push_back(obj.get());
					}
					else if(i==1)
					{
						if (obj->GetTag().compare("PLATFORM") == 0)
						{
							onPlatform = true;
						}
					}
			}
		}
		if (!onPlatform)
			m_State = State::falling;

		for (int i{}; i < 4; ++i)
		{
			if (m_DropStates[i] == false)
				return;
		}
		SetState(State::falling);
		m_CollidedIngredient = nullptr;
		for(int i{};i<4;++i)
		{
			m_DropStates[i] = false;
			m_Sprites[i]->SetOffsetY(0);
		}
		m_LevelsToFall = (int)m_Enemies.size();
		if(m_LevelsToFall==1)
			m_Peter->GetComponent<PeterPepperComponent>()->AddPoints(500);
		if (m_LevelsToFall == 2)
			m_Peter->GetComponent<PeterPepperComponent>()->AddPoints(1000);
		else if (m_LevelsToFall == 3)
			m_Peter->GetComponent<PeterPepperComponent>()->AddPoints(2000);
		else if (m_LevelsToFall == 4)
			m_Peter->GetComponent<PeterPepperComponent>()->AddPoints(4000);
		else if (m_LevelsToFall == 5)
			m_Peter->GetComponent<PeterPepperComponent>()->AddPoints(8000);
		else if (m_LevelsToFall == 6)
			m_Peter->GetComponent<PeterPepperComponent>()->AddPoints(1600);
		for(auto& enemy:m_Enemies)
		{
			enemy->GetComponent<EnemyComponent>()->SetState(EnemyComponent::State::falling);
		}
	}
	else if (m_State == State::falling)
	{
		for (auto& obj : SceneManager::GetInstance().GetActiveScene().GetObjects())
		{

			if (m_Collisions[1]->IsOverlapping(obj.get()))
			{
				if (obj.get() != m_Platform)
					if (obj->GetTag().compare("PLATFORM") == 0)
					{						
							if (!m_Collisions[1]->IsUnder(obj.get()))
							{
								if (m_LevelsToFall == 0)
								{
									m_Platform = nullptr;
									m_State = State::idle;
									m_CollidedIngredient = nullptr;

									m_Peter->GetComponent<PeterPepperComponent>()->AddPoints(50);
								}
								else
								{
									m_Platform = obj.get();
									--m_LevelsToFall;
									m_Peter->GetComponent<PeterPepperComponent>()->AddPoints(50);
								}
							}						
					}

				if (auto enemy = obj->GetComponent<EnemyComponent>())
				{
					if (!m_Next)
					{
						bool enemyOn = false;
						for (auto enemyon : m_Enemies)
							if (enemyon == obj.get())
								enemyOn = true;

						if (!enemyOn)
							enemy->Kill();
					}
				}


				if (auto comp = obj->GetComponent<IngredientComponent>())
				{
					if (comp->m_State == State::plated)
					{
						m_State = State::plated;
						for(auto enemy:m_Enemies)
						{
							enemy->GetComponent<EnemyComponent>()->Kill();
						}
						m_Enemies.clear();
						if (m_GameObject->GetTag() == "BUN")
							GameInstance::GetInstance().FillPlate();
					}
					else {
					for (auto enemy : m_Enemies)
						{
							bool exists = false;
							for (auto existing : comp->m_Enemies)
								if (enemy == existing)
									exists = true;
							if(!exists)
									comp->m_Enemies.push_back(enemy);

						}
						m_Enemies.clear();
						m_CollidedIngredient = obj.get();
						comp->SetState(State::falling);
						m_Next = true;
					}
				}


				if (obj->GetTag().compare("PLATE") == 0)
				{
						m_State = State::plated;
						for (auto enemy : m_Enemies)
							enemy->GetComponent<EnemyComponent>()->Kill();
						m_Enemies.clear();

						m_Peter->GetComponent<PeterPepperComponent>()->AddPoints(50);
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

void dae::IngredientComponent::SetState(State state)
{
	if (m_State != State::plated)
	{
		m_State = state;
		if (m_State == State::falling)
		{
			for (auto& obj : SceneManager::GetInstance().GetActiveScene().GetObjects())
			{
				if (m_Collisions[1]->IsOverlapping(obj.get()))
				{
					if (obj->GetTag().compare("PLATFORM") == 0)
					{
						m_Platform = obj.get();
					}
				}
			}
			for (int i{}; i < 4; ++i)
			{
				m_DropStates[i] = false;
				m_Sprites[i]->SetOffsetY(0);
			}
		}
	}
}
