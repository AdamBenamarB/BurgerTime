#pragma once
#include "Component.h"
namespace dae {
    class CollisionComponent :
        public Component
    {
    public:
        CollisionComponent(GameObject* owner):Component(owner){}
        void SetSize(float width, float height);
        void SetOffset(float x, float y);

        bool IsOverlapping(GameObject* other);
        bool IsUnder(GameObject* other);
    private:
        float m_Width{},
            m_Height{};
        float m_OffsetX{},
            m_OffsetY{};
    };

}