#pragma once
#include "Position.h"

//DEPRECATED
const int Deprecated_InvalidPosition = -1;
const int Deprecated_InitMoney = 0;
const int Deprecated_InitHealth = 100;

enum MoveDirection
{
	DirNone = 0,
	DirUp = 1 << 0,	// 1
	DirDown = 1 << 1,	// 2
	DirLeft = 1 << 2,	// 4
	DirRight = 1 << 3	// 8
};

enum MazeTile
{
	MazePath = 0,
	MazeWall = 1,
	MazeStart = 2,
	MazeEnd = 3
};

enum RandomIncounterType
{
	RI_None = 0,	// 아무일 없음
	RI_Battle,		// 전투
	RI_Heal,		// 회복
	RI_Treasure		// 보물 찾음(돈)
};

