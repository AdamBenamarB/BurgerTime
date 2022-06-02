#pragma once
#include "Component.h"
#include "Observer.h"

namespace dae
{
	class TextComponent;

	class PointsDisplayComponent : public Component, public Observer
    {
    public:
        PointsDisplayComponent(GameObject* owner);
        void SetActorToDisplay(GameObject* obj);
    protected:
        void OnNotify(const GameObject* obj, Event event) override;
    private:
        TextComponent* m_TextComponent{};
        GameObject* m_PointsActor{};        
    };
}
