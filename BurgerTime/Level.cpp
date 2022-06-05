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
#include "Wall.h"

dae::Level::Level(Scene& scene)
{
	Initialize(scene);
}


void dae::Level::Initialize(Scene& scene)
{
	dae::PeterPepper peter{ scene,{310,576} };

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
	scene.SetBounds({ Vec2{0,14},Vec2{800,590} });
	dae::MrEgg egg{ scene,{64,64},peter.GetGameObject() };

	dae::Platform{ scene,{64,0} };
	dae::Platform{ scene,{128,0} };
	dae::Platform{ scene,{192,0} };
	dae::Platform{ scene,{256,0} };
	dae::Platform{ scene,{320,0} };
	dae::Platform{ scene,{384,0} };
	dae::Platform{ scene,{448,0} };
	dae::Platform{ scene,{512,0} };
	dae::Platform{ scene,{576,0} };

	dae::Ladder{ scene,{64,64} };
	dae::Ladder{ scene,{64,128} };

	dae::Ladder{ scene,{192,64} };
	dae::Ladder{ scene,{192,128} };
	dae::Ladder{ scene,{192,192} };
	dae::Ladder{ scene,{192,256} };
	dae::Ladder{ scene,{192,320} };
	dae::Ladder{ scene,{192,384} };
	dae::Ladder{ scene,{192,448} };
	dae::Ladder{ scene,{192,512} };
	dae::Ladder{ scene,{192,576} };

	dae::Ladder{ scene,{320,64} };
	dae::Ladder{ scene,{320,128} };
	dae::Ladder{ scene,{320,192} };
	dae::Ladder{ scene,{320,256} };
	dae::Ladder{ scene,{320,320} };
	dae::Ladder{ scene,{320,384} };
	dae::Ladder{ scene,{320,448} };
	dae::Ladder{ scene,{320,512} };
	dae::Ladder{ scene,{320,576} };

	dae::Ladder{ scene,{448,64} };
	dae::Ladder{ scene,{448,128} };
	dae::Ladder{ scene,{448,192} };
	dae::Ladder{ scene,{448,256} };
	dae::Ladder{ scene,{448,320} };
	dae::Ladder{ scene,{448,384} };
	dae::Ladder{ scene,{448,448} };
	dae::Ladder{ scene,{448,512} };
	dae::Ladder{ scene,{448,576} };

	dae::Ladder{ scene,{576,64} };
	dae::Ladder{ scene,{576,128} };
	dae::Ladder{ scene,{576,192} };
	dae::Ladder{ scene,{576,256} };
	dae::Ladder{ scene,{576,448} };
	dae::Ladder{ scene,{576,512} };
	dae::Ladder{ scene,{576,576} };

	dae::Ladder{ scene,{256,64} };
	dae::Ladder{ scene,{256,128} };
	dae::Ladder{ scene,{256,192} };

	dae::Ladder{ scene,{128,192} };
	dae::Ladder{ scene,{128,256} };
	dae::Ladder{ scene,{128,320} };
	dae::Ladder{ scene,{128,384} };
	dae::Ladder{ scene,{128,448} };

	dae::Ladder{ scene,{64,320} };
	dae::Ladder{ scene,{64,384} };
	dae::Ladder{ scene,{64,448} };
	dae::Ladder{ scene,{64,512} };
	dae::Ladder{ scene,{64,576} };

	dae::Ladder{ scene,{384,192} };
	dae::Ladder{ scene,{384,256} };
	dae::Ladder{ scene,{384,320} };
	
	dae::Ladder{ scene,{512,320} };
	dae::Ladder{ scene,{512,384} };
	dae::Ladder{ scene,{512,448} };
	dae::Ladder{ scene,{512,512} };
	dae::Ladder{ scene,{512,576} };

	dae::Platform{ scene,{64,128} };
	dae::Platform{ scene,{128,128} };
	dae::Platform{ scene,{192,128} };
	dae::Platform{ scene,{320,128} };
	dae::Platform{ scene,{384,128} };
	dae::Platform{ scene,{448,128} };
	dae::Platform{ scene,{512,128} };
	dae::Platform{ scene,{576,128} };


	dae::Platform{ scene,{448,256} };
	dae::Platform{ scene,{512,256} };
	dae::Platform{ scene,{576,256} };

	dae::Platform{ scene,{448,384} };
	dae::Platform{ scene,{512,384} };
	dae::Platform{ scene,{576,384} };

	dae::Platform{ scene,{64,256} };
	dae::Platform{ scene,{128,256} };
	dae::Platform{ scene,{192,256} };

	dae::Platform{ scene,{64,448} };
	dae::Platform{ scene,{128,448} };
	dae::Platform{ scene,{192,448} };

	dae::Platform{ scene,{64,576} };
	dae::Platform{ scene,{128,576} };
	dae::Platform{ scene,{192,576} };
	dae::Platform{ scene,{256,576} };
	dae::Platform{ scene,{320,576} };
	dae::Platform{ scene,{384,576} };
	dae::Platform{ scene,{448,576} };
	dae::Platform{ scene,{512,576} };
	dae::Platform{ scene,{576,576} };

	dae::Platform{ scene,{192,192} };
	dae::Platform{ scene,{256,192} };
	dae::Platform{ scene,{320,192} };

	dae::Platform{ scene,{192,320} };
	dae::Platform{ scene,{256,320} };
	dae::Platform{ scene,{320,320} };
	dae::Platform{ scene,{384,320} };
	dae::Platform{ scene,{448,320} };

	dae::Platform{ scene,{192,448} };
	dae::Platform{ scene,{256,448} };
	dae::Platform{ scene,{320,448} };
	dae::Platform{ scene,{384,448} };
	dae::Platform{ scene,{448,448} };

	//dae::Wall wall{ scene,Vec2{128,0} };
	/*dae::Platform plat{ scene,Vec2{0,0} };
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
	dae::Wall wall{ scene,Vec2{-64,128} };
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
	dae::Plate plate{ scene, Vec2{128,384} };*/
}
