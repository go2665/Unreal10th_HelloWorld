#pragma once
#include "Monster.h"
class Goblin :
    public Monster
{
public:
    virtual void Skill(Actor* InTarget) const override;

public:
    Goblin()
        :Monster()
    {
        Name = "고블린";
    }
};

