#include <iostream>
#include "Actor.h"
#include "Utils.h"

void Actor::Attack(Actor* InTarget) const
{
	if (InTarget)
	{
		int Damage = CalcDamage();
		ApplyDamage(InTarget, Damage);
	}
}

void Actor::Die()
{
	printf("[%s]가 죽었습니다.\n", Name.c_str());
}

void Actor::PrintStatus() const
{
	printf("-------------------------------------------\n");	
	int Ratio = static_cast<int>((Health / static_cast<float>(MaxHealth)) * 10.0f);
	printf("[%s] : ", Name.c_str());
	for (int i = 0; i < Ratio; i++)
	{
		printf("■");
	}
	for (int i = Ratio; i < 10; i++)
	{
		printf("□");
	}
	printf(" ( %d / %d )\n", Health, MaxHealth);
	printf("-------------------------------------------\n");
}

void Actor::ApplyDamage(Actor* InTagrget, int InDamage) const
{
	if (InTagrget)
	{
		InTagrget->TakeDamage(InDamage);
	}
}

void Actor::TakeDamage(int InDamage)
{
	printf("피격 당했습니다! [%d]의 데미지를 입었습니다.\n", InDamage);
	Health -= InDamage;
	if (Health <= 0)
	{
		Health = 0;
		Die();
	}
	PrintStatus();
}

int Actor::CalcDamage() const
{
	return GetRandomRange(AttackPowerMin, AttackPowerMax);
}
