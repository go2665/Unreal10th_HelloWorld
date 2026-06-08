#include <stdlib.h>
#include "ShipManager.h"
#include "Map.h"
#include "HiddenMap.h"

void ShipManager::PlaceAllShips(HiddenMap* InMap)
{
    if (!InMap) // 맵이 없으면 리턴
        return;

    static constexpr int ShipSizes[ShipTypeCount] = { 5,4,3,2 };

    for (int i = 0; i < ShipTypeCount; i++)
    {
        bool Placed = false;
        while (!Placed)
        {
            int x = rand() % Map::MapSize;
            int y = rand() % Map::MapSize;
            bool bHorizontal = (rand() % 2 == 0);

            if (CanPlaceShip(x, y, ShipSizes[i], bHorizontal, InMap))
            {
                Position positions[Ship::MaxShipSize];
                for (int j = 0; j < ShipSizes[i]; j++)
                {
                    int NewX = x + (bHorizontal ? j : 0);
                    int NewY = y + (bHorizontal ? 0 : j);
                    InMap->SetCellType(NewX, NewY, CellType::Ship);
                    positions[j] = Position(NewX, NewY);
                }
                Ships[i].Initialize(ShipSizes[i], positions);
                Placed = true;
            }
        }
    }
}

bool ShipManager::AttackProcess(const Position& InHitPos)
{
    ShipJustSunk = false;

    for (int i = 0; i < ShipTypeCount; i++)
    {
        if (Ships[i].IsSunk())
            continue;

        if (Ships[i].HitCheckAndProcess(InHitPos))
        {
            if (Ships[i].IsSunk())
            {
                ShipJustSunk = true;
                SunkShipCount++;
            }
            return true;
        }
    }

    return false;
}

bool ShipManager::CanPlaceShip(int InX, int InY, int InSize, bool InIsHorizontal, const HiddenMap* InMap) const
{
    for (int i = 0; i < InSize; i++)
    {
        int NewX = InX + (InIsHorizontal ? i : 0);
        int NewY = InY + (InIsHorizontal ? 0 : i);
        if (!Map::IsValidPosition(NewX, NewY))
            return false;
        if (InMap->GetCellType(NewX, NewY) != CellType::Empty)
            return false;
    }
    return true;
}
