#pragma once
#include <vector>

#include "Component.h"
#include "RenderComponent.h"
#include "Structs.h"
#include "Transform.h"

namespace dae {
	class AnimatedRenderComponent;
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
            falling,
            dead
        };
        EnemyComponent(GameObject* owner);
        void Update(float deltaTime) override;

        void SetPeter(GameObject* peterObj);// { m_Peter = peterObj; }

        void SetState(State state);// { m_State = state; }

        void InitAnimation(AnimatedRenderComponent* animComp,std::string textureLoc);
    private:
        void HandleMovement(float deltaTime);
        void HandleCollision(float deltaTime);
        void HandleAnim() const;
        void Initialize();
        State m_State = State::left;

        float m_Speed{ 50.f },
            m_ClimbSpeed{ 30.f },
    		m_FallSpeed{150.f};

        bool m_OnPlatform{ false },
            m_OnLadder{ false },
            m_Horizontal{ false },
            m_Switched{ false };

        Bounds m_Bounds{};

        GameObject* m_Peter{},
            * m_CurrentPlatform{};

        Vec2 m_Direction{};

        AnimatedRenderComponent* m_Anim{};

        //Anim
        int m_RunLeft{},
            m_RunRight{},
            m_Climb{},
            m_ClimbDown{},
            m_Stunned{};
        
    };
}
