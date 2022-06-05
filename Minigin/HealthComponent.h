#pragma once
#include <iostream>

#include "Component.h"
#include "Subject.h"

namespace dae {
    class HealthComponent : public Component, public Subject
    {
    public:
        HealthComponent(GameObject* owner) : Component(owner) {}
        int GetLives() { return m_Lives; }
        void Hit(int amt = 1);
    private:
        int m_Lives = 3;
    };
}
