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
// 1. 두 변수의 값을 변경하는 함수 만들기
//		- int a, b; Swap(a,b);하면 a와 b의 값이 서로 바뀐다.
// 2. 포인터를 이용해서 배열의 최대값 찾는 함수 만들기
//		- 인덱스 사용 금지. (Array[i] 이런식의 사용 금지)
// 3. 포인터를 이용해서 배열의 순서를 뒤집는 함수 만들기
//		- 인덱스 사용 금지