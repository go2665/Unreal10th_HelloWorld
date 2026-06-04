#pragma once
#include "Actor.h"
#include "MazeCommon.h"

class Player : public Actor
{
public:
    virtual void Attack(Actor* InTarget) const override;
    virtual void PrintStatus() const override;

    // Getter
    inline const Position& GetLocation() const { return Location; }
    inline int GetMoney() const { return Money; }
    inline bool IsPlayerValidLocation() const
    {
        return Location.X != InvalidPosition && Location.Y != InvalidPosition;
    }

    // Setter
    inline void SetLocation(int InX, int InY) { Location.X = InX; Location.Y = InY; }
    inline void SetLocation(const Position& InLocation) { Location = InLocation; }
    inline void SetInvalidLocation() { Location.X = InvalidPosition; Location.Y = InvalidPosition; };
    inline void AddMoney(unsigned int InAdded) { Money += InAdded; } // 직접 세팅은 안됨. 추가만 가능
    inline void SubMoney(unsigned int InPrice) { Money += InPrice; } // 직접 세팅은 안됨. 삭제만 가능

public:
    Player()
        : Actor("플레이어", 100, 5, 15, 0.15f)
    {
    }
    Player(const char* InName, int InMaxHealth, int InMinAttack, int InMaxAttack, float InCriticalRate)
        : Actor(InName, InMaxHealth, InMinAttack, InMaxAttack, InCriticalRate)
    {
    }
    virtual ~Player() = default;

protected:
    const int InitMoney = 0;
    const int InvalidPosition = -1;

    Position Location{ InvalidPosition, InvalidPosition };
    int Money = InitMoney;
};