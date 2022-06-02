#pragma once
#include <string>
namespace dae {
	class Sound
	{
	class SoundImpl;
	public:
		Sound(std::string loc);
		~Sound();
		Sound(const Sound&) = delete;
		Sound(Sound&&) = delete;
		Sound& operator= (const Sound&) = delete;
		Sound& operator= (const Sound&&) = delete;

		void Play(int volume) const;
	private:
		SoundImpl* pImpl{};
	};
}
