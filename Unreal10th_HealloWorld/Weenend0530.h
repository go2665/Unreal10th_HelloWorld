#pragma once

void Homework0530_01_Run();	// 요일 구하기
bool IsLeap(int InYear);
int GetTotalDay(int InYear, int InMonth, int InDay);
const char* GetDayOfWeek(int InYear, int InMonth, int InDay);

enum Suit
{
	Spade,
	Heart,
	Diamond,
	Clover,
	NUM_OF_SUIT
};

enum CardValue
{
	CardA = 0,
	Card2,
	Card3,
	Card4,
	Card5,
	Card6,
	Card7,
	Card8,
	Card9,
	Card10,
	CardJ,
	CardQ,
	CardK,
	NUM_OF_CARD_VALUE
};

struct Card
{
	Suit Suit;	
	CardValue Value;	
};

const int MaxDeckSize = NUM_OF_SUIT * NUM_OF_CARD_VALUE;

const int MaxHand = 12;
const int DealerStop = 17;

void PrintCard(const Card& InCard);
void InitializeDeck(Card* InDeck);
void ShuffleDeck(Card* InDeck);

Card DrawCard(Card* InDeck, int& InOutTop);
void AddCardToHand(Card* InHand, int& InCount, Card InCard);

void PrintPlayerHand(Card* InHand, int InCount);
void PrintDealerHand(Card* InHand, int InCount, bool InRevealHole);
void PrintHandState(Card* InPlayerHand, int InPlayerCount, Card* InDealerHand, int InDealerCount, bool InRevealHole);

bool IsBlackjack(Card* InHand, int InCount);
int GetCardScore(Card& InCard);

int GetBestScore(Card* InHand, int InCount);
bool IsBurst(Card* InHand, int InCount);
bool IsSoft17(Card* InHand, int InCount);

void Homework0530_02_Run();	// 블랙잭