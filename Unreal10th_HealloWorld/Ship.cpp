#include "Ship.h"

void Ship::Initialize(int InSize, const Position* InPosition)
{
    Size = InSize;
    for (int i = 0; i < Size; i++)
    {
        Positions[i] = InPosition[i];
    }
    Hits = 0;
}

bool Ship::HitCheckAndProcess(const Position& InHitPos)
{
    bool Result = false;
    if (!IsSunk())  // 배가 침몰하지 않았을 때만 처리
    {
        for (int i = 0; i < Size; i++)
        {
            if (Positions[i] == InHitPos)
            {
                Hits++;
                Result = true;
                break;
            }
        }
    }
    
    return Result;
}
