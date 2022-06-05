#pragma once
#include "Component.h"
#include "Structs.h"

namespace dae {
    class PlatformComponent : public Component
    {
    public:
        PlatformComponent(GameObject* owner);
        Vec2 GetFloorPos() const;
        bool IsUnder(Rect other) const;
    };
}
