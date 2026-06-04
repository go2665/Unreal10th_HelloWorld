#pragma once
#include "Actor.h"
class Monster : public Actor
{
public:
	virtual void Attack(Actor* InTarget) const override;
	virtual void Skill(Actor* InTarget) const;

protected:
	int Reward = 100;

public:
	Monster() 
		: Actor("몬스터", 100, 5, 15, 0.1f)
	{
		MakeVariant();
	}
	Monster(const char* InName, int InMaxHealth, int InMinAttack, int InMaxAttack, float InCriticalRate)
		: Actor(InName, InMaxHealth, InMinAttack, InMaxAttack, InCriticalRate)
	{
	}
	virtual ~Monster() = default;

protected:
	void MakeVariant();	// 스텟 재조정
};

