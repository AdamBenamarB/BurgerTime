#pragma once
#include "Component.h"
#include "Observer.h"

namespace dae
{
	class TextComponent;
	class HealthDisplayComponent : public Component, public Observer
	{
	public:
		HealthDisplayComponent(GameObject* owner);
		void SetActorToDisplay(GameObject* obj);
	protected:
		void OnNotify(const GameObject* obj, Event event) override;
	private:
		TextComponent* m_TextComponent{};
		GameObject* m_HealthActor{};
	};
}
