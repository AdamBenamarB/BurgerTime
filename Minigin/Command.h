#pragma once
#include <iostream>

#include "GameObject.h"
#include "HealthComponent.h"
#include "PointsComponent.h"

namespace dae
{
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

	class KillCommand : public Command
	{
	public:
		KillCommand(std::shared_ptr<GameObject> obj) :Command(obj) {}
		void Execute() override { GetGameObject()->GetComponent<HealthComponent>()->Kill(); }
	};

	class AddPointsCommand : public Command
	{
	public:
		AddPointsCommand(std::shared_ptr<GameObject> obj) :Command(obj) {}
		void Execute() override{ GetGameObject()->GetComponent<PointsComponent>()->AddPoints(100); }
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
