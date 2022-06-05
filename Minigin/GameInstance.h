#pragma once
#include "Singleton.h"

class GameInstance : public dae::Singleton<GameInstance>
{
public:
	void SetPlates(int amt);

	void FillPlate();
private:
	int m_LevelIdx{ 1 };

	int m_Plates{},
		m_FullPlates{};

	int m_Score{};
};