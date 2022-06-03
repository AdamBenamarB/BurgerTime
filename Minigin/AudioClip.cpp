#include "MiniginPCH.h"
#include "AudioClip.h"
#include <SDL_mixer.h>

class dae::AudioClip::AudioImpl
{
public:
	AudioImpl(std::string loc)
	{
		m_Chunk = Mix_LoadWAV(loc.c_str());
		if(m_Chunk==nullptr)
		{
			throw std::runtime_error(std::string("Failed to load AudioClip: ") + SDL_GetError());
		}
	}
	~AudioImpl()
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

dae::AudioClip::AudioClip(std::string loc)
	:m_FileLoc{loc}
{
}

dae::AudioClip::~AudioClip()
{
	delete pImpl;
}

void dae::AudioClip::Play(int volume) const
{
	pImpl->Play(volume);
}

void dae::AudioClip::Load()
{
	pImpl = new AudioImpl(m_FileLoc);
}

bool dae::AudioClip::IsLoaded() const
{
	return pImpl != nullptr;
}