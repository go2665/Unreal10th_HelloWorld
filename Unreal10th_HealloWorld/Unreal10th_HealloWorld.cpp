// Unreal10th_HealloWorld.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>
#include <time.h>
//#include <random>

using namespace std;

int main()  // 코드의 시작점
{	
	/*
	주사위 게임
		초기 세팅
			플레이어와 컴퓨터 모두 일정 금액(예: 10000원)으로 시작한다.
		1차 주사위 굴리기
			게임 시작 시, 플레이어와 컴퓨터가 각각 주사위(1~6)를 한 번 굴린다.
			각자 주사위 결과를 공개한다.
		배팅
			이전 판에서 진 쪽이 배팅 금액을 제시한다.
			제시한 배팅 금액은 두 사람 모두의 현재 소지 금액 이하이어야 한다.
			배팅 금액은 두 사람 모두에게서 차감된다.
		2차 주사위 굴리기
			다시 플레이어와 컴퓨터가 각각 주사위를 한 번씩 굴린다.
			(1차+2차) 주사위의 합을 계산한다.
		승패 판정 및 금액 증감
			합이 더 큰 쪽이 배팅 금액의 총합(즉, 2×배팅금액)을 모두 가져간다.
			동점일 경우 배팅 금액은 그대로 반환한다.
		다음 판 진행
			소지금이 0 이하인 쪽이 나오면 게임 종료.
	*/

	const int InitialMoney = 10000;	// 게임 시작시 소유 금액		
	unsigned int Seed = (unsigned int)time(0);
	//Seed = 0;		// 테스트용으로 임시로 설정
	
	srand(Seed);	// 시드값 초기화

	int Turn = 1;					// 현재 턴
	bool PlayerLost = false;		// 이전판의 승자 기록용 bool. 플레이어가 졌으면 true, 플레이어가 이겼으면 false
	int Bet = 0;					// 현재 배팅 금액(한명분)
	int MaxBet = 0;					// 최대 배팅 금액
	int PlayerMoney = InitialMoney;	// 플레이어의 소유 금액
	int ComMoney = InitialMoney;	// 컴퓨터의 소유 금액

	while (PlayerMoney > 0 && ComMoney > 0)	// 한명이 돈이 남아 있는 한 반복
	{
		// 턴 상황 표시
		printf("\n---------- %d Turn ----------\n", Turn);
		printf("플레이어 금액 : %d\t/\t컴퓨터 금액 : %d\n", PlayerMoney, ComMoney);

		// 1차 주사위 굴리기
		const int DiceSize = 6;
		int PlayerDice1 = 0;			// 플레이어의 첫번째 주사위 값
		int ComDice1 = 0;				// 컴퓨터의 첫번째 주사위 값
		PlayerDice1 = rand() % DiceSize + 1;
		ComDice1 = rand() % DiceSize + 1;
		printf("플레이어 1차 주사위 : %d\n", PlayerDice1);
		printf("컴퓨터 1차 주사위   : %d\n", ComDice1);

		// 배팅
		//if (PlayerMoney < ComMoney)
		//{
		//	MaxBet = PlayerMoney;
		//}
		//else
		//{
		//	MaxBet = ComMoney;
		//}
		MaxBet = (PlayerMoney < ComMoney) ? PlayerMoney : ComMoney;	// 배팅금액의 최대치는 보유금액까지
		if (PlayerLost)
		{
			// 플레이어가 졌다. => 플레이어가 배팅
			do
			{
				printf("배팅 금액을 입력하세요(1~%d) : ", MaxBet);
				cin >> Bet;
			} while (Bet<1 || Bet > MaxBet);	// 범위를 벗어난 값이나 잘못 입력했을 때를 위해 다시 입력 받는 처리
		}
		else
		{
			// 플레이어가 이겼다 => 컴퓨터가 배팅
			Bet = rand() % MaxBet + 1;
			printf("컴퓨터가 배팅 금액으로 [%d]원을 지정했습니다.\n", Bet);
		}
		PlayerMoney -= Bet;	// 배팅 금액 차감
		ComMoney -= Bet;

		// 2차 주사위 굴리기
		int PlayerDice2 = 0;			// 플레이어의 두번째 주사위 값
		int ComDice2 = 0;				// 컴퓨터의 두번째 주사위 값
		PlayerDice2 = rand() % DiceSize + 1;
		ComDice2 = rand() % DiceSize + 1;
		printf("플레이어 2차 주사위 : %d\n", PlayerDice2);
		printf("컴퓨터 2차 주사위   : %d\n", ComDice2);
		int PlayerSum = PlayerDice1 + PlayerDice2;		// 합계 출력
		int ComSum = ComDice1 + ComDice2;
		printf("플레이어 주사위 합계 : %d\n", PlayerSum);
		printf("컴퓨터 주사위 합계   : %d\n", ComSum);

		// 승패 판정 및 금액 증감
		if (PlayerSum > ComSum)
		{
			printf("플레이어 승리! 당신이 [%d]원을 획득합니다.\n", Bet * 2);
			PlayerMoney += (Bet * 2);
			PlayerLost = false;
		}
		else if (ComSum > PlayerSum)
		{
			printf("컴퓨터 승리! 컴퓨터가 [%d]원을 획득합니다.\n", Bet * 2);
			ComMoney += (Bet * 2);
			PlayerLost = true;
		}
		else
		{
			printf("무승부입니다. 배팅 금액은 반환됩니다.");
			PlayerMoney += Bet;
			ComMoney += Bet;
		}

		// 턴 종료
		Turn++;
	}

	printf("\n------------ 게임 종료 ------------\n");
	if (PlayerMoney > 0)
	{
		printf("당신의 승리입니다.\n");
	}
	else
	{
		printf("컴퓨터의 승리입니다. 당신은 파산했습니다.\n");
	}

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


