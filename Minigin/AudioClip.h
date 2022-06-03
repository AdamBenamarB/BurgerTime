#pragma once
#include <string>
namespace dae {
	class AudioClip
	{
	class AudioImpl;
	public:
		AudioClip(std::string loc);
		~AudioClip();
		AudioClip(const AudioClip&) = delete;
		AudioClip(AudioClip&&) = delete;
		AudioClip& operator= (const AudioClip&) = delete;
		AudioClip& operator= (const AudioClip&&) = delete;

		void Play(int volume) const;
		void Load();
		bool IsLoaded() const;
	private:
		AudioImpl* pImpl{};
		std::string m_FileLoc{};
	};
}
