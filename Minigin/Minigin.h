#pragma once
struct SDL_Window;
namespace dae
{
	class SoundSystem;

	class Minigin
	{
	public:
		void Initialize();
		virtual void LoadGame() const;
		void Test();
		virtual void Cleanup();
		void Run();
	private:
		static const int MsPerFrame = 16; //16 for 60 fps, 33 for 30 fps
		SDL_Window* m_Window{};
		float m_FixedTimeStep=0.010f;
	};
}