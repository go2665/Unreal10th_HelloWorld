#include <iostream>
#include "Day0526.h"

void Day0526()
{
	// 포인터
	// - 메모리 '주소'를 저장하는 변수
	// - 각 데이터 타입에 *(아스트리크)만 붙이면 포인터 타입이 된다.

	// IntergerAddress는 int 타입변수의 주소를 저장하는 변수다. 기본값으로 nullptr을 저장한다.
	int* IntergerAddress = nullptr;	// 인티저 포인터 IntergerAddress 선언하고 nullptr로 초기화하기
	float* pFloat = nullptr;		// 플롯 포인터 pFloat
	char* pTestString = nullptr;	// 캐릭터 포인터(문자열, string) pTestString

	// 포인터 연산자
	//	- & : 주소연산자. 변수 앞에 붙이면 그 변수의 주소를 돌려준다.
	//	- * : 간접참조연산자. 포인터 변수 앞에 붙이면 그 포인터 변수가 가리키는 주소에 있는 실제 값을 돌려준다.
	int Data = 10;
	IntergerAddress = &Data;		// Data라는 변수의 주소를 IntergerAddress에 저장해라.
	int Temp1 = *IntergerAddress;	// IntergerAddress가 가리키는 주소에 있는 실제값(Data의 값)을 Temp에 대입해라.
	int Temp2 = (*IntergerAddress) * 2;	// IntergerAddress가 가리키는 실제값을 두배시켜서 Temp2에 대입해라.

	// 상수와 포인터
	const int* ConstPointer = &Data;	// ConstPointer는 Data의 주소를 가리키는데 그 "값"을 변경하지 않겠다.
	ConstPointer = &Temp1;
	//(*ConstPointer) = 20;				// const int*에서 값을 변경하는 것은 문법 에러
	int* const ConstPointer2 = &Data;	// ConstPointer는 Data의 주소를 가리키는데 "주소"를 변경하지 않겠다.
	//ConstPointer2 = &Temp2;			// int* const에서 주소를 변경하는 것은 문법에러	

	//// const는 자기 왼쪽에 있는 것(왼쪽에 아무것도 없으면 오른쪽에 있는것)을 변경하지 않는 것
	//const int a = 10;	// 일반적으로 많이 사용
	//int const b = 20;	// 문법적으로는 문제 없으나 거의 사용 안함

	// +연산자와 -연산자
	//	- 포인터 타입의 값타입의 크기만큼 증가/감소한다.
	int* pData = &Data;	// Data의 주소가 0x10이라고 가정하면
	pData = pData + 1;	// +1한 결과는 0x14. int의 크기가 4byte라서.
	pData++;			// 0x18
	pData--;			// 0x14

	// 배열과 포인터
	int Array[5] = {1,2,3,4,5};
	int* pArray = Array;	// Array의 첫번째 요소의 주소를 pArray에 저장해라.
	//Array[1];	// 배열의 두번째 요소에 접근
	//pArray + 1;	// 포인터를 이용해서 두번째 요소에 접근

	// range-for : 배열이나 컨테이너의 첫 요소에서 마지막 요소까지 순차적으로 처리할 때 유용
	for (int Element : Array)
	{
		printf("%d ", Element);
	}
	printf("\n");

	// pArray를 이용해서 Array의 4번째 요소 출력하기
	printf("Array 4번째 요소 : %u\n", *(pArray + 3));
	Day0526_PointerParameter(Array, 5);

	// C++의 메모리 영역
	// - 코드 영역
	//		- 프로그램의 실행 코드가 저장되는 공간
	// - 데이터 영역
	//		- 프로그램이 시작할 때 부터 끝날 때까지 유지되는 변수가 저장되는 공간
	//		- 전역 변수, static 변수 등
	// - 스택 영역
	//		- 함수가 호출될 때마다 필요한 변수(지역변수)
	//		- 함수가 끝나면 자동으로 정리
	//		- 크기 제한이 있다.(윈도우에서 별다른 설정없으면 1MB)
	//		- 빠르다.
	// - 힙 영역
	//		- 프로그램 실행 중에 필요에 따라 직접 메모리를 할당하고 사용하는 공간
	//		- 반드시 할당을 하면 해제를 해줘야 한다.
	//		- 크기는 대략 RAM 크기와 같다.
	//		- 느리다.(상대적으로 스택에 비해)
	
	// 동적 할당(Dynamic Allocation)
	//	- 프로그램 실행 도중(Runtime)에 메모리를 사용하기 위해 확보하는 행위
	//	- 단점
	//		- 처리 속도가 느리다(= 자주하면 안된다.)
	//		- 메모리 단편화 문제가 발생할 수 있다.
	//	- C++ 방식
	//		- 장점 : 초기화 있음. 타입안정성 있음. 생성자/소멸자 호출됨.
	//		- new, delete

	int* Alloc = new int(5);	// int 크기로 동적할당을 받고 초기값으로 5를 설정한 다음 그 주소를 Alloc에 저장해라.

	*Alloc = 20;

	delete Alloc;				// 다썼으면 반드시 해제해야 한다. 메모리를 할당하고 해제하지 않으면 메모리 릭이 발생한다.
	Alloc = nullptr;			// 댕글링 포인터 방지를 위해 꼭 하는 것이 좋음.

	Alloc = new int[10] {0,};	// int 10개짜리 배열을 만들어라. 그리고 0으로 초기화 해라
	delete[] Alloc;				// 배열을 할당받은 것을 해제할 때는 delete[]를 써야 한다.
	Alloc = nullptr;

	int** Array2Dim = new int* [5];	// 세로 5
	for (int i = 0; i < 5; i++)
	{
		Array2Dim[i] = new int[10];	// 가로 10
	}
	for (int i = 0; i < 5; i++)
	{
		delete[] Array2Dim[i];
	}
	delete[] Array2Dim;


	int PracticeArray[] = { 5,2,74,4,15,7,3,1,52 };
	int PracticeSize = sizeof(PracticeArray) / sizeof(PracticeArray[0]);
	Day0526_PrintArray(PracticeArray, PracticeSize);

	Day0526_Practice1(&PracticeArray[1], &PracticeArray[2]);
	Day0526_PrintArray(PracticeArray, PracticeSize);

	Day0526_Practice2(PracticeArray, PracticeSize);
	Day0526_Practice3(PracticeArray, PracticeSize);
	Day0526_PrintArray(PracticeArray, PracticeSize);

}

