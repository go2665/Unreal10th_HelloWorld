#include <iostream>
#include "Weenend0530.h"

// 윤년 확인 함수
bool IsLeap(int InYear)
{
	return (InYear % 4 == 0 && InYear % 100 != 0) || (InYear % 400 == 0);
}

// 총 몇일이 걸리는지 리턴하는 함수
int GetTotalDay(int InYear, int InMonth, int InDay)
{
	const int DaysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	int Days = 0;
	for (int Y = 1; Y < InYear; Y++)
	{
		Days += IsLeap(Y) ? 366 : 365;
	}
	for (int M = 1; M < InMonth; M++)
	{
		if (M == 2 && IsLeap(InYear))
		{
			Days += 29;
		}
		else
		{
			Days += DaysInMonth[M - 1];
		}
	}
	Days += (InDay - 1);
	return Days;
}

const char* GetDayOfWeek(int InYear, int InMonth, int InDay)
{
	const char* Week[7] = { "월요일", "화요일" , "수요일" , "목요일" , "금요일" , "토요일" , "일요일" };
	int Days = GetTotalDay(InYear, InMonth, InDay);
	return Week[Days % 7];
}

void Homework0530_01_Run()
{
	// 요일을 7개가 반복된다. (%7 사용)
	// 1년 1월 1일에서 몇일이 지났는지 확인해야한다.
	// 윤년에 대한 처리가 필요하다.

	int Year, Month, Day;
	printf("날짜를 입력하세요 (예 : 2026 5 29) : ");
	std::cin >> Year >> Month >> Day;
	printf("%d년 %d월 %d일은 [%s]입니다.\n", Year, Month, Day, GetDayOfWeek(Year, Month, Day));
}

