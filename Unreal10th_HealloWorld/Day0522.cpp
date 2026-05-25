#include <iostream>
#include "Day0522.h"

void Day0522()
{
	//Day0522_Array();
	//Day0522_Array_Example01();
	//Day0522_Array_Example02();
	//Day0522_Array_Example03();

	//Day0522_Casting();
	//Day0522_Reference();

	//Day0522_ArrayParameter();

	Day0522_Shuffle();
}

void Day0522_Array()
{
	// 배열
	// 같은 종류의 데이터타입을 한번에 여러개 저장할 때 사용.
	// 같은 데이터 타입을 가진 요소들이 연속적으로 저장되어 있는 데이터 구조를 가진다.
	// 장점 : 빠르게 각 요소에 접근이 가능하다(랜덤 엑세스 성능이 매우 뛰어나다)
	// 단점 : 크기가 고정이다. 삽입/삭제가 힘들다.

	int Num1 = 0, Num2 = 0, Num3 = 0;	// 이전까지 데이터 3개 저장하는 방식
	int Numbers[3];			// 배열을 이용해서 데이터 3개 저장하는 방식
	Numbers[0] = 10;		// 배열의 각 요소에 접근하는 방식
	Numbers[1] = 20;
	Numbers[2] = 50;

	Numbers[1] = Numbers[0];	// Numbers의 첫번째 요소를 두번째 요소에 대입하기

	// Numbers[3] = 100;		// 범위를 벗어나서 접근하는 것은 안됨!!!

	int Array1[5] = { 1, 4, 76, 32, 6 };	// 순서대로 데이터 초기화
	int Array2[5] = { 32, 6 };				// 32, 6들어가고 나머지는 0

	int ArraySize = sizeof(Array1);
	printf("ArraySize : %d Byte\n", ArraySize);
	int ArrayCount = ArraySize / sizeof(int);
	printf("ArrayCount : %d 개\n", ArrayCount);

	// 2차원 배열
	int Array3[4][3] = { 0, };	// int 3개짜리 배열이 4개있다.
	int Array4[4][3] = { {1,2,3}, {4,5,6}, {7,8,9}, {10,11,12} };	// int Array4[12];와 메모리상 구조는 똑같다.

	// 간단 실습
	// 1. 배열 만들고 초기화 하고 전부 출력해보기(1차원과 2차원 모두)
	// 2. 배열 내부값을 모두 더하고 평균 구해보기
	// 3. 배열의 값 중 최대값과 최소값 구해보기
}

void Day0522_Array_Example01()
{
	// 1. 배열 만들고 초기화 하고 전부 출력해보기(1차원과 2차원 모두)
	int Array1[5] = { 1, 2, 3, 4, 5 };
	int Array1Size = sizeof(Array1) / sizeof(Array1[0]);
	printf("Array1 = [ ");
	for (int i = 0; i < Array1Size; i++)
	{
		printf("%d ", Array1[i]);
	}
	printf("]\n");

	const int Array2Size = 5;	// constexpr이 더 정확하다.
	int Array2[Array2Size] = { 0, };
	printf("Array2 = [ ");
	for (int i = 0; i < Array2Size; i++)
	{
		printf("%d ", Array2[i]);
	}
	printf("]\n");

	int Array3[3][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
	};

	printf("Array3 = [ \n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%3d ", Array3[i][j]);
		}
		printf("\n");
	}
	printf("]\n");
}

void Day0522_Array_Example02()
{
	// 2. 배열 내부값을 모두 더하고 평균 구해보기
	const int Size = 5;
	int Array[Size] = { 1,2,3,4,5 };
	int Sum = 0;
	printf("Array = { ");
	for (int i = 0; i < Size; i++)
	{
		printf("%d ", Array[i]);
		Sum += Array[i];
	}
	float Average = Sum / (float)Size;
	printf("}\n");
	printf("Sum = %d, Average = %.1f", Sum, Average);
}

void Day0522_Array_Example03()
{
	// 3. 배열의 값 중 최대값과 최소값 구해보기
	int Max = INT32_MIN;
	int Min = INT32_MAX;

	int Array[5] = { 0, -55, 99, 10, 53 };
	for (int i = 0; i < 5; i++)
	{
		if (Max < Array[i])
		{
			Max = Array[i];
		}
		if (Min > Array[i])
		{
			Min = Array[i];
		}
	}
	printf("Max = %d, Min = %d", Max, Min);
}

