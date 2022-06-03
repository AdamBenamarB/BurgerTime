#include "MiniginPCH.h"
#include "PointsDisplayComponent.h"

#include "Event.h"
#include "HealthComponent.h"
#include "RenderComponent.h"
#include "ResourceManager.h"
#include "GameObject.h"
#include "PointsComponent.h"
#include "TextComponent.h"


dae::PointsDisplayComponent::PointsDisplayComponent(GameObject* owner) : Component(owner)
{
	auto font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 20);
	m_TextComponent = owner->AddComponent<TextComponent>();
	m_TextComponent->SetFont(font);
	m_TextComponent->SetText("Points: ");
}

void dae::PointsDisplayComponent::SetActorToDisplay(GameObject* obj)
{
	m_PointsActor = obj;
	int pointsAmt = obj->GetComponent<PointsComponent>()->GetPoints();
	std::string points = "Points: " + std::to_string(pointsAmt);
	m_TextComponent->SetText(points);
}

void dae::PointsDisplayComponent::OnNotify(const GameObject* obj, Event event)
{
	switch (event)
	{
	case Event::ADDED_POINTS:
		if (obj == m_PointsActor)
		{
			int pointsAmt = obj->GetComponent<PointsComponent>()->GetPoints();
			std::string points = "Points: " + std::to_string(pointsAmt);
			m_TextComponent->SetText(points);
		}
		break;
	}
}