void PrintCard(const Card& InCard)
{
	const char* ValueString[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	const char* SuitString[4] = { "♠", "♡", "◇", "♣" };
	printf("[%s%s] ", SuitString[InCard.Suit], ValueString[InCard.Value]);
}

void InitializeDeck(Card* InDeck)
{
	int Index = 0;
	for (int suit = 0; suit < NUM_OF_SUIT; suit++)
	{
		for (int value = 0; value < NUM_OF_CARD_VALUE; value++)
		{
			InDeck[Index] = { static_cast<Suit>(suit), static_cast<CardValue>(value) };
			Index++;
		}
	}
}

void ShuffleDeck(Card* InDeck)
{
	int Start = MaxDeckSize - 1;
	for (int i = Start; i > 0; i--)
	{
		int j = rand() % (i + 1);

		Card Temp = InDeck[i];
		InDeck[i] = InDeck[j];
		InDeck[j] = Temp;
	}
}

Card DrawCard(Card* InDeck, int& InOutTop)
{
	if (InOutTop >= MaxDeckSize)
	{
		ShuffleDeck(InDeck);
		InOutTop = 0;
	}
	return InDeck[InOutTop++];	// 카드를 리턴하고 Top을 증가시킴
}

void AddCardToHand(Card* InHand, int& InCount, Card InCard)
{
	if (InCount < MaxHand)
	{
		InHand[InCount] = InCard;
		InCount++;
	}
}

void PrintPlayerHand(Card* InHand, int InCount)
{
	for (int i = 0; i < InCount; i++)
	{
		PrintCard(InHand[i]);
	}
}

void PrintDealerHand(Card* InHand, int InCount, bool InRevealHole)
{
	for (int i = 0; i < InCount; i++)
	{
		if (i == 1 && InRevealHole)
		{
			printf("[??] ");
		}
		else
		{
			PrintCard(InHand[i]);
		}
	}
}

void PrintHandState(Card* InPlayerHand, int InPlayerCount, Card* InDealerHand, int InDealerCount, bool InRevealHole)
{
	printf("플레이어 카드\t: ");
	PrintPlayerHand(InPlayerHand, InPlayerCount);
	printf("\n딜러 카드\t: ");
	PrintDealerHand(InDealerHand, InDealerCount, InRevealHole);
	printf("\n");
}

bool IsBlackjack(Card* InHand, int InCount)
{
	if(InCount == 2)
	{
		bool HasAce = InHand[0].Value == CardA || InHand[1].Value == CardA;
		bool HasTen = GetCardScore(InHand[0]) == 10 || GetCardScore(InHand[1]) == 10;
		return HasAce && HasTen;
	}
	return false;
}

int GetCardScore(Card& InCard)
{
	int Value = 0;
	if (InCard.Value < CardJ)
	{
		Value = static_cast<int>(InCard.Value) + 1;
	}
	else
	{
		Value = 10;
	}
	return Value;
}

int GetBestScore(Card* InHand, int InCount)
{
	int Sum = 0;
	int AceCount = 0;
	for (int i = 0; i < InCount; i++)
	{
		Sum += GetCardScore(InHand[i]);
		if (InHand[i].Value == CardA)
		{
			AceCount++;
		}
	}

	while (AceCount > 0 && (Sum + 10) <= 21)	// Ace카드가 남아있고 Burst가 안날 때까지 반복
	{
		Sum += 10;
		AceCount--;
	}

	return Sum;
}

bool IsBurst(Card* InHand, int InCount)
{
	return GetBestScore(InHand, InCount) > 21;
}

bool IsSoft17(Card* InHand, int InCount)
{
	if (GetBestScore(InHand, InCount) >= 17)
	{
		for (int i = 0; i < InCount; i++)
		{
			if (InHand[i].Value == CardA)
			{
				return true;
			}
		}
	}
	return false;
}

void Homework0530_02_Run()
{
	//PrintCard(Card{ Spade, Card2 });
	Card Deck[MaxDeckSize];		// 전체 카드 덱
	int DeckTop = 0;								// 덱의 현재 인덱스를 가리키는 변수

	InitializeDeck(Deck);	// 카드 초기화
	ShuffleDeck(Deck);		// 덱 섞기

	Card PlayerHand[MaxHand];
	int PlayerCardCount = 0;
	Card DealerHand[MaxHand];
	int DealerCardCount = 0;

	AddCardToHand(PlayerHand, PlayerCardCount, DrawCard(Deck, DeckTop));	// 플레이어에게 한장
	AddCardToHand(DealerHand, DealerCardCount, DrawCard(Deck, DeckTop));	// 딜러에게 한장
	AddCardToHand(PlayerHand, PlayerCardCount, DrawCard(Deck, DeckTop));	// 플레이어에게 한장
	AddCardToHand(DealerHand, DealerCardCount, DrawCard(Deck, DeckTop));	// 딜러에게 한장

	//PlayerHand[0].Value = CardA;
	//PlayerHand[1].Value = CardK;
	//DealerHand[0].Value = CardA;
	//DealerHand[1].Value = CardK;

	// 각자의 핸드 출력
	PrintHandState(PlayerHand, PlayerCardCount, DealerHand, DealerCardCount, true);

	// 플레이어와 딜러가 블랙잭인지 확인
	if (IsBlackjack(PlayerHand, PlayerCardCount))
	{
		if (IsBlackjack(DealerHand, DealerCardCount))
		{
			// 둘 다 블랙잭이다.
			printf("둘 다 블랙잭! 무승부!\n");
			PrintHandState(PlayerHand, PlayerCardCount, DealerHand, DealerCardCount, false);
			return;
		}
		else
		{
			// 플레이어만 블랙잭이다.
			printf("플레이어 블랙잭 승리!\n");
			PrintHandState(PlayerHand, PlayerCardCount, DealerHand, DealerCardCount, false);
			return;
		}
	}
	else if(IsBlackjack(DealerHand, DealerCardCount))
	{
		// 딜러만 블랙잭이다.
		printf("딜러 블랙잭 승리!\n");
		PrintHandState(PlayerHand, PlayerCardCount, DealerHand, DealerCardCount, false);
		return;
	}
	// 둘 다 블랙잭이 아니다.

	bool PlayerStand = false;
	bool DealerStand = false;
	while ( !PlayerStand && !DealerStand )
	{
		// 플레이어 턴
		printf("플레이어의 차례...\n");
		printf("플레이어 점수: %d\n", GetBestScore(PlayerHand, PlayerCardCount));
		printf("Hit(1) / Stand(2)? 입력 :");
		int Choice = 0;
		std::cin >> Choice;
		if (Choice == 1)
		{
			AddCardToHand(PlayerHand, PlayerCardCount, DrawCard(Deck, DeckTop));
			PrintHandState(PlayerHand, PlayerCardCount, DealerHand, DealerCardCount, true);
			if (IsBurst(PlayerHand, PlayerCardCount))
			{
				printf("플레이어 버스트! 당신의 패배!\n");
				PrintHandState(PlayerHand, PlayerCardCount, DealerHand, DealerCardCount, false);
				return;
			}
		}
		else
		{
			PlayerStand = true;
		}

		// 딜러 턴
		printf("딜러의 차례...\n");
		PrintHandState(PlayerHand, PlayerCardCount, DealerHand, DealerCardCount, true);
		if (GetBestScore(DealerHand, DealerCardCount) < DealerStop)
		{
			printf("딜러가 한장 더 받기로 합니다.\n");
			AddCardToHand(DealerHand, DealerCardCount, DrawCard(Deck, DeckTop));
			PrintHandState(PlayerHand, PlayerCardCount, DealerHand, DealerCardCount, true);
			if (IsBurst(DealerHand, DealerCardCount))
			{
				printf("딜러 버스트! 당신의 승리!\n");
				PrintHandState(PlayerHand, PlayerCardCount, DealerHand, DealerCardCount, false);
				return;
			}
		}
		else
		{
			printf("딜러가 스탠드를 선언합니다.\n");
			PrintHandState(PlayerHand, PlayerCardCount, DealerHand, DealerCardCount, false);
			DealerStand = true;
		}
	}

	if (PlayerStand && !DealerStand)
	{
		printf("딜러가 남은 처리를 계속합니다.......\n");
		// 플레이어만 스탠드(딜러는 17이 되기 전까지 계속 받는다)
		while (GetBestScore(DealerHand, DealerCardCount) < DealerStop)
		{
			AddCardToHand(DealerHand, DealerCardCount, DrawCard(Deck, DeckTop));
			PrintDealerHand(DealerHand, DealerCardCount, false);
			printf("\n");
			if (IsBurst(DealerHand, DealerCardCount))
			{
				printf("딜러 버스트! 당신의 승리!\n");
				PrintHandState(PlayerHand, PlayerCardCount, DealerHand, DealerCardCount, false);
				return;
			}
		}		
	}
	if(!PlayerStand && DealerStand)
	{
		printf("플레이어가 남은 처리를 계속합니다.......\n");
		// 딜러만 스탠드(플레이어는 계속 선택하며 받을 수 있다.)
		while (!PlayerStand)
		{
			printf("플레이어 점수: %d\n", GetBestScore(PlayerHand, PlayerCardCount));
			printf("Hit(1) / Stand(2)? 입력 :");
			int Choice = 0;
			std::cin >> Choice;
			if (Choice == 1)
			{
				AddCardToHand(PlayerHand, PlayerCardCount, DrawCard(Deck, DeckTop));
				PrintHandState(PlayerHand, PlayerCardCount, DealerHand, DealerCardCount, true);
				if (IsBurst(PlayerHand, PlayerCardCount))
				{
					printf("플레이어 버스트! 당신의 패배!\n");
					PrintHandState(PlayerHand, PlayerCardCount, DealerHand, DealerCardCount, false);
					return;
				}
			}
			else
			{
				PlayerStand = true;
			}
		}
	}	
	
	// 점수 계산하기
	int PlayerScore = GetBestScore(PlayerHand, PlayerCardCount);
	int DealerScore = GetBestScore(DealerHand, DealerCardCount);
	printf("플레이어 점수 : %d, 딜러 점수 : %d\n", PlayerScore, DealerScore);
	if (PlayerScore > DealerScore)
	{
		printf("플레이어의 승리!\n");
	}
	else if (PlayerScore < DealerScore)
	{
		printf("딜러의 승리!\n");
	}
	else
	{
		printf("무승부!\n");
	}


	/*
	* 블랙잭 만들기
		게임 목표
			두 카드의 합이 21에 가깝게 만들되, 21을 넘지 않는 것이 목표
			21을 초과하면(버스트, Bust)  즉시 패배
			배팅은 없음
		카드의 값
			2~10: 카드 숫자 그대로 점수.
			J(잭), Q(퀸), K(킹): 각각 10점.
			A(에이스): 1점 또는 11점(유리한 쪽으로 자동 선택).
		게임 진행 절차
			초기 배분
				딜러와 플레이어 모두 2장씩 카드를 받음.
				플레이어의 카드는 두 장 모두 공개.
				딜러는 한 장은 공개(오픈 카드), 한 장은 비공개(홀 카드).
			플레이어 턴
				플레이어가 먼저 행동.
				선택지:
					Hit(히트): 카드를 한 장 더 받음.
					Stand(스탠드): 더 이상 카드를 받지 않고 멈춤.
				플레이어가 21을 초과하면(버스트) 즉시 패배.
			딜러 턴
				플레이어가 스탠드를 하면 딜러 차례.
				딜러는 자신의 카드 합이 17 이상이 될 때까지 계속 히트(카드 받기)해야 함.
					A가 포함된 "소프트 17"(A+6=7 또는 17)도 멈춤.
				17 이상이면 멈추고, 21을 넘으면 딜러 패배.
		승패 판정
			버스트가 아닌 경우, 점수 비교.
				플레이어가 21에 더 가까우면 승리.
				동점이면 무승부(Push).
				딜러가 더 가까우면 패배.
			블랙잭: 처음 받은 두 장이 A + 10(또는 J, Q, K)이면 블랙잭. 일반적으로 블랙잭이 단순 21점보다 우선함.
	*/
}
