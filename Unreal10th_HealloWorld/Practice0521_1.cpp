#include <iostream>
#include "Practice0521_1.h"

void StateChangeRun()
{
	int State = None;
	
	// 플레이어의 상태를 대기로 설정
	State = SetState(State, Wait);	
	PrintState(State);
	
	// 점프 상태 추가
	State = SetState(State, Jump);
	PrintState(State);
	
	// 공격 상태 추가
	State = SetState(State, Attack);
	PrintState(State);
	
	// 대기 상태 해제
	ClearState(State, Wait);
	PrintState(State);
	
	// 무적 상태 추가
	State = SetState(State, Invincible);
	PrintState(State);
	
	// 무적 상태 토글(XOR 사용)
	ToggleState(State, Invincible);
	PrintState(State);
}

int SetState(int State, PlayerState AddedState)
{	
	return State | AddedState;
}

int ClearState(int State, PlayerState ClearTargetState)
{
	return State & (~ClearTargetState);
}

int ToggleState(int State, PlayerState ToggleTargetState)
{
	return State ^ ToggleTargetState;
}

void PrintState(int State)
{
	printf("\n현재상태\n");
	printf("대기 : [%c], 점프: [%c], 공격: [%c], 무적: [%c]",
		StateSetChecker(State, Wait),
		StateSetChecker(State, Jump),
		StateSetChecker(State, Attack),
		StateSetChecker(State, Invincible));
}