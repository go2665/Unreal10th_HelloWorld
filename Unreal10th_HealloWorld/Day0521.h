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


// 주사위 게임-----------------------------
//	/*
//	주사위 게임
//		초기 세팅
//			플레이어와 컴퓨터 모두 일정 금액(예: 10000원)으로 시작한다.
//		1차 주사위 굴리기
//			게임 시작 시, 플레이어와 컴퓨터가 각각 주사위(1~6)를 한 번 굴린다.
//			각자 주사위 결과를 공개한다.
//		배팅
//			이전 판에서 진 쪽이 배팅 금액을 제시한다.
//			제시한 배팅 금액은 두 사람 모두의 현재 소지 금액 이하이어야 한다.
//			배팅 금액은 두 사람 모두에게서 차감된다.
//		2차 주사위 굴리기
//			다시 플레이어와 컴퓨터가 각각 주사위를 한 번씩 굴린다.
//			(1차+2차) 주사위의 합을 계산한다.
//		승패 판정 및 금액 증감
//			합이 더 큰 쪽이 배팅 금액의 총합(즉, 2×배팅금액)을 모두 가져간다.
//			동점일 경우 배팅 금액은 그대로 반환한다.
//		다음 판 진행
//			소지금이 0 이하인 쪽이 나오면 게임 종료.
//	*/
//
//const int InitialMoney = 10000;	// 게임 시작시 소유 금액		
//unsigned int Seed = (unsigned int)time(0);
////Seed = 0;		// 테스트용으로 임시로 설정
//
//srand(Seed);	// 시드값 초기화
//
//int Turn = 1;					// 현재 턴
//bool PlayerLost = false;		// 이전판의 승자 기록용 bool. 플레이어가 졌으면 true, 플레이어가 이겼으면 false
//int Bet = 0;					// 현재 배팅 금액(한명분)
//int MaxBet = 0;					// 최대 배팅 금액
//int PlayerMoney = InitialMoney;	// 플레이어의 소유 금액
//int ComMoney = InitialMoney;	// 컴퓨터의 소유 금액
//
//while (PlayerMoney > 0 && ComMoney > 0)	// 한명이 돈이 남아 있는 한 반복
//{
//	// 턴 상황 표시
//	printf("\n---------- %d Turn ----------\n", Turn);
//	printf("플레이어 금액 : %d\t/\t컴퓨터 금액 : %d\n", PlayerMoney, ComMoney);
//
//	// 1차 주사위 굴리기
//	const int DiceSize = 6;
//	int PlayerDice1 = 0;			// 플레이어의 첫번째 주사위 값
//	int ComDice1 = 0;				// 컴퓨터의 첫번째 주사위 값
//	PlayerDice1 = rand() % DiceSize + 1;
//	ComDice1 = rand() % DiceSize + 1;
//	printf("플레이어 1차 주사위 : %d\n", PlayerDice1);
//	printf("컴퓨터 1차 주사위   : %d\n", ComDice1);
//
//	// 배팅
//	//if (PlayerMoney < ComMoney)
//	//{
//	//	MaxBet = PlayerMoney;
//	//}
//	//else
//	//{
//	//	MaxBet = ComMoney;
//	//}
//	MaxBet = (PlayerMoney < ComMoney) ? PlayerMoney : ComMoney;	// 배팅금액의 최대치는 보유금액까지
//	if (PlayerLost)
//	{
//		// 플레이어가 졌다. => 플레이어가 배팅
//		do
//		{
//			printf("배팅 금액을 입력하세요(1~%d) : ", MaxBet);
//			cin >> Bet;
//			cin.clear();					// 에러 상태 해제
//			cin.ignore(10000, '\n');		// 이전 입력 제거
//		} while (Bet<1 || Bet > MaxBet);	// 범위를 벗어난 값이나 잘못 입력했을 때를 위해 다시 입력 받는 처리
//	}
//	else
//	{
//		// 플레이어가 이겼다 => 컴퓨터가 배팅
//		Bet = rand() % MaxBet + 1;
//		printf("컴퓨터가 배팅 금액으로 [%d]원을 지정했습니다.\n", Bet);
//	}
//	PlayerMoney -= Bet;	// 배팅 금액 차감
//	ComMoney -= Bet;
//
//	// 2차 주사위 굴리기
//	int PlayerDice2 = 0;			// 플레이어의 두번째 주사위 값
//	int ComDice2 = 0;				// 컴퓨터의 두번째 주사위 값
//	PlayerDice2 = rand() % DiceSize + 1;
//	ComDice2 = rand() % DiceSize + 1;
//	printf("플레이어 2차 주사위 : %d\n", PlayerDice2);
//	printf("컴퓨터 2차 주사위   : %d\n", ComDice2);
//	int PlayerSum = PlayerDice1 + PlayerDice2;		// 합계 출력
//	int ComSum = ComDice1 + ComDice2;
//	printf("플레이어 주사위 합계 : %d\n", PlayerSum);
//	printf("컴퓨터 주사위 합계   : %d\n", ComSum);
//
//	// 승패 판정 및 금액 증감
//	if (PlayerSum > ComSum)
//	{
//		printf("플레이어 승리! 당신이 [%d]원을 획득합니다.\n", Bet * 2);
//		PlayerMoney += (Bet * 2);
//		PlayerLost = false;
//	}
//	else if (ComSum > PlayerSum)
//	{
//		printf("컴퓨터 승리! 컴퓨터가 [%d]원을 획득합니다.\n", Bet * 2);
//		ComMoney += (Bet * 2);
//		PlayerLost = true;
//	}
//	else
//	{
//		printf("무승부입니다. 배팅 금액은 반환됩니다.");
//		PlayerMoney += Bet;
//		ComMoney += Bet;
//	}
//
//	// 턴 종료
//	Turn++;
//}
//
//printf("\n------------ 게임 종료 ------------\n");
//if (PlayerMoney > 0)
//{
//	printf("당신의 승리입니다.\n");
//}
//else
//{
//	printf("컴퓨터의 승리입니다. 당신은 파산했습니다.\n");
//}


