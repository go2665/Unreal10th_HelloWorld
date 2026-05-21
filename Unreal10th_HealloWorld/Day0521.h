#pragma once
//// 실습 풀이 ---------------------------------------------------------------------
//	/*
//	* 비트플래그를 이용한 캐릭터 상태 변환 구현하기
//		캐릭터의 상태는 대기, 점프, 공격, 무적 4가지가 존재
//		다음 작업을 수행하고 현재 상태 출력하기
//			플레이어의 상태를 대기로 설정
//			점프 상태 추가
//			공격 상태 추가
//			대기 상태 해제
//			무적 상태 추가
//			무적 상태 토글(XOR 사용)
//		현재 상태를 출력할 때는 다음과 같은 양식을 따를 것
//			대기 : [O], 점프: [O], 공격: [X], 무적: [O]
//	*/
//enum PlayerState
//{
//	None = 0,
//	Wait = 1 << 0,	// 0001
//	Jump = 1 << 1,	// 0010
//	Attack = 1 << 2,	// 0100
//	Invincible = 1 << 3	// 1000
//};
//
//int State = None;
//// 플레이어의 상태를 대기로 설정
//State |= Wait;		// State에 Wait을 Or 시키고 저장해라.
//
//printf("\n현재상태\n");
//printf("대기 : [%c], 점프: [%c], 공격: [%c], 무적: [%c]",
//	(State& Wait) ? 'O' : 'X',
//	(State& Jump) ? 'O' : 'X',
//	(State& Attack) ? 'O' : 'X',
//	(State& Invincible) ? 'O' : 'X');
//
//// 점프 상태 추가
//State |= Jump;		// State에 Jump을 Or 시키고 저장해라.
//printf("\n현재상태\n");
//printf("대기 : [%c], 점프: [%c], 공격: [%c], 무적: [%c]",
//	(State& Wait) ? 'O' : 'X',
//	(State& Jump) ? 'O' : 'X',
//	(State& Attack) ? 'O' : 'X',
//	(State& Invincible) ? 'O' : 'X');
//
//// 공격 상태 추가
//State |= Attack;	// State에 Attack을 Or 시키고 저장해라.
//printf("\n현재상태\n");
//printf("대기 : [%c], 점프: [%c], 공격: [%c], 무적: [%c]",
//	(State& Wait) ? 'O' : 'X',
//	(State& Jump) ? 'O' : 'X',
//	(State& Attack) ? 'O' : 'X',
//	(State& Invincible) ? 'O' : 'X');
//
//// 대기 상태 해제
////State &= (~Wait);	// State에 Not시킨 Wait를 And시키고 저장해라.
//State = State & (~Wait);
//printf("\n현재상태\n");
//printf("대기 : [%c], 점프: [%c], 공격: [%c], 무적: [%c]",
//	(State& Wait) ? 'O' : 'X',
//	(State& Jump) ? 'O' : 'X',
//	(State& Attack) ? 'O' : 'X',
//	(State& Invincible) ? 'O' : 'X');
//
//// 무적 상태 추가
//State |= Invincible;
//printf("\n현재상태\n");
//printf("대기 : [%c], 점프: [%c], 공격: [%c], 무적: [%c]",
//	(State& Wait) ? 'O' : 'X',
//	(State& Jump) ? 'O' : 'X',
//	(State& Attack) ? 'O' : 'X',
//	(State& Invincible) ? 'O' : 'X');
//
//// 무적 상태 토글(XOR 사용)
//State ^= Invincible;
//printf("\n현재상태\n");
//printf("대기 : [%c], 점프: [%c], 공격: [%c], 무적: [%c]",
//	(State& Wait) ? 'O' : 'X',
//	(State& Jump) ? 'O' : 'X',
//	(State& Attack) ? 'O' : 'X',
//	(State& Invincible) ? 'O' : 'X');