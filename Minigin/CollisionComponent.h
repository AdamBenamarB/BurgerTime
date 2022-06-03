#pragma once
#include "Component.h"
namespace dae {
    class CollisionComponent :
        public Component
    {
    public:
        CollisionComponent(GameObject* owner):Component(owner){}
        void SetSize(float width, float height);

        bool IsOverlapping(GameObject* other);
    private:
        float m_Width{},
            m_Height{};
    };

}