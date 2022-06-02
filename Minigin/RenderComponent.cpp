#include "MiniginPCH.h"
#include "RenderComponent.h"
#include "Texture2D.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include "GameObject.h"
#include "Transform.h"

dae::RenderComponent::RenderComponent(GameObject* owner)
	:Component{owner}
{}
void dae::RenderComponent::Render() const
{
	if (m_Texture != nullptr)
	{
		auto pos = m_GameObject->GetComponent<Transform>()->GetPosition();

		Renderer::GetInstance().RenderTexture(*m_Texture, pos.x, pos.y);
	}
}

void dae::RenderComponent::SetTexture(std::shared_ptr<Texture2D> texture)
{
	m_Texture = texture;
}

void dae::RenderComponent::SetTexture(const std::string& filename)
{
	m_Texture = ResourceManager::GetInstance().LoadTexture(filename);
}