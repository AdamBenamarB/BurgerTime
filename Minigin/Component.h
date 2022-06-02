#pragma once
namespace dae
{

	class GameObject;
	class Component
	{
	public:
		Component(GameObject* owner);
		virtual ~Component() = default;
		Component(const Component& other) = delete;
		Component(Component&& other) noexcept = delete;
		Component& operator=(const Component& other) = delete;
		Component& operator=(Component&& other) noexcept = delete;
		void SetOwner(GameObject* owner);
		virtual void Update(float deltaTime);
		virtual void FixedUpdate(float timeStep);
	protected:
		GameObject* m_GameObject;
	};
}


