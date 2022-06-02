#pragma once
#include "Component.h"
#include <string>
namespace dae
{
	class Texture2D;
	class RenderComponent : public Component
	{
	public:
		RenderComponent(GameObject* owner);
		void Render() const;
		void SetTexture(const std::shared_ptr<Texture2D> texture);
		void SetTexture(const std::string& filename);
	private:
		std::shared_ptr<Texture2D> m_Texture;
	};
}


