#include <iostream>
#include "BattleShip.h"
#include "PlayerMap.h"
#include "HiddenMap.h"

void BattleShip::Initialize()
{
    MapHidden = new HiddenMap();
    MapPlayer = new PlayerMap();
    EnemyFleet = new ShipManager();
    if (EnemyFleet)
    {
        EnemyFleet->PlaceAllShips(MapHidden);
    }
}

void BattleShip::Clear()
{    
    if (EnemyFleet)
    {
        delete EnemyFleet;
        EnemyFleet = nullptr;
    }
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
    if (!MapHidden || !MapPlayer || !EnemyFleet)
    {
        printf("ERROR : 초기화가 안되었습니다.\n");
        return;
    }

    printf("배틀쉽 게임 시작!\n%d턴 안에 모든 적을 침몰시키세요.\n", MaxTurn);
    while (!IsGameOver())
    {
        PrintGameState();
        InputHandle();
    }
    PrintGameResult();
}

bool BattleShip::Shoot(int InX, int InY)
{
    if (!Map::IsValidPosition(InX, InY))
    {
        printf("잘못된 좌표입니다.\n");
        return false;
    }

    Position HitPos(InX, InY);
    if (MapPlayer->GetCellType(HitPos) != CellType::Empty)
    {
        printf("공격한 곳을 다시 공격했습니다.\n");
        return false;
    }

    if (EnemyFleet->AttackProcess(HitPos))
    {
        // 맞았다.
        MapPlayer->SetCellType(HitPos, CellType::Hit);
        if (EnemyFleet->WasShipJustSunk())
        {
            printf("명중입니다! 적함이 침몰했습니다.\n");
        }
        else
        {
            printf("명중입니다!\n");
        }
    }
    else
    {
        // 빗나갔다.
        printf("빗나갔습니다.\n");
        MapPlayer->SetCellType(HitPos, CellType::Miss);
    }
    TurnLeft--;
    return true;
}

void BattleShip::InputHandle()
{
    int x = 0;
    int y = 0;
    do
    {
        printf("공격 좌표를 입력하세요 (x y) : ");
        std::cin >> x >> y;
    } while (!Shoot(x, y));
}

void BattleShip::PrintGameState() const
{
    if (IsTestMode)
    {
        MapHidden->PrintMap();
    }
    MapPlayer->PrintMap();
    printf("남은 턴 : %d\n", TurnLeft);
    printf("남은 적 함선 수 : %d\n", EnemyFleet->GetAliveShipCount());
}

void BattleShip::PrintGameResult() const
{
    if (EnemyFleet->IsAllSunk())
    {
        printf("승리! 모든 적 함선이 침몰했습니다.\n");
    }
    else
    {
        printf("패배..... 시간이 다 되었습니다.\n");
        MapHidden->PrintMap();
    }
}