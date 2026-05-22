// Unreal10th_HealloWorld.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>
#include <time.h>
//#include <random>
#include "Day0521_2.h"
#include "Practice0521_1.h"
#include "Practice0521_2.h"

using namespace std;

int main()  // 코드의 시작점
{	
	unsigned int Seed = (unsigned int)time(0);
	Seed = 0;		// 테스트용으로 임시로 설정
	srand(Seed);	// 시드값 초기화

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
	int Array3[4][3];	// int 3개짜리 배열이 4개있다.
	int Array4[4][3] = { {1,2,3}, {4,5,6}, {7,8,9}, {10,11,12} };	// int Array4[12];와 메모리상 구조는 똑같다.
	
	// 간단 실습
	// 1. 배열 만들고 초기화 하고 전부 출력해보기(1차원과 2차원 모두)
	// 2. 배열 내부값을 모두 더하고 평균 구해보기
	// 3. 배열의 값 중 최대값과 최소값 구해보기
	
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