// 홀짝 게임 ------------------------------------
//	/*
//	* 홀짝 게임
//		초기 금액 및 배팅
//			플레이어는 기본금 100원으로 베팅을 시작한다.
//		홀짝 선택
//			플레이어가 1(홀) 또는 2(짝)을 선택한다.
//		결과 결정
//			컴퓨터가 랜덤으로 1(홀) 또는 2(짝)을 선택한다.
//			플레이어의 선택과 결과가 일치하면 승리(이기면 배팅금의 2배 획득), 다르면 패배(배팅금 전액 잃음).
//		연속 배팅 선택
//			승리 시 플레이어는 두 가지 중 하나를 선택:
//				(A) 이긴 금액을 모두 다시 한 번에 배팅 (연승 도전)
//				(B) 이긴 금액을 얻고, 다시 100원부터 새로 배팅 시작
//		게임 종료 조건
//			플레이어가 소지금이 100원 미만일 경우 게임 종료.
//	*/
//
//const int InitialMoney = 10000;	// 게임 시작할 때 플레이어의 돈
//const int MinimumBet = 100;		// 최소 배팅 금액
//const int WinMultiplier = 2;	// 이겼을 때 배율
//
//int Money = InitialMoney;		// 플레이어의 현재 돈
//int CurrentBat = MinimumBet;	// 현재 배팅 금액
//
//unsigned int Seed = (unsigned int)time(0);
//Seed = 0;		// 테스트용으로 임시로 설정
//
//srand(Seed);	// 시드값 초기화
//
//while (Money >= 100)	// 게임 종료 조건 : 플레이어가 소지금이 100원 미만일 경우 게임 종료.
//{
//	// 배팅
//	// 플레이어는 기본금 100원으로 베팅을 시작한다.
//	printf("\n현재 소지금 : [%d]원\n", Money);
//	printf("현재 배팅 금액 : [%d]원\n", CurrentBat);
//	Money -= CurrentBat;	// 배팅 금액만큼 감소
//
//	// 홀짝 선택
//	//	플레이어가 1(홀)또는 2(짝)을 선택한다.
//	int Select = 0;
//	while (Select != 1 && Select != 2)	// 잘못된 입력 방지
//	{
//		printf("홀(1) 또는 짝(2)을 선택하세요 : ");
//		cin >> Select;					// 입력 받고
//		cin.clear();					// 잘못된 입력일 때 에러 리셋
//		cin.ignore(10000, '\n');		// 버퍼 비우기
//	}
//
//	// 결과 결정
//	//	컴퓨터가 랜덤으로 1(홀)또는 2(짝)을 선택한다.
//	//	플레이어의 선택과 결과가 일치하면 승리(이기면 배팅금의 2배 획득), 다르면 패배(배팅금 전액 잃음).
//	int Result = rand() % 2 + 1;	// 랜덤으로 1 or 2 고르기
//	printf("결과는 [%s]입니다.\n", (Result == 1) ? "홀" : "짝");
//	if (Select == Result)
//	{
//		int WinPrice = CurrentBat * WinMultiplier;	// 승리 상금은 현재 배팅금액의 두배
//		printf("축하합니다! [%d]원을 획득할 수 있습니다.\n", WinPrice);
//		printf("1) [%d]원을 모두 다시 배팅\n", WinPrice);
//		printf("2) [%d]원을 받고 다시 [%d]원부터 배팅\n", WinPrice, MinimumBet);
//		printf("1 또는 2 중 하나를 선택하세요 : ");
//		int KeepGoing = 0;
//		while (KeepGoing != 1 && KeepGoing != 2)	// 선택지 입력받기
//		{
//			cin >> KeepGoing;
//			cin.clear();
//			cin.ignore(10000, '\n');
//		}
//		if (KeepGoing == 1)
//		{
//			CurrentBat = WinPrice;		// 상금을 다시 그대로 배팅
//		}
//		else
//		{
//			Money += WinPrice;			// 상금을 받고
//			CurrentBat = MinimumBet;	// 100원부터 다시 배팅
//		}
//	}
//	else
//	{
//		printf("안타깝네요! 배팅한 [%d]원을 모두 잃었습니다.\n", CurrentBat);
//		CurrentBat = MinimumBet;	// 배팅 금액 초기화
//	}
//}
//
//printf("소지금이 부족해서 더 이상 진행할 수 없습니다.\n");


