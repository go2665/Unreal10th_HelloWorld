#include "Monster.h"
#include "Utils.h"

void Monster::Attack(Actor* InTarget) const
{
	if (GetRandom() < 0.2f)
	{
		Skill(InTarget);
	}
	else
	{
		printf("[%s] : 몬스터가 공격합니다.\n", Name.c_str());
		Actor::Attack(InTarget);
	}
}

void Monster::Skill(Actor* InTarget) const
{
	printf("[%s] : 몬스터가 스킬을 사용합니다.\n", Name.c_str());
	int Damage = CalcDamage() * 2;
	ApplyDamage(InTarget, Damage);
}

void Monster::MakeVariant()
{
	Health = GetRandomRange(15, 25);
	MaxHealth = Health;
	AttackPowerMin = GetRandomRange(3, 7);
	AttackPowerMax = GetRandomRange(8, 12);
	Reward = GetRandomRange(80, 120);
}
