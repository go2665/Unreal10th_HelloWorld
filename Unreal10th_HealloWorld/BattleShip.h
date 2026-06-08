#pragma once
#include "ShipManager.h"

// 게임 진행
//	- 턴 처리
//	- 맵(플레이어가 공격한 결과 맵, 적함선이 실제 배치되어 있는 맵)
//	- 적 함선 관리
//	- 공격 처리
//	- 게임 오버 처리
//	- 입력처리
//	- 출력 처리

// 게임에 대한 전반적인 관리 + 게임 진행
class BattleShip
{
public:
	// 클래스 초기화(각종 자원 할당 및 초기화)
	void Initialize();

	// 클래스 정리(할당한 자원들 릴리즈)
	void Clear();

	// 게임 시작
	void Play();

private:
	// static
	//  - 인스턴스를 만들지 않아도 접근이 가능해진다.
	//  - 모든 인스턴스에서 공용으로 사용할 수 있다.

	// 최대 턴 수
	static constexpr int MaxTurn = 30;
	
	// 남은 턴 수
	int TurnLeft = MaxTurn;

	// 적의 실제 함선 위치를 저장해 놓은 맵
	class HiddenMap* MapHidden = nullptr;
	// 플레이어가 공격한 결과를 저장해 놓은 맵
	class PlayerMap* MapPlayer = nullptr;
	// 적함선 관리
	ShipManager* EnemyFleet = nullptr;

	// 지정된 좌표에 공격
	bool Shoot(int InX, int InY);


	// 입력처리
	void InputHandle();

	// 게임 상태 출력
	void PrintGameState() const;

	// 게임 결과 출력
	void PrintGameResult() const;

	// 게임 오버 확인
	inline bool IsGameOver() const { return TurnLeft <= 0 || (EnemyFleet && EnemyFleet->IsAllSunk()); }

	// 테스트 모드 여부(true면 적함선 위치 찍어서 보여주기)
	bool IsTestMode = true;
};

/*
	//목표
	//	- 플레이어는 컴퓨터가 숨겨놓은 적 함선을 찾아 격침시킨다.
	//맵 크기는 10 x 10이다.
	//	- 각 칸에는 함선 또는 빈 칸이 위치한다.
	//적 함선 종류
	//	- 총 4척: 크기 5, 4, 3, 2 (항공모함, 전함, 순양함, 구축함 등)
	//함선 배치
	//	- 함선은 맵에 겹치지 않게 가로 또는 세로로 랜덤 배치된다.
	//플레이어의 목표
	//	- 제한된 공격 횟수(30회) 내에 모든 적 함선을 명중시켜 격침시키는 것.
	//게임 진행 방식
	//	- 플레이어는 (x, y) 좌표를 입력해 공격한다.
	//	- 공격 결과(명중/실패)는 바로 표시되고, 플레이어의 맵에 기록된다.
	//	- 이미 공격한 좌표는 다시 공격할 수 없다.
	//함선 격침
	//	- 한 함선의 모든 칸을 명중시키면 "격침" 메시지가 출력된다.
	//게임 종료 조건
	//	- 모든 적 함선을 격침시키면 승리.
	//	- 주어진 횟수 내에 격침하지 못하면 패배하며, 패배 시 적 함선의 실제 위치가 공개된다.
	//추가 정보
	//	- 남은 공격 횟수와 남은 적 함선 수가 항상 안내된다.
*/

// 클래스 후보
//	- 적함선, 적함선관리, 맵, 게임 진행

