#include "Game.h"

#include "CollisionComponent.h"
#include "FPS.h"
#include "Minigin.h"
#include "GameObject.h"
#include "HealthDisplayComponent.h"
#include "InputManager.h"
#include "PeterPepper.h"
#include "PointsDisplayComponent.h"
#include "ResourceManager.h"
#include "Scene.h"
#include "SceneManager.h"
#include "TextComponent.h"
#include "RenderComponent.h"
#include "ServiceLocator.h"

void Game::LoadGame() const
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");
	dae::PeterPepper peter{ scene };

	/*auto go = std::make_shared<dae::GameObject>();
	auto rc = go->AddComponent<dae::RenderComponent>();
	rc->SetTexture("\\Sprites\\PeterPepper\\peter.png");
	rc->SetDimensions(64, 64);

	auto col = go->AddComponent<dae::CollisionComponent>();
	col->SetSize(64, 64);

	scene.Add(go);*/

	//dae::ServiceLocator::RegisterSoundSystem(new dae::SoundSystem());
	//dae::ServiceLocator::GetSoundSystem().Play(sound, 64);
	//sound->Play(124);
	//auto sound = dae::Sound("C:\\School\\Prog4\\BurgerTime\\Data\\test2.wav");
	//sound.Play(100);
	//dae::ServiceLocator::RegisterSoundSystem(std::shared_ptr<dae::SoundSystem>().get());
	//int id = dae::ServiceLocator::GetSoundSystem().AddSound("C:\\School\\Prog4\\BurgerTime\\Data\\test2.wav");
	//dae::ServiceLocator::GetSoundSystem().Play(id, 100);
	////BACKGROUND
	//auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");
	//auto go = std::make_shared<dae::GameObject>();
	//go->AddComponent<dae::RenderComponent>();
	//go->GetComponent<dae::RenderComponent>()->SetTexture("background.jpg");
	//go->AddComponent<dae::Transform>();
	//go->GetComponent<dae::Transform>()->SetPosition(0, 0, 0);
	//scene.Add(go);

	////FPS
	//go = std::make_shared<dae::GameObject>();
	//auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	//auto text = go->AddComponent<dae::TextComponent>();
	//text->SetColor(0, 1, 0);
	//text->SetFont(font);
	//go->GetTransform()->SetPosition(10, 10, 0);
	//go->AddComponent<dae::FPS>();
	//scene.Add(go);

	////go = std::make_shared<GameObject>();
	////go->AddComponent<HealthComponent>();
	////InputManager::GetInstance().AddController(1);
	////auto controllerkey2 = Input::ControllerKey(make_pair(1, XBox360Controller::ControllerButton::ButtonB));//pass controlleridx as first value


	////Peter Pepper
	//go = std::make_shared<dae::GameObject>();
	//go->AddComponent<dae::PeterPepper>();
	//scene.Add(go);
	//dae::InputManager::GetInstance().AddController(0);

	////Decrease Lives
	//auto controllerkey = Input::ControllerKey({0, dae::XBox360Controller::ControllerButton::ButtonA,Input::KeyState::OnPressed});
	//auto command = std::make_unique<dae::KillCommand>(go);
	//dae::InputManager::GetInstance().AddCommand(controllerkey,std::move(command));
	////Add points
	//controllerkey = Input::ControllerKey({ 0, dae::XBox360Controller::ControllerButton::ButtonB,Input::KeyState::Held });
	//auto pointcommand = std::make_unique<dae::AddPointsCommand>(go);
	//dae::InputManager::GetInstance().AddCommand(controllerkey, std::move(pointcommand));

	//////Health Display
	//auto healthDisp = std::make_shared<dae::GameObject>();
	//healthDisp->GetTransform()->SetPosition(10,100,0);//WHY CANT I ADD A TRANSFORM IN MY CONSTRUCTOR
	//healthDisp->AddComponent<dae::HealthDisplayComponent>()->SetActorToDisplay(go.get());
	//healthDisp->GetComponent<dae::TextComponent>()->SetColor(1, 0, 0);
	//scene.Add(healthDisp);
	//go->GetComponent<dae::HealthComponent>()->AddObserver(healthDisp->GetComponent<dae::HealthDisplayComponent>());

	////Points Display
	//auto pointsDisp = std::make_shared<dae::GameObject>();
	//pointsDisp->GetTransform()->SetPosition(10, 130, 0);
	//auto display = pointsDisp->AddComponent<dae::PointsDisplayComponent>();
	//display->SetActorToDisplay(go.get());
	//pointsDisp->GetComponent<dae::TextComponent>()->SetColor(1, 0, 0);
	//scene.Add(pointsDisp);
	//go->GetComponent<dae::PointsComponent>()->AddObserver(display);
	//
	////PLAYER 2
	////Peter Pepper 2
	//go = std::make_shared<dae::GameObject>();
	//go->AddComponent<dae::PeterPepper>();
	//scene.Add(go);
	//dae::InputManager::GetInstance().AddController(1);

	////Decrease Lives
	//controllerkey = Input::ControllerKey({ 1, dae::XBox360Controller::ControllerButton::ButtonA,Input::KeyState::OnPressed });
	//auto command2 = std::make_unique<dae::KillCommand>(go);
	//dae::InputManager::GetInstance().AddCommand(controllerkey, std::move(command2));

	////Add points
	//controllerkey = Input::ControllerKey({ 1, dae::XBox360Controller::ControllerButton::ButtonB,Input::KeyState::OnPressed });
	//auto pointcommand2 = std::make_unique<dae::AddPointsCommand>(go);
	//dae::InputManager::GetInstance().AddCommand(controllerkey, std::move(pointcommand2));

	//////Health Display
	//healthDisp = std::make_shared<dae::GameObject>();
	//healthDisp->GetTransform()->SetPosition(10, 200, 0);
	//healthDisp->AddComponent<dae::HealthDisplayComponent>()->SetActorToDisplay(go.get());
	//healthDisp->GetComponent<dae::TextComponent>()->SetColor(1, 0, 0);
	//scene.Add(healthDisp);
	//go->GetComponent<dae::HealthComponent>()->AddObserver(healthDisp->GetComponent<dae::HealthDisplayComponent>());

	////Points Display
	//pointsDisp = std::make_shared<dae::GameObject>();
	//pointsDisp->GetTransform()->SetPosition(10, 230, 0);
	//display = pointsDisp->AddComponent<dae::PointsDisplayComponent>();
	//display->SetActorToDisplay(go.get());
	//pointsDisp->GetComponent<dae::TextComponent>()->SetColor(1, 0, 0);
	//scene.Add(pointsDisp);
	//go->GetComponent<dae::PointsComponent>()->AddObserver(display);

	//std::cout << "Button A to decrease lives, Button B to increase score\n";
}