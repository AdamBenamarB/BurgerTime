#pragma once
#include "Component.h"
#include "Subject.h"

namespace dae
{
    class PointsComponent : public Component, public Subject
    {
    public:
        PointsComponent(GameObject* owner) : Component(owner){}
        void AddPoints(int pointsAmt) { m_Points += pointsAmt; Notify(m_GameObject, Event::ADDED_POINTS); }
        int GetPoints() { return m_Points; }
    private:
        int m_Points{};
    };
}