//// 함수 ---------------------------------------------------------------
//	// - 특정 기능을 수행하는 코드 뭉치
//
//	// 선언부
//	//	- 이런 함수가 있다고 알리는 것
//	//  - 프로토타입 제시.(이름, 리턴타입, 파라메터)
//	//  - 함수의 실제 동작이 어떻게 되는지에 대한 내용은 없음
//	//  - h(헤더)에 선언한다.
//	// 정의부
//	//  - 함수의 실제 동작을 작성하는 부분
//	//	- {} 사이에 실제 실행할 코드를 작성.(함수 바디)
//	//	- cpp파일에 작성한다.
//
//	// 함수의 구성요소
//	// 1. 리턴 타입
//	//	- 함수가 실행이 끝났을 때 돌려주는 결과값.
//	// 2. 함수 이름
//	//	- 함수들을 구분하기 위해 붙이는 이름
//	//	- 함수를 호출(Call)할 때 사용.
//	// 3. 파라메터
//	//	- 함수를 호출할 때 전달하는 값
//	//	- 매개변수, 인자라고도 함.
//	//	- 0개 이상 가능
//	//	- 데이터 타입과 이름으로 구성
//	// 4. 함수 바디
//	//	- 함수의 실제 실행 코드
//	//	- 종료할 때 return이 있어야 한다.
//
//int Sum = Add(10, 20);
//printf("Sum = %d\n", Sum);
//
//double A = 30.0;
//double B = 15.5;
//double C = Add(A, B);
//
//string str1 = "Hello ";
//string str2 = "World!";
//string str3 = Add(str1, str2);

// 함수--------------------------------------------------------------------------------
//StateChangeRun();	// 실습 1번 실행용
//DiceGameRun();		// 실습 2번 실행용