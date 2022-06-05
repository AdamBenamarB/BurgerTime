#include "MiniginPCH.h"
#include "SoundSystem.h"

#include <thread>

#include "AudioClip.h"

dae::SoundSystem::SoundSystem()
	:m_Clips{}
{
	Initialize();
}

dae::SoundSystem::~SoundSystem()
{
	m_Active = false;
	m_Thread.join();
}

void dae::SoundSystem::Initialize()
{

	m_Thread = std::thread(&dae::SoundSystem::CheckQueue, this);
}


int dae::SoundSystem::AddSound(std::string loc)
{
	m_Clips.push_back(std::make_shared<AudioClip>(loc));
	return (unsigned int)m_Clips.size();
}

void dae::SoundSystem::CheckQueue()
{
	while (m_Active)
	{
		while (m_ToBePlayed.size() > 0)
		{
			m_Mutex.lock();
			if (!m_Clips[m_ToBePlayed.back().first]->IsLoaded())
				m_Clips[m_ToBePlayed.back().first]->Load();
			m_Clips[m_ToBePlayed.back().first]->Play(m_ToBePlayed.back().second);
			m_ToBePlayed.pop_back();
			m_Mutex.unlock();
		}
	}
}

void dae::SoundSystem::Play(int id, int volume)
{
	m_ToBePlayed.push_back(std::make_pair(id, volume));
}