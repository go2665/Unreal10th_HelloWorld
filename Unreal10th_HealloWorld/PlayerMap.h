#pragma once
#include "Map.h"
class PlayerMap :
    public Map
{
public:
    virtual void PrintMap() const override;
};

