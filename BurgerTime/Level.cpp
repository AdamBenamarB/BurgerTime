#include "Level.h"

#include "BottomBun.h"
#include "Bun.h"
#include "Cheese.h"
#include "EnemyComponent.h"
#include "Ladder.h"
#include "Lettuce.h"
#include "Patty.h"
#include "PeterPepper.h"
#include "Plate.h"
#include "Platform.h"
#include "RenderComponent.h"
#include "Tomato.h"
#include "GameObject.h"
#include "CollisionComponent.h"
#include "MrEgg.h"
#include "Scene.h"

dae::Level::Level(Scene& scene)
{
	Initialize(scene);
}


void dae::Level::Initialize(Scene& scene)
{
	dae::PeterPepper peter{ scene,{0,0} };

	/*auto go = std::make_shared<dae::GameObject>();
	auto rc = go->AddComponent<dae::RenderComponent>();
	rc->SetTexture("\\Sprites\\PeterPepper\\peter.png");
	rc->SetDimensions(48, 48);
	auto enemy = go->AddComponent<dae::EnemyComponent>();
	enemy->SetPeter(peter.GetGameObject());
	auto col = go->AddComponent<dae::CollisionComponent>();
	col->SetSize(48, 48);

	go->GetTransform()->SetPosition(64, 32, 0);
	scene.Add(go, 1);*/

	dae::MrEgg egg{ scene,{64,64},peter.GetGameObject() };

	//dae::Wall wall{ scene,Vec2{128,0} };
	dae::Platform plat{ scene,Vec2{0,0} };
	dae::Platform plat2{ scene,Vec2{64,0} };
	dae::Platform plat3{ scene,Vec2{0,128} };
	dae::Platform plat4{ scene,Vec2{64,128} };
	dae::Platform plat41{ scene,Vec2{128,64} };
	dae::Platform plat5{ scene,Vec2{128,196} };
	dae::Platform plat6{ scene,Vec2{64,64} };
	dae::Ladder ladder2{ scene,Vec2{64,64} };
	dae::Ladder ladder{ scene,Vec2{64,0} };
	dae::Ladder ladder3{ scene,Vec2{64,128} };
	dae::Ladder ladder4{ scene,Vec2{64,192} };
	dae::Ladder ladder5{ scene,Vec2{64,256} };
	dae::Ladder ladder6{ scene,Vec2{64,320} };
	//dae::Wall wall{ scene,Vec2{64,128} };
	dae::Platform plat7{ scene,Vec2{128,0} };
	dae::Platform plat8{ scene,Vec2{128,64} };
	dae::Platform plat9{ scene,Vec2{128,128} };
	dae::Platform plat10{ scene,Vec2{128,196} };
	dae::Platform plat11{ scene,Vec2{128,256} };
	dae::Platform plat12{ scene,Vec2{128,320} };

	dae::Bun bun{ scene, Vec2{128,0} };
	dae::Cheese cheese{ scene, Vec2{128,64} };
	dae::Patty patty{ scene,Vec2{128,128} };
	dae::Tomato tomato{ scene, Vec2{128,192} };
	dae::Lettuce lettuce{ scene, Vec2{128,256} };
	dae::BottomBun botbun{ scene, Vec2{128,320} };
	dae::Plate plate{ scene, Vec2{128,384} };
}
