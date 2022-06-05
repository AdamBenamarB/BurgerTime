#pragma once
#include <iostream>

#include "GameObject.h"
#include "HealthComponent.h"
#include "PointsComponent.h"
#include "../BurgerTime/PeterPepperComponent.h"

namespace dae
{
	class PeterPepperComponent;
	class HealthComponent;

	class Command
	{
	public:
		explicit Command(std::shared_ptr<GameObject> obj) :object{ obj } {}
		virtual ~Command() = default;
		virtual void Execute() = 0;
	protected:
		std::shared_ptr<GameObject>  GetGameObject() { return object; }
	private:
		std::shared_ptr<GameObject>  object;
	};
	
	class AddPointsCommand : public Command
	{
	public:
		AddPointsCommand(std::shared_ptr<GameObject> obj) :Command(obj) {}
		void Execute() override{ GetGameObject()->GetComponent<PointsComponent>()->AddPoints(100); }
	};

	class MoveLeft:public Command
	{
	public:
		MoveLeft(std::shared_ptr<GameObject> obj): Command(obj){}
		void Execute() override
		{
			GetGameObject()->GetComponent<PeterPepperComponent>()->SetState(PeterPepperComponent::State::left);
		}
	};

	class MoveRight :public Command
	{
	public:
		MoveRight(std::shared_ptr<GameObject> obj) : Command(obj) {}
		void Execute() override
		{
			GetGameObject()->GetComponent<PeterPepperComponent>()->SetState(PeterPepperComponent::State::right);
		}
	};

	class MoveUp :public Command
	{
	public:
		MoveUp(std::shared_ptr<GameObject> obj) : Command(obj) {}
		void Execute() override
		{
			GetGameObject()->GetComponent<PeterPepperComponent>()->SetState(PeterPepperComponent::State::up);
		}
	};

	class MoveDown :public Command
	{
	public:
		MoveDown(std::shared_ptr<GameObject> obj) : Command(obj) {}
		void Execute() override
		{
			GetGameObject()->GetComponent<PeterPepperComponent>()->SetState(PeterPepperComponent::State::down);
		}
	};

	class Idle :public Command
	{
	public:
		Idle(std::shared_ptr<GameObject> obj) : Command(obj) {}
		void Execute() override
		{
			GetGameObject()->GetComponent<PeterPepperComponent>()->SetState(PeterPepperComponent::State::idle);
		}
	};
}
//
//class FireCommand : public Command
//{
//public:
//	FireCommand(dae::GameObject* go) :Command(go){}
//	void Execute() override { std::cout << "fire\n"; }
//};

//class JumpCommand : public Command
//{
//public:
//	void Execute() override { std::cout << "Jump\n"; }
//};
//
//class DuckCommand : public Command
//{
//public:
//	void Execute() override { std::cout << "Duck\n"; }
//};
//
//class FartCommand : public Command
//{
//public:
//	void Execute() override { std::cout << "Fart\n"; }
//};
