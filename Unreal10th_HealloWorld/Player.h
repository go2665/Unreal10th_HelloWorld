#pragma once
#include "MazeCommon.h"

struct Deprecated_Player
{
    Position Pos{InvalidPosition, InvalidPosition};
    int Health = InitHealth;
    int MaxHealth = InitHealth;
    int AttackPowerMin = 5;
    int AttackPowerMax = 15;
    int Money = InitMoney;
};