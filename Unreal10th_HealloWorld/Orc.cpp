#include "Orc.h"

void Orc::Skill(Actor* InTarget) const
{
	printf("[%s] : 도끼 던지기 스킬을 사용합니다.\n", Name.c_str());
	int Damage = static_cast<int>(CalcDamage() * 3.0f);
	ApplyDamage(InTarget, Damage);
}
