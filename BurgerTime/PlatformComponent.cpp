#include "PlatformComponent.h"

#include "CollisionComponent.h"
#include "GameObject.h"

dae::PlatformComponent::PlatformComponent(GameObject* owner)
	:Component{owner}
{
	
}

Vec2 dae::PlatformComponent::GetFloorPos() const
{
	auto pos = m_GameObject->GetTransform()->GetPosition();
	Vec2 floorPos = { pos.x,pos.y -62 };
	return floorPos;
}

bool dae::PlatformComponent::IsUnder(Rect other) const
{
	return m_GameObject->GetComponent<CollisionComponent>()->IsUnder(other);
}

bool dae::PlatformComponent::IsToSide(Rect other) const
{
	return m_GameObject->GetComponent<CollisionComponent>()->IsToSide(other);
}
