#pragma once
#include "Component.h"
#include "RenderComponent.h"
#include "Structs.h"
#include "Transform.h"

namespace dae {
	class AnimatedRenderComponent;

	class PeterPepperComponent : public Component
    {
    public:
        enum class State
        {
	        idle,
            left,
            right,
            up,
            down
        };
        PeterPepperComponent(GameObject* owner);
        ~PeterPepperComponent();
        void Update(float deltaTime) override;

        void SetState(State state);

        void InitAnimation(AnimatedRenderComponent* comp);

        void Hit();

        void AddPoints(GameObject* go);
        void AddPoints(int amt);

        State GetState() const { return m_State; }
    private:
        void HandleMovement(float deltaTime);
        void HandleCollision(float deltaTime);
        void HandleAnim();
        State m_State = State::idle;
        float m_Speed = 70.f;
        float m_LadderSpeed = 80.f;
        
        //ANIM
        AnimatedRenderComponent* m_Anim{};


        int m_Idle{},
            m_RunLeft{},
            m_RunRight{},
            m_Climb{},
            m_ClimbDown{};

        bool m_OnPlatform{ false },
            m_OnLadder{ false },
            m_Hit{ false };


        float m_ElapsedInv{}
        , m_m_InvTime{2.f};

        
    };
}
