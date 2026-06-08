#include <iostream>
#include "BattleShip.h"
#include "PlayerMap.h"
#include "HiddenMap.h"

void BattleShip::Initialize()
{
    MapHidden = new HiddenMap();
    MapPlayer = new PlayerMap();
}

void BattleShip::Clear()
{    
    if (MapPlayer)
    {
        delete MapPlayer;
        MapPlayer = nullptr;
    }
    if (MapHidden)
    {
        delete MapHidden;
        MapHidden = nullptr;
    }
}

void BattleShip::Play()
{
    if (!MapHidden || !MapPlayer)
    {
        printf("ERROR : 초기화가 안되었습니다.\n");
        return;
    }
}

bool BattleShip::Shoot(int InX, int InY)
{
    return false;
}

bool BattleShip::IsGameOver() const
{
    return false;
}

void BattleShip::InputHandle()
{
}

void BattleShip::PrintGameStatus() const
{
}

void BattleShip::PrintGameResult() const
{
}