#include "MiniginPCH.h"
#include "AnimatedRenderComponent.h"

#include "GameObject.h"
#include "Renderer.h"

dae::AnimatedRenderComponent::AnimatedRenderComponent(GameObject* owner)
	:RenderComponent(owner)
{}

void dae::AnimatedRenderComponent::Render() const
{
	if (m_Texture != nullptr)
	{
		auto& pos = m_GameObject->GetTransform()->GetPosition();
		Rect dst{ pos.x,pos.y,m_Width,m_Height };

		Renderer::GetInstance().RenderTexture(*m_Texture, dst,m_SrcRct);
	}
	

}

void dae::AnimatedRenderComponent::Update(float deltaTime)
{
	m_ElapsedSec += deltaTime;
	if(m_ElapsedSec>1.f/m_FPS)
	{
		m_ElapsedSec = 0;
		++m_ColNr;

		if (m_ColNr >= m_Clips[m_AnimIdx].colAmt)
			if (m_Clips[m_AnimIdx].looping)
				m_ColNr = 0;
			else
				m_ColNr = m_Clips[m_AnimIdx].colAmt - 1;
	}
	float x = m_SpriteWidth * m_ColNr;
	float y = m_SpriteHeight * m_AnimIdx;
	m_SrcRct = Rect{ x,y,m_SpriteWidth,m_SpriteHeight };
}

int dae::AnimatedRenderComponent::AddClip(int colAmt, bool looping)
{
	m_Clips.push_back({ colAmt,looping });
	return (int)m_Clips.size() - 1;
}


void dae::AnimatedRenderComponent::SetSpriteDimensions(float width, float height)
{
	m_SpriteWidth = width;
	m_SpriteHeight = height;
}

void dae::AnimatedRenderComponent::SetClip(int idx)
{
	if(idx!=m_AnimIdx)
	{ m_AnimIdx = idx;
		m_ColNr = 0;
	}
}
