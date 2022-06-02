#include "MiniginPCH.h"
#include "HealthDisplayComponent.h"

#include "Event.h"
#include "HealthComponent.h"
#include "RenderComponent.h"
#include "ResourceManager.h"
#include "GameObject.h"
#include "TextComponent.h"

dae::HealthDisplayComponent::HealthDisplayComponent(GameObject* owner) : Component(owner)
{
	auto font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 20);
	m_TextComponent = owner->AddComponent<TextComponent>();
	m_TextComponent->SetFont(font);
	m_TextComponent->SetText("Lives: ");
}

void dae::HealthDisplayComponent::SetActorToDisplay(GameObject* obj)
{
	m_HealthActor = obj;
	int livesAmt = obj->GetComponent<HealthComponent>()->GetLives();
	std::string lives = "Lives: " + std::to_string(livesAmt);
	m_TextComponent->SetText(lives);
}


void dae::HealthDisplayComponent::OnNotify(const GameObject* obj, Event event)
{
	switch (event)
	{
	case Event::ON_DEATH:
		if(obj == m_HealthActor)
		{
			int livesAmt = obj->GetComponent<HealthComponent>()->GetLives();
			std::string lives = "Lives: " + std::to_string(livesAmt);
			m_TextComponent->SetText(lives);
		}
		break;
	}
}
