#include "Goblin.h"

void Goblin::Skill(Actor* InTarget) const
{
	printf("[%s] : 고블린이 독화살 스킬을 사용합니다.\n", Name.c_str());
	int Damage = static_cast<int>(CalcDamage() * 1.5f);
	ApplyDamage(InTarget, Damage);
}
