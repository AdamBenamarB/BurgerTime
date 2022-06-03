#include "MiniginPCH.h"
#include "SoundSystem.h"

#include <thread>

#include "AudioClip.h"

dae::SoundSystem::SoundSystem()
	:m_Clips{}
{
	m_Thread = std::thread(&dae::SoundSystem::CheckQueue,this);
}

dae::SoundSystem::~SoundSystem()
{
	m_Thread.join();
}

int dae::SoundSystem::AddSound(std::string loc)
{
	m_Clips.push_back(std::make_shared<AudioClip>(loc));
	return (unsigned int)m_Clips.size();
}

void dae::SoundSystem::CheckQueue()
{
	for (int i{}; i < m_ToBePlayed.size(); ++i)
	{
		m_Mutex.lock();
		if (!m_Clips[m_ToBePlayed[i].first]->IsLoaded())
			m_Clips[m_ToBePlayed[i].first]->Load();
		m_Clips[m_ToBePlayed[i].first]->Play(m_ToBePlayed[i].second);
		m_Mutex.unlock();
	}
	m_ToBePlayed.clear();
}

void dae::SoundSystem::Play(int id, int volume)
{
	m_ToBePlayed.push_back(std::make_pair(id, volume));
}