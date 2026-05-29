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
	MazeEnemy(const std::string& InName, int InLevel) 
		: Name(InName)
	{ 
		Health *= InLevel;
		AttackPowerMin *= InLevel;
		AttackPowerMax *= InLevel;
		Reward *= InLevel;
	}

	// +연산자를 오버로딩 한다.
	// 결과는 MazeEnemy타입으로 나온다.
	// 계산 대상은 나와 InOther다.
	MazeEnemy operator+(const MazeEnemy& InOther) const	// 이 const는 맴버를 수정하지 않는다.(읽기 전용이다.)
	{
		//	Health = 20; // const 때문에 안된다.

		MazeEnemy Result;
		Result.Name = this->Name + InOther.Name;	// this : 자기 자신의 주소
		Result.AttackPowerMin = (AttackPowerMin + InOther.AttackPowerMin) / 2;
		Result.AttackPowerMax = AttackPowerMax + InOther.AttackPowerMax;
		Result.Reward = Reward + InOther.Reward;

		return Result;
	}
};