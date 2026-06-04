#pragma once
#include <string>

class Actor
{
public:
    virtual void Attack(Actor* InTarget);
    virtual void Die();
    virtual void PrintStatus();

    void ApplyDamage(Actor* InTagrget, int InDamage);
    void TakeDamage(int InDamage);

    inline bool IsAlive() const { return Health > 0; }

public:
    Actor() = default;
    Actor(const char* InName, int InMaxHealth, int InMinAttack, int InMaxAttack)
        : Name(InName), Health(InMaxHealth), MaxHealth(InMaxHealth), AttackPowerMin(InMinAttack), AttackPowerMax(InMaxAttack)
    {
    }
    virtual ~Actor() = default;

protected:
    virtual int CalcDamage();

private:
    std::string Name = "액터";
    int Health = 100;
    int MaxHealth = 100;
    int AttackPowerMin = 1;
    int AttackPowerMax = 10;
};

