#pragma once
#include "Component.h"
#include <string>
namespace dae
{
	class TextComponent;
	class FPS : public Component
	{
	public:
		FPS(GameObject* owner);
		void Update(float deltaTime) override;
		std::string GetFPS() const;
	private:
		int m_FrameCount{};
		float m_ElapsedSeconds{};
		int m_FPS{};
		TextComponent* m_TextComponent;
	};
}

