#pragma once
#include "Monster.h"
class Orc :
    public Monster
{
public:
    virtual void Skill(Actor* InTarget) const override;

public:
    Orc()
        :Monster()
    {
        Name = "오크";
    }
};