// 배열을 파라메터로 넘길 때는 포인터를 주로 활용한다.
void Day0526_PointerParameter(int* Data, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		printf("%d ", *(Data + i));
	}
	printf("\n");
}

// 간단 실습
void Day0526_Practice1(int* Number1, int* Number2)
{
	// 1. 두 변수의 값을 변경하는 함수 만들기
	//		- int a, b; Swap(&a,&b);하면 a와 b의 값이 서로 바뀐다.
	int Temp = (*Number1);
	(*Number1) = (*Number2);
	(*Number2) = Temp;
}

void Day0526_Practice2(int* Array, int Size)
{
	// 2. 포인터를 이용해서 배열의 최대값 찾는 함수 만들기
	//		- 인덱스 사용 금지. (Array[i] 이런식의 사용 금지)
	int Max = INT32_MIN;
	for (int i = 0; i < Size; i++)
	{
		if (Max < *(Array + i))
		{
			Max = *(Array + i);
		}
	}
	printf("최대값은 %d입니다.\n", Max);
}

void Day0526_Practice3(int* Array, int Size)
{
	// 3. 포인터를 이용해서 배열의 순서를 뒤집는 함수 만들기
	//		- 인덱스 사용 금지
	int* Left = Array;					// 배열의 시작
	int* Right = Array + (Size - 1);	// 배열의 마지막

	while (Left < Right)	// 왼쪽과 오른쪽이 같아지거나 교차하기 전까지 반복
	{
		Day0526_Practice1(Left, Right);	// 스왑하기

		Left++;		// 오른쪽으로 한칸씩 이동
		Right--;	// 왼쪽으로 한칸씩 이동
	}
}

void Day0526_PrintArray(int* Array, int Size)
{
	printf("Array : [ ");
	for (int i = 0; i < Size; i++)
	{
		printf("%d ", *(Array + i));
	}
	printf("]\n");
}


