#pragma once
#include "Component.h"
#include "GameObject.h"
#include "HealthComponent.h"
#include "PointsComponent.h"

namespace dae
{
	class PeterPepper : public Component
	{
	public:
		PeterPepper(GameObject* owner):Component(owner)
		{
			owner->AddComponent<HealthComponent>();
			owner->AddComponent<PointsComponent>();
		}
	};

}
