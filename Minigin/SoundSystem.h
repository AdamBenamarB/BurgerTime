#pragma once

namespace dae {
	class Sound;
	class SoundSystem
	{
	public:
		
		//virtual ~SoundSystem();
		//virtual void Play(const std::shared_ptr<Sound> sound, int volume);
	};

	class NullSoundSystem : public SoundSystem
	{
		//void Play(const std::shared_ptr<Sound>, int) override {}
	};
}