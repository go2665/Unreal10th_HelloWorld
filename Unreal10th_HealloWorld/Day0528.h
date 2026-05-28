#pragma once

void Day0528();
void Day0528_String();
void Day0528_FileIO();
void Day0528_Structure();
void FindCharacter(const std::string& Str, const char Target);

void Test(int i = 0);

struct Enemy	// 적은
{
	std::string Name;	// 이름을 가지고
	float Health;		// 체력을 가지고
	float AttackPower;	// 공격력을 가지고
	int Reward;			// 보상을 가진다.
};

void TestStruct(Enemy Target);