void Day0522_Casting()
{
	// 값의 데이터 타입을 다른 타입으로 임시 변경하는 것
	// C 스타일
	// - 강제 변환(위험함)
	int Integer = 10;
	float RealNumer = (float)Integer;	// Integer에 있는 값을 float타입으로 임시변경한 후 RealNumber에 저장

	bool Boolean = (bool)Integer;
	Boolean = (bool)0;

	int i = 0;

	// C++ 스타일
	// 1. static_cast
	//		- C스타일 cast와 매우 유사
	//		- 문법적으로 암시적 변환이 허용될 때만 캐스팅을 한다.
	RealNumer = static_cast<float>(Integer);
	// 2. dynamic_cast
	//		- 상속을 배워야 의미가 있음. 다운캐스팅을 할 때 사용.
	//		- 캐스팅 할 수 있으면 null이 아닌 값. 할 수 없으면 null을 반환.
	//		- RTTI(RunTime Type Information)를 관리
	//		- 변환 속도가 매우 늦다.(일반적인 게임에서 남용하면 안된다)
	//	캐스팅된 결과를 받을 변수 = dymanic_cast<캐스팅할 타입>(변수);
	// 3. const_cast
	//		- const나 volatile 속성을 제거하거나 추가할 때 사용.
	//		- 사용되지 않는 것이 권장(레거시 처리용)	// 
	// 4. reinterpret_cast
	//		- C스타일 캐스트의 위험한 부분을 그대로 가져온 것
	//		- 원래 타입의 구조를 무시하고 새 타입으로 강제적으로 해석하게 하는 cast
	//		- 포인터 타입간 변환이나 유니온 변환 같은 경우 사용
}

void Day0522_Reference()
{
	// 참조
	//  - 변수의 별명
	//	- 참조 대상을 재설정하는 것이 불가능하다.(선언할 때 참조할 변수를 지정해줘야 한다.)
	//	- 참조를 변경하면 참조하고 있던 원본 변수도 함께 수정된다.

	int Num = 10;
	int Target = Num;
	Target = 15;

	Test_Reference1(Num);
	Num = Test_Reference2(Num);

	int& NumRef = Num;
	int i = 0;
	//int& Ref;		// 참조할 변수 지정없이 사용하는건 안된다.
	NumRef = 100;	// 참조하고 있는 변수인 Num이 100이 된다.
	
	int Num1 = 0, Num2 = 0, Num3 = 0;
	Test_Reference3(Num1, Num2, Num3);
}

void Test_Reference1(int Data)
{
	Data += 10;
}

int Test_Reference2(int Data)
{
	return Data += 10;
}

void Test_Reference3(int& OutData1, int& OutData2, int& OutData3)
{
	OutData1 = 10;
	OutData2 = 20;
	OutData3 = 30;
}

void Day0522_ArrayParameter()
{
	const int Length = 5;
	int Array[Length] = { 10, 50, 30, 20, 40 };

	// 포인터(*)와 배열은 근본적으로 같다.
	Test_ArrayParameter(Array, Length);
}

void Test_ArrayParameter(int* Array, int Lenght)
{
	printf("Array : [ ");
	for (int i = 0; i < Lenght; i++)
	{
		printf("%d ", Array[i]);
	}
	printf("]\n");
}


void Day0522_Shuffle()
{
	const int DataSize = 100;
	int Data[DataSize] = { 0, };

	for (int i = 0; i < DataSize; i++)
	{
		Data[i] = i;
	}
	Test_ArrayParameter(Data, DataSize);

	FisherYatesShuffle(Data, DataSize);
	Test_ArrayParameter(Data, DataSize);
}

void FisherYatesShuffle(int* Array, int Lenght)
{
	// 1. 인덱스는 배열의 마지막 요소에서 첫번째 요소로 진행
	// 2. 인덱스가 가리키는 요소와 0~인덱스까지의 요소 중 임의의 요소를 선택
	// 3. 인덱스가 가리키는 요소와 임의로 선택된 요소를 교환
	// 4. 인덱스는 1 감소
	// 5. 인덱스가 0이되면 종료

	for (int i = Lenght - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);

		int Temp = Array[i];
		Array[i] = Array[j];
		Array[j] = Temp;
	}
}

	// 간단 실습
	// 1. 배열의 값들을 전부 출력해주는 함수 만들기
	// 2. 배열을 파라메터로 받는 함수를 만들어 구현하기
	//	  - 배열 내부값을 모두 더하고 평균 구해보기
	//    - 배열의 값 중 최대값과 최소값 구해보기
	// 3. 피셔 예이츠 알고리즘 완성하기