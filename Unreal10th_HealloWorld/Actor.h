#pragma once
#include <string>

class Actor
{
public:
    virtual void Attack(Actor* InTarget) const;
    virtual void Die();
    virtual void PrintStatus() const;

    void ApplyDamage(Actor* InTagrget, int InDamage) const;
    void TakeDamage(int InDamage);

    inline bool IsAlive() const { return Health > 0; }
    inline void AddHealth(int InRestore) {
        Health += InRestore;
        if (Health > MaxHealth)
            Health = MaxHealth;
    }

public:
    Actor() = default;
    Actor(const char* InName, int InMaxHealth, int InMinAttack, int InMaxAttack, float InCriticalRate)
        : Name(InName), Health(InMaxHealth), MaxHealth(InMaxHealth), AttackPowerMin(InMinAttack), AttackPowerMax(InMaxAttack), CriticalRate(InCriticalRate)
    {
    }
    virtual ~Actor() = default;

protected:
    virtual int CalcDamage() const;

protected:
    std::string Name = "액터";
    int Health = 100;
    int MaxHealth = 100;
    int AttackPowerMin = 1;
    int AttackPowerMax = 10;
    float CriticalRate = 0.1f;      // 기본 크리티컬 확율은 10%
};

