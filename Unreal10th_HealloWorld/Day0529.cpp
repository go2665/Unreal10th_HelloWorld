#include "Day0529.h"

void Day0529()
{
	Deprecated_MazeEnemy E1("오크", 1);
	Deprecated_MazeEnemy E2("슬라임", 2);

	PrintEnemyInfo(E1);
	PrintEnemyInfo(E2);

	Deprecated_MazeEnemy E3 = FusionEnemy(E1, E2);
	PrintEnemyInfo(E3);

	Deprecated_MazeEnemy E4 = E1 + E2;
	PrintEnemyInfo(E4);

	// 간단 실습
	// 1. MazeEnemy에 -연산자 오버로딩하기
	//		E5 = E1 - E2;
	Deprecated_MazeEnemy E5 = E1 - E2;
	PrintEnemyInfo(E5);

	// 2. MazeEnemy에 *연산자 오버로딩하기(*의 오른쪽 값은 float)
	//		E6 = E5 * 2;
	Deprecated_MazeEnemy E6 = E5 * 2;
	PrintEnemyInfo(E6);

	// 3. MazeEnemy에 *=연산자 오버로딩하기(*의 오른쪽 값은 float)
	//		E6 *= 3;
	E6 *= 3;
	PrintEnemyInfo(E6);
}

void PrintEnemyInfo(Deprecated_MazeEnemy& InEnemy)
{
	printf("----------------------------\n");
	printf("이름   : %s\n", InEnemy.Name.c_str());
	printf("체력   : %d\n", InEnemy.Health);
	printf("공격력 : %d - %d\n", InEnemy.AttackPowerMin, InEnemy.AttackPowerMax);
	printf("보상   : %d\n", InEnemy.Reward);
	printf("----------------------------\n");
}

Deprecated_MazeEnemy FusionEnemy(Deprecated_MazeEnemy& InEnemy1, Deprecated_MazeEnemy& InEnemy2)
{
	Deprecated_MazeEnemy Result;
	Result.Name = InEnemy1.Name + InEnemy2.Name;
	Result.AttackPowerMin = (InEnemy1.AttackPowerMin + InEnemy2.AttackPowerMin) / 2;
	Result.AttackPowerMax = InEnemy1.AttackPowerMax + InEnemy2.AttackPowerMax;
	Result.Reward = InEnemy1.Reward + InEnemy2.Reward;

	return Result;
}
