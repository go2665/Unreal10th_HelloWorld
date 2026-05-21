#pragma once

// 기능이 완전히 독립적이라 재활용 용도로 만드는 함수
void PrintGameState(int Turn, int PlayerMoney, int EnemyMoney);
int RandomRange(int Min, int Max);
int InputPlayerBet(int MaxBet);

// 의도를 명확하게 보여주는 용도로 만드는 함수
void DiceGameRun();
int Dice6();

// 각종 수식처럼 자주 변할 수 있는 부분을 쉽게 구분하기 위해 만드는 함수
bool IsGameClear(int PlayerMoney, int EnemyMoney);
int GetMaxBet(int PlayerMoney, int EnemyMoney);
int CalcEnemyBet(int MaxBet);