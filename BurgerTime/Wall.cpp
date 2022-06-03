#include "Wall.h"

#include "CollisionComponent.h"
#include "RenderComponent.h"
#include "GameObject.h"
#include "Input.h"
#include "Scene.h"

dae::Wall::Wall(dae::Scene& scene,Vec2 loc)
{
	Initialize(scene, loc);
}

void dae::Wall::Initialize(dae::Scene& scene, Vec2 loc)
{
	auto go = std::make_shared<dae::GameObject>();

	auto col = go->AddComponent<CollisionComponent>();
	col->SetSize(64, 64);
	go->SetTag("WALL");
	go->GetTransform()->SetPosition(loc.x, loc.y, 0);
	scene.Add(go);


}
