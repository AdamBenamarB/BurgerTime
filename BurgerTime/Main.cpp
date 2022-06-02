#if _DEBUG
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif
#include "Game.h"

int main(int, char* []) {
	//dae::Minigin engine;
	//engine.Initialize();
	Game burgerTime{};
	burgerTime.Run();
	//LoadGame();
	return 0;
}

void LoadGame()
{
	//dae::ResourceManager::GetInstance().Init("../Data/");

	////BACKGROUND
	//auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");
	//auto go = std::make_shared<dae::GameObject>();
	//go->AddComponent<dae::RenderComponent>();
	////go->GetComponent<dae::RenderComponent>()->SetTexture("background.jpg");
	//go->AddComponent<dae::Transform>();
	//go->GetComponent<dae::Transform>()->SetPosition(0, 0, 0);
	//scene.Add(go);
	//auto font = dae::ResourceManager::GetInstance().LoadTexture("logo.png");

	////FPS
	//go = std::make_shared<GameObject>();
	//auto text = go->AddComponent<TextComponent>();
	//text->SetColor(0, 1, 0);
	//text->SetFont(font);
	//go->GetTransform()->SetPosition(10, 10, 0);
	//go->AddComponent<FPS>();
	//scene.Add(go);

	////go = std::make_shared<GameObject>();
	////go->AddComponent<HealthComponent>();
	////InputManager::GetInstance().AddController(1);
	////auto controllerkey2 = Input::ControllerKey(make_pair(1, XBox360Controller::ControllerButton::ButtonB));//pass controlleridx as first value


	////Peter Pepper
	//go = std::make_shared<GameObject>();
	//go->AddComponent<PeterPepper>();
	//scene.Add(go);
	//InputManager::GetInstance().AddController(0);

	////Decrease Lives
	//auto controllerkey = Input::ControllerKey({ 0,XBox360Controller::ControllerButton::ButtonA,Input::KeyState::OnPressed });
	//auto command = std::make_unique<KillCommand>(go);
	//InputManager::GetInstance().AddCommand(controllerkey, std::move(command));
	////Add points
	//controllerkey = Input::ControllerKey({ 0,XBox360Controller::ControllerButton::ButtonB,Input::KeyState::OnPressed });
	//auto pointcommand = std::make_unique<AddPointsCommand>(go);
	//InputManager::GetInstance().AddCommand(controllerkey, std::move(pointcommand));

	//////Health Display
	//auto healthDisp = std::make_shared<GameObject>();
	//healthDisp->GetTransform()->SetPosition(10, 100, 0);//WHY CANT I ADD A TRANSFORM IN MY CONSTRUCTOR
	//healthDisp->AddComponent<HealthDisplayComponent>()->SetActorToDisplay(go.get());
	//healthDisp->GetComponent<TextComponent>()->SetColor(1, 0, 0);
	//scene.Add(healthDisp);
	//go->GetComponent<HealthComponent>()->AddObserver(healthDisp->GetComponent<HealthDisplayComponent>());

	////Points Display
	//auto pointsDisp = std::make_shared<GameObject>();
	//pointsDisp->GetTransform()->SetPosition(10, 130, 0);
	//auto display = pointsDisp->AddComponent<PointsDisplayComponent>();
	//display->SetActorToDisplay(go.get());
	//pointsDisp->GetComponent<TextComponent>()->SetColor(1, 0, 0);
	//scene.Add(pointsDisp);
	//go->GetComponent<PointsComponent>()->AddObserver(display);

	////PLAYER 2
	////Peter Pepper 2
	//go = std::make_shared<GameObject>();
	//go->AddComponent<PeterPepper>();
	//scene.Add(go);
	//InputManager::GetInstance().AddController(1);

	////Decrease Lives
	//controllerkey = Input::ControllerKey({ 1,XBox360Controller::ControllerButton::ButtonA,Input::KeyState::OnPressed });
	//auto command2 = std::make_unique<KillCommand>(go);
	//InputManager::GetInstance().AddCommand(controllerkey, std::move(command2));

	////Add points
	//controllerkey = Input::ControllerKey({ 1,XBox360Controller::ControllerButton::ButtonB,Input::KeyState::OnPressed });
	//auto pointcommand2 = std::make_unique<AddPointsCommand>(go);
	//InputManager::GetInstance().AddCommand(controllerkey, std::move(pointcommand2));

	//////Health Display
	//healthDisp = std::make_shared<GameObject>();
	//healthDisp->GetTransform()->SetPosition(10, 200, 0);
	//healthDisp->AddComponent<HealthDisplayComponent>()->SetActorToDisplay(go.get());
	//healthDisp->GetComponent<TextComponent>()->SetColor(1, 0, 0);
	//scene.Add(healthDisp);
	//go->GetComponent<HealthComponent>()->AddObserver(healthDisp->GetComponent<HealthDisplayComponent>());

	////Points Display
	//pointsDisp = std::make_shared<GameObject>();
	//pointsDisp->GetTransform()->SetPosition(10, 230, 0);
	//display = pointsDisp->AddComponent<PointsDisplayComponent>();
	//display->SetActorToDisplay(go.get());
	//pointsDisp->GetComponent<TextComponent>()->SetColor(1, 0, 0);
	//scene.Add(pointsDisp);
	//go->GetComponent<PointsComponent>()->AddObserver(display);

	//std::cout << "Button A to decrease lives, Button B to increase score\n";
}
