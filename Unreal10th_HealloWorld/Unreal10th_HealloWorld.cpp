// Unreal10th_HealloWorld.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int main()  // 코드의 시작점
{
	// 이진수
	// - 0과 1로만 표현되는 숫자
	//	- ex) int i = 8;	// 메모리 : 0000 0000 0000 0000 0000 0000 0000 1000

	// float(부동소수점)
	// - 32bit
	// - 소수점이 있는 숫자를 저장한다.
	// - 구조적으로 오차가 있는 데이터 타입. 같다는 비교를 조심해서 해야한다.
	// - 숫자 뒤에 f를 붙여야 한다.

	// double(부동소수점)
	// - 64bit

	float RealNumber = 0.0f;	// 0.0f는 float
	//RealNumber = 0.1;			// 0.1는 double -> 암시적 변환이 일어나 float으로 저장됨 -> 워닝 발생
	RealNumber = (float)0.1;	// 명시적 변환, Casting

	printf("이것은 실수입니다 : %f\n", RealNumber);

	RealNumber = 0.1f + 0.5f;
	printf("이것은 실수입니다 : %.2f\n", RealNumber);	// 소수점 아래 둘째자리까지 출력
	RealNumber -= 0.2f;
	printf("이것은 실수입니다 : %8.2f\n", RealNumber);	// 소수점 포함 전체 8자리, 소수점 아래 둘째자리까지 출력
	printf("float타입의 사이즈는 [%d]byte입니다.\n\n", (int)(sizeof(float)));

	// bool(불리언 타입)
	// - true, false 이 둘만 저장하는 데이터 타입
	// - 프로그램의 각종 분기를 결정할 때 사용
	// - 8bit
	bool bTest = false;
	bTest = true;
	printf("bool타입의 사이즈는 [%d]byte입니다.\n", (int)(sizeof(bool)));

	// char(캐릭터 타입)
	// - 글자 하나를 저장하는 데이터 타입
	// - 8bit짜리 정수형 데이터 타입
	char TestCharacter = 'a'; 
	TestCharacter = 'b';
	TestCharacter = 'B';

	printf("char c = %c\n", TestCharacter);
	
	// 문자열
	// - char*, std::string 
	std::string TestString = "Hello World!\n";

	// 부호없는 인티저(32bit, 숫자 범위 0~42억)
	unsigned int TestInteger = 0;

	// 64bit 인티저
	long long TestInteger64 = 0;
	unsigned long long TestInteger64_2 = 0;

	// 유니코드 캐릭터
	wchar_t UnicodeChar = L'가';

	int Size = 100;
	printf("\n한변이 %d인 정사각형의 넓이는 %d입니다.\n", Size, Size * Size);
	Size = 50000;
	printf("한변이 %d인 정사각형의 넓이는 %u입니다.\n", Size, (unsigned int)Size * (unsigned int)Size);

	// 간단 실습
	// 1. 원의 반지름 입력 받고 넓이 구하기
	// 2. 3개의 값을 입력 받고 평균값 구하기
	// 3. 정가와 할인율을 입력받고 할인된 가격 구하기

	// 상수
	// - 절대 변하지 않는 숫자
	// - 코드의 안정성과 가독성을 높여준다.
	const int TestConst = 10;
	// TestConst = 20;	// 컴파일 에러
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
