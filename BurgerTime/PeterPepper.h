#pragma once


namespace dae
{
	class Scene;
	class GameObject;
	class PeterPepper
	{
	public:
		PeterPepper(dae::Scene& scene);
		~PeterPepper() = default;
		PeterPepper(const PeterPepper& other) = delete;
		PeterPepper(PeterPepper&& other) noexcept = delete;
		PeterPepper& operator=(const PeterPepper& other) = delete;
		PeterPepper& operator=(PeterPepper&& other) noexcept = delete;

		GameObject* GetGameObject();
	private:
		void Initialize(dae::Scene& scene);

		float m_Height{ 62 },
			m_Width{ 64 };
		GameObject* m_Peter{};
	};
}
