#pragma once
#include <string>
#include "Utils.h"

struct Deprecated_MazeEnemy
{
	std::string Name = "고블린";
	int Health = 20;
	int AttackPowerMin = 5;
	int AttackPowerMax = 10;
	int Reward = 100;

	Deprecated_MazeEnemy()
	{
		Health = GetRandomRange(15, 25);
		AttackPowerMin = GetRandomRange(3, 7);
		AttackPowerMax = GetRandomRange(8, 12);
		Reward = GetRandomRange(80, 120);
	}
	Deprecated_MazeEnemy(const std::string& InName, int InLevel)
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
	Deprecated_MazeEnemy operator+(const Deprecated_MazeEnemy& InOther) const	// 이 const는 맴버를 수정하지 않는다.(읽기 전용이다.)
	{
		//	Health = 20; // const 때문에 안된다.

		Deprecated_MazeEnemy Result;
		Result.Name = this->Name + InOther.Name;	// this : 자기 자신의 주소
		Result.AttackPowerMin = (AttackPowerMin + InOther.AttackPowerMin) / 2;
		Result.AttackPowerMax = AttackPowerMax + InOther.AttackPowerMax;
		Result.Reward = Reward + InOther.Reward;

		return Result;
	}

	Deprecated_MazeEnemy operator-(const Deprecated_MazeEnemy& InOther) const
	{
		Deprecated_MazeEnemy Result;
		Result.Name = "약화된 " + this->Name;
		Result.AttackPowerMin = (AttackPowerMin - InOther.AttackPowerMin) / 2;
		if(Result.AttackPowerMin < 1)
		{
			Result.AttackPowerMin = 1;
		}
		Result.AttackPowerMax = AttackPowerMax - InOther.AttackPowerMax;
		if (Result.AttackPowerMax < 1)
		{
			Result.AttackPowerMax = 1;
		}
		if (Result.AttackPowerMax < Result.AttackPowerMin)
		{
			Result.AttackPowerMax = Result.AttackPowerMin;
		}
		Result.Reward = Reward + InOther.Reward;

		return Result;
	}

	Deprecated_MazeEnemy operator*(float InOther) const
	{
		Deprecated_MazeEnemy Result;
		Result.Name = this->Name;
		Result.Health = static_cast<int>(Health * InOther);
		Result.AttackPowerMin = static_cast<int>(AttackPowerMin * InOther);
		Result.AttackPowerMax = static_cast<int>(AttackPowerMax * InOther);
		Result.Reward = static_cast<int>(Reward * InOther);
		return Result;
	}

	Deprecated_MazeEnemy& operator*=(float InOther)
	{		
		Health = static_cast<int>(Health * InOther);
		AttackPowerMin = static_cast<int>(AttackPowerMin * InOther);
		AttackPowerMax = static_cast<int>(AttackPowerMax * InOther);
		Reward = static_cast<int>(Reward * InOther);
		return *this;
	}
};