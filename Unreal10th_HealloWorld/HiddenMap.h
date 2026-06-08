#pragma once
#include "Map.h"

// 배가 배치된 정보를 저장하는 맵
// Cell에는 Empty와 Ship만 존재
class HiddenMap :
    public Map
{
public:
    virtual void PrintMap() const override;
};

