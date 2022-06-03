#pragma once
#include "Component.h"
#include "Transform.h"

namespace dae {
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
        void Update(float deltaTime) override;

        void SetState(State state) { m_State = state; }
    private:
        void HandleMovement(float deltaTime);
        void HandleCollision(float deltaTime);
        State m_State = State::idle;
        float m_Speed = 50.f;
    };
}
