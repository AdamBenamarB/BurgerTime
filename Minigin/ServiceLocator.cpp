#include "MiniginPCH.h"
#include "ServiceLocator.h"

dae::SoundSystem* dae::ServiceLocator::m_SSInstance{};
dae::NullSoundSystem dae::ServiceLocator::m_DefaultSS{};

dae::ServiceLocator::~ServiceLocator()
{
	delete m_SSInstance;
}
