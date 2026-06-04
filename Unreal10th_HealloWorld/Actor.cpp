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
	printf("[%s] : [%s]가 죽었습니다.\n", Name.c_str(), Name.c_str());
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
	printf("[%s] : 피격 당했습니다! [%d]의 데미지를 입었습니다.\n", Name.c_str(), InDamage);
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
	int Damage = GetRandomRange(AttackPowerMin, AttackPowerMax);
	if (GetRandom() < CriticalRate)
	{
		Damage = static_cast<int>(Damage * 1.5f);
	}
	return Damage;
}
