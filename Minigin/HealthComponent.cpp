#include "MiniginPCH.h"
#include "HealthComponent.h"

void dae::HealthComponent::Hit(int amt)
{
	m_Lives -= amt;
	if (m_Lives <= 0)
	{
		m_Lives = 0;
		Notify(m_GameObject, Event::ON_DEATH);
	}
	else
		Notify(m_GameObject, Event::ON_HIT);
}
