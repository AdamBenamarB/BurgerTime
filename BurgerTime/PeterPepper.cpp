#include "PeterPepper.h"

#include "AnimatedRenderComponent.h"
#include "CollisionComponent.h"
#include "RenderComponent.h"
#include "GameObject.h"
#include "Input.h"
#include "InputManager.h"
#include "Scene.h"
#include "ServiceLocator.h"

dae::PeterPepper::PeterPepper(dae::Scene& scene,Vec2 loc)
{
	Initialize(scene, loc);
}

void dae::PeterPepper::Initialize(dae::Scene& scene, Vec2 loc)
{
	auto go = std::make_shared<dae::GameObject>();
	m_Peter = go.get();
	auto ppcomp = go->AddComponent<PeterPepperComponent>();
	/*auto rc = go->AddComponent<dae::RenderComponent>();
	rc->SetTexture("\\Sprites\\PeterPepper\\peter.png");
	rc->SetDimensions(m_Height, m_Width);*/
	go->AddComponent<PointsComponent>();
	go->AddComponent<HealthComponent>();

	auto rc = go->AddComponent<dae::AnimatedRenderComponent>();
	rc->SetTexture("\\Sprites\\PeterPepper\\sprites.png");
	rc->SetDimensions(m_Height, m_Width);
	rc->SetSpriteDimensions(16, 16);
	ppcomp->InitAnimation(rc);

	auto col = go->AddComponent<CollisionComponent>();
	col->SetSize(32,32);
	col->SetOffset(0, 0);
	//col->SetOffset(16, 16);
	go->SetTag("PETER");

	go->GetTransform()->SetPosition(loc.x+24, loc.y+24, 0);
	scene.Add(go,0);

	InputManager::GetInstance().AddController(1);
	auto controllerkey = Input::ControllerKey({0, dae::XBox360Controller::ControllerButton::DpadLeft,Input::KeyState::OnPressed});
	auto command = std::make_unique<dae::MoveLeft>(go);
	dae::InputManager::GetInstance().AddCommand(controllerkey,std::move(command));

	controllerkey = Input::ControllerKey({ 0, dae::XBox360Controller::ControllerButton::DpadLeft,Input::KeyState::OnReleased });
	auto command2 = std::make_unique<dae::Idle>(go);
	dae::InputManager::GetInstance().AddCommand(controllerkey, std::move(command2));

	controllerkey = Input::ControllerKey({ 0, dae::XBox360Controller::ControllerButton::DpadRight,Input::KeyState::OnPressed });
	auto command3 = std::make_unique<dae::MoveRight>(go);
	dae::InputManager::GetInstance().AddCommand(controllerkey, std::move(command3));

	controllerkey = Input::ControllerKey({ 0, dae::XBox360Controller::ControllerButton::DpadRight,Input::KeyState::OnReleased });
	auto command21 = std::make_unique<dae::Idle>(go);
	dae::InputManager::GetInstance().AddCommand(controllerkey, std::move(command21));

	controllerkey = Input::ControllerKey({ 0, dae::XBox360Controller::ControllerButton::DpadUp,Input::KeyState::OnPressed });
	auto command4 = std::make_unique<dae::MoveUp>(go);
	dae::InputManager::GetInstance().AddCommand(controllerkey, std::move(command4));

	controllerkey = Input::ControllerKey({ 0, dae::XBox360Controller::ControllerButton::DpadUp,Input::KeyState::OnReleased });
	auto command22 = std::make_unique<dae::Idle>(go);
	dae::InputManager::GetInstance().AddCommand(controllerkey, std::move(command22));

	controllerkey = Input::ControllerKey({ 0, dae::XBox360Controller::ControllerButton::DpadDown,Input::KeyState::OnPressed });
	auto command5 = std::make_unique<dae::MoveDown>(go);
	dae::InputManager::GetInstance().AddCommand(controllerkey, std::move(command5));

	controllerkey = Input::ControllerKey({ 0, dae::XBox360Controller::ControllerButton::DpadDown,Input::KeyState::OnReleased });
	auto command23 = std::make_unique<dae::Idle>(go);
	dae::InputManager::GetInstance().AddCommand(controllerkey, std::move(command23));

}

dae::GameObject* dae::PeterPepper::GetGameObject()
{
	return m_Peter;
}

