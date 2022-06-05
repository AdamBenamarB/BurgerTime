#pragma once
#include <vector>

#include "Component.h"
#include "RenderComponent.h"
#include "Transform.h"

namespace dae {
	class CollisionComponent;

	class IngredientComponent : public Component
    {
    public:
        enum class State
        {
            idle,
            falling,
            plated
        };
        IngredientComponent(GameObject* owner);
        void Update(float deltaTime) override;
        void SetCollisions(std::vector<CollisionComponent*>& cols);
        void SetSprites(std::vector<RenderComponent*>& sprites);

        void SetState(State state);
        //void SetLevelsToFall()
    private:
        void HandleMovement(float deltaTime);
        void HandleCollision(float deltaTime);
        State m_State = State::idle;

        std::vector<CollisionComponent*> m_Collisions{};
        std::vector<RenderComponent*> m_Sprites{};
        bool m_DropStates[4]{false,false,false,false};//true is dropped

        float m_FallSpeed{ 150.f };

        GameObject* m_CollidedIngredient{ nullptr },
            *m_Platform{ nullptr };

        std::vector<GameObject*> m_Enemies{};

        int m_LevelsToFall{};
    };
}
