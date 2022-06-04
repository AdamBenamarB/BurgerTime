#pragma once
#include <vector>

#include "Component.h"
#include "RenderComponent.h"
#include "Structs.h"
#include "Transform.h"

namespace dae {
    class CollisionComponent;

    class EnemyComponent : public Component
    {
    public:
        enum class State
        {
            left,
            right,
            up,
            down,
            stunned,
            falling
        };
        EnemyComponent(GameObject* owner);
        void Update(float deltaTime) override;

        void SetPeter(GameObject* peterObj) { m_Peter = peterObj; }

        void SetState(State state);// { m_State = state; }
    private:
        void HandleMovement(float deltaTime);
        void HandleCollision(float deltaTime);
        State m_State = State::left;

        float m_Speed{ 80.f },
            m_ClimbSpeed{ 60.f },
    		m_FallSpeed{200.f};

        bool m_OnPlatform{ false },
            m_OnLadder{ false },
            m_Colliding{ false };

        GameObject* m_Peter{},
            * m_CurrentPlatform{};

        Vec2 m_Direction{};
        
    };
}
