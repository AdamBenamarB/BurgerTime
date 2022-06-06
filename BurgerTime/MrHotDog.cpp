#include "MrHotDog.h"

#include "AnimatedRenderComponent.h"
#include "CollisionComponent.h"
#include "EnemyComponent.h"
#include "RenderComponent.h"
#include "GameObject.h"
#include "Input.h"
#include "InputManager.h"
#include "Scene.h"
#include "ServiceLocator.h"

dae::MrHotDog::MrHotDog(dae::Scene& scene, Vec2 loc, GameObject* peter)
{
	Initialize(scene, loc, peter);
}

void dae::MrHotDog::Initialize(dae::Scene& scene, Vec2 loc, GameObject* peter)
{
	auto go = std::make_shared<dae::GameObject>();
	auto enemycomp = go->AddComponent<EnemyComponent>();
	enemycomp->SetPeter(peter);

	auto rc = go->AddComponent<dae::AnimatedRenderComponent>();
	rc->SetDimensions(m_Height, m_Width);
	rc->SetSpriteDimensions(16, 16);
	enemycomp->InitAnimation(rc, "\\Sprites\\Enemies\\dog.png");

	auto col = go->AddComponent<CollisionComponent>();
	col->SetSize(20, 32.5f);
	col->SetOffset(6, 0);

	go->SetTag("MRHOTDOG");

	go->GetTransform()->SetPosition(loc.x + 24, loc.y + 28, 0);
	scene.Add(go, 0);
}
