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

void Homework0530_02_Run()
{
}
