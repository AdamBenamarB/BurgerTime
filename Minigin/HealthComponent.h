#pragma once
#include <iostream>

#include "Component.h"
#include "Subject.h"

namespace dae {
    class HealthComponent : public Component, public Subject
    {
    public:
        HealthComponent(GameObject* owner) : Component(owner) {}
        void SetHealth(float healthValue) { m_Health = healthValue; }
        int GetLives() { return m_Lives; }
        void Kill();
    private:
        float m_Health{10};
        int m_Lives = 3;
    };
}
