#include <stdio.h>
#include "Day0521_2.h"

int Add(int Num1, int Num2)
{
	int Result = Num1 + Num2;

	return Result;
}

int Sub(int Num1, int Num2)
{
	int Result = Num1 - Num2;
	return Result;
}

int Mul(int Num1, int Num2)
{
	int Result = Num1 * Num2;
	return Result;
}

int Div(int Num1, int Num2)
{
	int Result = 0;
	if (Num2 != 0)	// 0으로 나누어 지는 것 방지
	{
		Result = Num1 / Num2;		
	}

	return Result;	
}

void Test()
{
	printf("Hello World!\n");
	// return;	// 리턴값이 void인데 중간에 함수를 종료하고 싶을 때
}

float Add(float Num1, float Num2)
{
	float Result = Num1 + Num2;
	return Result;
}
