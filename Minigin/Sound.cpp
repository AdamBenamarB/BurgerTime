#include "MiniginPCH.h"
#include "Sound.h"
#include <SDL_mixer.h>

class dae::Sound::SoundImpl
{
public:
	SoundImpl(std::string loc)
	{
		m_Chunk = Mix_LoadWAV(loc.c_str());
		if(m_Chunk==nullptr)
		{
			throw std::runtime_error(std::string("Failed to load sound: ") + SDL_GetError());
		}
	}
	~SoundImpl()
	{
		Mix_FreeChunk(m_Chunk);
	}
	void Play(int volume) const
	{

		Mix_VolumeChunk(m_Chunk, volume);
		Mix_PlayChannel(-1, m_Chunk, 10);
	}
private:
	Mix_Chunk* m_Chunk{};
};

dae::Sound::Sound(std::string loc)
{
	pImpl= new SoundImpl(loc);
}

dae::Sound::~Sound()
{
	delete pImpl;
}

void dae::Sound::Play(int volume) const
{
	pImpl->Play(volume);
}
