#pragma once

enum PlayerState
{
	None = 0,
	Wait = 1 << 0,	// 0001
	Jump = 1 << 1,	// 0010
	Attack = 1 << 2,	// 0100
	Invincible = 1 << 3	// 1000
};

// 단순 실행용
void StateChangeRun();

/// <summary>
/// 상태 설정용
/// </summary>
/// <param name="State">원본 상태 데이터</param>
/// <param name="SetTargetState">추가할 상태</param>
/// <returns>변경 완료된 상태</returns>
int SetState(int State, PlayerState SetTargetState);

/// <summary>
/// 상태 해제용
/// </summary>
/// <param name="State">원본 상태 데이터</param>
/// <param name="ClearTargetState">제거할 상태</param>
/// <returns>변경 완료된 상태</returns>
int ClearState(int State, PlayerState ClearTargetState);

/// <summary>
/// 상태 토글용
/// </summary>
/// <param name="State">원본 상태 데이터</param>
/// <param name="ToggleTargetState">토글 될 상태</param>
/// <returns>변경 완료된 상태</returns>
int ToggleState(int State, PlayerState ToggleTargetState);

/// <summary>
/// 상태 출력용 함수
/// </summary>
/// <param name="State">현재 상태</param>
void PrintState(int State);

/// <summary>
/// 특정 상태가 설정되어 있는지 확인해서 'O' 또는 'X'를 리턴하는 함수
/// </summary>
/// <param name="State">원본 상태 데이터</param>
/// <param name="TargetState">체크할 상태</param>
/// <returns>TargetState가 Set 되어 있으면 'O', 아니면 'X'</returns>
inline char StateSetChecker(int State, PlayerState TargetState)
{
	return (State & TargetState) ? 'O' : 'X';
}