#pragma once
#include "Monster.h"
class Slime :
    public Monster
{
public:
    virtual void Skill(Actor* InTarget) const override;

public:
    Slime()
        :Monster()
    {
        Name = "슬라임";
    }
};

