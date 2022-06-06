#include "Game.h"

#include "GameInstance.h"
#include "LevelLoader.h"
#include "NextScreen.h"

void Game::LoadGame() const
{
	GameInstance::GetInstance().StartGame();
	
	LevelLoader::LoadLevel("../Data/Levels/level2.json");

	
}

void Game::Cleanup()
{
	GameInstance::GetInstance().EndGame();
	Minigin::Cleanup();
}
