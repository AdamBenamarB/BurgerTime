#include "PlatformComponent.h"

#include "GameObject.h"

dae::PlatformComponent::PlatformComponent(GameObject* owner)
	:Component{owner}
{
	
}

Vec2 dae::PlatformComponent::GetFloorPos() const
{
	auto pos = m_GameObject->GetTransform()->GetPosition();
	Vec2 floorPos = { pos.x,pos.y - 60 };
	return floorPos;
}
