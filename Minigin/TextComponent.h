#pragma once
#include "Component.h"
#include <string>

namespace dae
{
	struct Color
	{
		uint8_t red;
		uint8_t green;
		uint8_t blue;
		uint8_t alpha;
	};
	class RenderComponent;
	class Font;
	class Texture2D;
	class TextComponent : public Component
	{
	public:
		TextComponent(GameObject* owner);
		void Update(float deltaTime) override;
		void Render() const;

		void SetText(const std::string& text);
		void SetFont(const std::shared_ptr<Font>& font);
		void SetColor(float r, float g, float b, float a = 1);
		TextComponent();
		virtual ~TextComponent() = default;
		TextComponent(const TextComponent& other) = delete;
		TextComponent(TextComponent&& other) = delete;
		TextComponent& operator=(const TextComponent& other) = delete;
		TextComponent& operator=(TextComponent&& other) = delete;
	private:
		Color m_Color{ 255,255,255,255 };
		bool m_NeedsUpdate;
		RenderComponent* m_RenderComponent{};
		std::string m_Text;
		std::shared_ptr<Font> m_Font;
		std::shared_ptr<Texture2D> m_TextTexture;
	};
}
