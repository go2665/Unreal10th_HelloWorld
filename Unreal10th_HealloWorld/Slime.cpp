#include "Slime.h"

void Slime::Skill(Actor* InTarget) const
{
	printf("[%s] : 슬라임이 산성용액 스킬을 사용합니다.\n", Name.c_str());
	int Damage = CalcDamage() * 2.5f;
	ApplyDamage(InTarget, Damage);
}
