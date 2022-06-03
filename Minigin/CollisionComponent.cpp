#include "MiniginPCH.h"
#include "CollisionComponent.h"

#include "GameObject.h"

void dae::CollisionComponent::SetSize(float width, float height)
{
	m_Width = width;
	m_Height = height;
}

bool dae::CollisionComponent::IsOverlapping(GameObject* other)
{
	auto& pos = m_GameObject->GetTransform()->GetPosition();
	glm::vec3 cornerpos{ pos.x+m_Width,pos.y+m_Height,pos.z };

	auto& otherpos = other->GetTransform()->GetPosition();
	auto othercol = other->GetComponent<CollisionComponent>();
	glm::vec3 othercorner{ otherpos.x+ othercol->m_Width,otherpos.y+ othercol->m_Height,otherpos.z };

	if (pos.x > othercorner.x || otherpos.x > cornerpos.x)
		return false;

	if (cornerpos.y > otherpos.y || othercorner.y > pos.y)
		return false;

	return true;
}

