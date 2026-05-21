// Unreal10th_HealloWorld.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>
#include <time.h>
//#include <random>

using namespace std;

int main()  // 코드의 시작점
{
	// 실습 풀이 ---------------------------------------------------------------------
	/*
	* 비트플래그를 이용한 캐릭터 상태 변환 구현하기
		캐릭터의 상태는 대기, 점프, 공격, 무적 4가지가 존재
		다음 작업을 수행하고 현재 상태 출력하기
			플레이어의 상태를 대기로 설정
			점프 상태 추가
			공격 상태 추가
			대기 상태 해제
			무적 상태 추가
			무적 상태 토글(XOR 사용)
		현재 상태를 출력할 때는 다음과 같은 양식을 따를 것
			대기 : [O], 점프: [O], 공격: [X], 무적: [O]
	*/
	enum PlayerState
	{
		None		= 0,
		Wait		= 1 << 0,	// 0001
		Jump		= 1 << 1,	// 0010
		Attack		= 1 << 2,	// 0100
		Invincible	= 1 << 3	// 1000
	};

	int State = None;
	// 플레이어의 상태를 대기로 설정
	State |= Wait;		// State에 Wait을 Or 시키고 저장해라.

	printf("\n현재상태\n");
	printf("대기 : [%c], 점프: [%c], 공격: [%c], 무적: [%c]",
		(State & Wait) ? 'O' : 'X',
		(State & Jump) ? 'O' : 'X', 
		(State & Attack) ? 'O' : 'X', 
		(State & Invincible) ? 'O' : 'X');

	// 점프 상태 추가
	State |= Jump;		// State에 Jump을 Or 시키고 저장해라.
	printf("\n현재상태\n");
	printf("대기 : [%c], 점프: [%c], 공격: [%c], 무적: [%c]",
		(State& Wait) ? 'O' : 'X',
		(State& Jump) ? 'O' : 'X',
		(State& Attack) ? 'O' : 'X',
		(State& Invincible) ? 'O' : 'X');

	// 공격 상태 추가
	State |= Attack;	// State에 Attack을 Or 시키고 저장해라.
	printf("\n현재상태\n");
	printf("대기 : [%c], 점프: [%c], 공격: [%c], 무적: [%c]",
		(State& Wait) ? 'O' : 'X',
		(State& Jump) ? 'O' : 'X',
		(State& Attack) ? 'O' : 'X',
		(State& Invincible) ? 'O' : 'X');

	// 대기 상태 해제
	//State &= (~Wait);	// State에 Not시킨 Wait를 And시키고 저장해라.
	State = State & (~Wait);
	printf("\n현재상태\n");
	printf("대기 : [%c], 점프: [%c], 공격: [%c], 무적: [%c]",
		(State& Wait) ? 'O' : 'X',
		(State& Jump) ? 'O' : 'X',
		(State& Attack) ? 'O' : 'X',
		(State& Invincible) ? 'O' : 'X');

	// 무적 상태 추가
	State |= Invincible;
	printf("\n현재상태\n");
	printf("대기 : [%c], 점프: [%c], 공격: [%c], 무적: [%c]",
		(State& Wait) ? 'O' : 'X',
		(State& Jump) ? 'O' : 'X',
		(State& Attack) ? 'O' : 'X',
		(State& Invincible) ? 'O' : 'X');

	// 무적 상태 토글(XOR 사용)
	State ^= Invincible;
	printf("\n현재상태\n");
	printf("대기 : [%c], 점프: [%c], 공격: [%c], 무적: [%c]",
		(State& Wait) ? 'O' : 'X',
		(State& Jump) ? 'O' : 'X',
		(State& Attack) ? 'O' : 'X',
		(State& Invincible) ? 'O' : 'X');

}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.


