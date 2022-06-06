#pragma once
#include "RenderComponent.h"

namespace dae {
	class GameObject;

	class PepperComponent : public Component
	{
	public:
		PepperComponent(GameObject* owner);
		void Update(float deltaTime)override;
		void Activate();
	private:
		void Initialize();

		GameObject* m_Peter{};
		dae::RenderComponent* m_RenderComp{};
		bool m_Active{ false };

		float m_TimeToShow{ .5f },
			m_ElapsedTime{};

		int m_Amt{5};

		int m_Sound{};
	};
}