#pragma once
#include <mutex>
#include <string>
#include <thread>

namespace dae {
	class AudioClip;
	class SoundSystem
	{
	public:
		SoundSystem();

		virtual int AddSound(std::string loc);
		virtual void Play(int id,int volume);
		~SoundSystem();

	private:
		void Initialize();
		void CheckQueue();

		std::vector<std::shared_ptr<AudioClip>> m_Clips{};
		std::vector<std::pair<int,int>> m_ToBePlayed{};
		std::thread m_Thread{};
		std::mutex m_Mutex{};

		bool m_Active=true;
	};

	class NullSoundSystem : public SoundSystem
	{
		virtual int AddSound(std::string) override { return -1; }
		virtual void Play(int, int) override{}
	};
}
