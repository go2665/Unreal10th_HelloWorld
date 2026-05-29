#pragma once
#include <string>
#include "Utils.h"

struct MazeEnemy
{
	std::string Name = "고블린";
	int Health = 20;
	int AttackPowerMin = 5;
	int AttackPowerMax = 10;
	int Reward = 100;

	MazeEnemy()
	{
		Health = GetRandomRange(15, 25);
		AttackPowerMin = GetRandomRange(3, 7);
		AttackPowerMax = GetRandomRange(8, 12);
		Reward = GetRandomRange(80, 120);
	}
};