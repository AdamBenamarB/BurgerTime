#include "MiniginPCH.h"
#include "HealthComponent.h"

void dae::HealthComponent::Kill()
{
	m_Health = 0;
	if(m_Lives>0)
	{
		m_Lives -= 1;
	}
	Notify(m_GameObject, Event::ON_DEATH);
}