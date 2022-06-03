#pragma once
#include "SoundSystem.h"

namespace dae {
	class ServiceLocator final
	{
		static SoundSystem* m_SSInstance;
		static NullSoundSystem m_DefaultSS;
	public:
		ServiceLocator() = default;
		~ServiceLocator();
		ServiceLocator(const ServiceLocator& other) = delete;
		ServiceLocator(ServiceLocator&& other) = delete;
		ServiceLocator& operator=(const ServiceLocator& other) = delete;
		ServiceLocator& operator=(ServiceLocator&& other) = delete;

		static SoundSystem& GetSoundSystem() { return* m_SSInstance; }
		static void RegisterSoundSystem(SoundSystem* ss) {
			m_SSInstance = ss == nullptr ? &m_DefaultSS : ss;
		}
	};
}
