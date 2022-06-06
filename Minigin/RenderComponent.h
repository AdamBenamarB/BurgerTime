#pragma once
#include "Component.h"
#include <string>
#include <memory>
namespace dae
{
	class Texture2D;
	class RenderComponent : public Component
	{
	public:
		RenderComponent(GameObject* owner);
		virtual void Render() const;
		void SetTexture(const std::shared_ptr<Texture2D> texture);
		void SetTexture(const std::string& filename);
		void SetDimensions(float width, float height);
		void SetOffsetX(float x);
		void SetOffsetY(float y);

		void SetEnabled(bool enabled) { m_Enabled = enabled; }
	protected:
		std::shared_ptr<Texture2D> m_Texture;
		float m_Width{},
			m_Height{};
	private:
		float m_OffsetX{},
			m_OffsetY{};
		bool m_UseDimensions{false};
		bool m_Enabled{ true };
	};
}


