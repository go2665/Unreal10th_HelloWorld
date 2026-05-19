#pragma once
//printf("Hello World!\n");
//int number = 0;
////int size = scanf("%d", &number);	// C 스타일의 표준 입력 방식(위험하다)
//std::cin >> number;	// C++ 스타일의 표준 입력 방식
//printf("Input number is %d", number);

//printf("나이를 입력하세요 : ");
//int Age = 0;		// Age라는 int 변수를 선언했다.
//std::cin >> Age;
//printf("당신의 나이는 [%d]살입니다.\n", Age);

// 변수(Variable)
// - 변하는 숫자
// - 컴퓨터에 값을 기억시키기 위해 만들고 사용한다.
// - 메모리의 일정 공간을 확보하고 이름을 붙여 사용하는 것.
// - ex) 데이터타입 변수명; int age;

// int(인티저, Integer)
// - 정수형 타입
// - 정수는 소수점이 없는 숫자
// - 일반적으로 32bit의 크기를 가진다.

// 네이밍 규약
// - 중요. 
// - 알아보기 쉽고 간결해야한다.(길이가 길어지더라고 알아보기 좋은 것이 권장된다.)
// - 수업중에는 언리얼의 코딩 규약을 따를 것(파스칼 케이스 기반 + 약간의 변형)
// - 문법적 금지
//		- 예약어(컴파일러가 미리 사용하려고 잡아 놓은 이름)
//		- 숫자로 시작하기
//		- 대부분의 특수문자(언더바_는 가능. 하지만 비권장)
//		- 띄워쓰기
// - 비권장
//		- 영어가 아닌 문자
//		- 알파벳은 같지만 대소문자가 다른 두 변수

// 연산자(Operator)
//	- 산술 연산자
//		+,-,*,/,%
//		사칙연산 같이 숫자끼리 더하거나 빼거나 하는 것들
//	- 대입 연산자
//		=
//		=오른쪽에 있는 값을, =왼쪽에 있는 변수에 넣어라
//		int i = 20;	// i라는 변수에 20이라는 값을 넣어라
// 
//	- 복합 대입 연산자
//		줄여 쓰기용. 대입연산자와 다른 연산자를 합쳐서 복합적으로 사용하는 연산자.
//		int a, int b;
//		a = a + b;	a += b;		// 둘 다 같은 코드
//	- 증감 연산자
//		줄여 쓰기용. 정수에 1을 더하거나 뺄 때 사용하는 연산자.
//		a = a + 1;	a++;		// 둘 다 같은 코드
//		b = b - 1;	b--;
// 
//int Number = 10;	// 대입 연산자로 Number에 10을 넣었다.
//printf("Number : %d\n", Number); 
//printf("Number : %5d\n", Number);	// Number를 정수 5자리로 출력해라
//Number = 20;		// 대입 연산자로 Number에 20을 넣었다.(덮어써진다)
//printf("Number : %d\n", Number);
//Number = 5 + 10;	// 산술 연산자 +를 이용해서 5와 10을 더하고 그 결과를 Number에 대입한다.
//printf("Number : %d\n", Number);
//Number = 7 % 3;		// 산술 연산자 %를 이용해서 7을 3으로 나눈 나머지를 구하고(1), 그 결과를 Number에 대입한다.
//printf("Number : %d\n", Number);
//
//int Temp1 = 7;
//Number += Temp1;	// Number와 Temp1의 값을 더하고 그 결과를 Number에 덮어쓴다. (Number = 8)
//printf("Number : %d\n", Number);
//Number *= Temp1;	// Number와 Temp1의 값을 서로 곱하고 그 결과를 Number에 덮어쓴다. (Number = 56)
//printf("Number : %d\n", Number);
//
//Number--;	// (Number = 55)
//Number--;	// (Number = 54)
//Number--;	// (Number = 53)
//printf("Number : %d\n", Number);

//// 간단 실습
//// - 두 수를 입력받아 스왑하기
//int Num1 = 0, Num2 = 0, Num3 = 0;
//printf("첫번째 숫자를 입력하세요 : ");
//cin >> Num1;		//std::cin >> Num1;
//printf("두번째 숫자를 입력하세요 : ");
//cin >> Num2;
//printf("입력한 숫자는 %d, %d 입니다.\n", Num1, Num2);
//Num3 = Num1;
//Num1 = Num2;
//Num2 = Num3;
//printf("스왑한 결과는 %d, %d 입니다.\n", Num1, Num2);
//
//// - 두 수를 입력받아 합을 출력하기
//printf("숫자 두개를 입력하세요 : ");
//cin >> Num1 >> Num2;
//printf("입력한 숫자는 %d, %d 입니다.\n", Num1, Num2);
//printf("두 수의 합은 %d입니다.\n", Num1 + Num2);
//
//// - 사각형의 가로, 세로를 입력받아 넓이를 출력하기
//printf("사각형의 가로와 세로를 입력하세요 : ");
//cin >> Num1 >> Num2;
//printf("입력한 숫자는 %d, %d 입니다.\n", Num1, Num2);
//printf("사각형의 넓이는 %d입니다.\n", Num1* Num2);
//
//// - 두 수를 입력받아 나머지를 출력하기(% 연산자를 사용한 것과 안한것 모두)
//printf("숫자 두개를 입력하세요 : ");
//cin >> Num1 >> Num2;
//printf("입력한 숫자는 %d, %d 입니다.\n", Num1, Num2);
//printf("나머지 값은 %d입니다.\n", Num1% Num2);
//int Mok = Num1 / Num2;
//int Namugi = Num1 - (Mok * Num2);
//printf("나머지 값은 %d입니다.\n", Namugi);

// 실습 풀이
	//온도 변환기 
	//설명: 섭씨 온도를 정수로 입력받아 화씨 온도로 변환하여 출력하는 프로그램.
	//공식 : 화씨 = 섭씨 * 9 / 5 + 32 = 섭씨 * 1.8 + 32
	//int Temperature = 0;
	//printf("섭씨 온도를 입력해 주세요 : ");
	//cin >> Temperature;
	//printf("화씨 온도는 %d입니다.\n", Temperature * 9 / 5 + 32);

	//시간 계산기
	//초를 입력 받아 시분초 출력하기
	//int Second = 0;
	//printf("계산할 초를 입력해 주세요 : ");
	//cin >> Second;
	//int Hour = Second / 3600;	
	//Second -= Hour * 3600;	//Second = Second - Hour * 3600;
	//int Minute = Second / 60;
	//Second -= Minute * 60;
	//printf("%d시간 %d분 %d초", Hour, Minute, Second);

	//동전 개수 계산하기
	//금액을 입력받아 500원, 100원, 50원, 10원 동전이 각각 몇 개 필요한지 계산하는 프로그램.
	//금액이 큰 동전을 최대한 많이 받아야 한다.
	//int Money = 0;
	//printf("총 금액을 입력해 주세요 : ");
	//cin >> Money;
	//int CoinCount500 = 0;
	//CoinCount500 = Money / 500;
	//Money -= CoinCount500 * 500;
	//int CoinCount100 = 0;
	//CoinCount100 = Money / 100;
	//Money -= CoinCount100 * 100;
	//int CoinCount50 = 0;
	//CoinCount50 = Money / 50;
	//Money -= CoinCount50 * 50;
	//int CoinCount10 = 0;
	//CoinCount10 = Money / 10;
	//Money -= CoinCount10 * 10;
	//printf("500원 : %d개, 100원 : %d개, 50원 : %d개, 10원 : %d개, 1원 : %d개",
	//	CoinCount500, CoinCount100, CoinCount50, CoinCount10, Money);

	//자리수 분리하기(입력은 항상 세자리라고 가정)
	//수를 입력받고 100의 자리, 10의 자리, 1의 자리를 각각 출력하기	
	//각 자리의 수를 합해서 출력하기
	//int Number = 0;
	//printf("세자리 수를 입력해 주세요 : ");
	//cin >> Number;
	//int Hundred = Number / 100;
	//Number -= Hundred * 100;
	//int Ten = Number / 10;
	//Number -= Ten * 10;
	//int One = Number;
	//printf("100의 자리 : %d, 10의 자리 : %d, 1의 자리 : %d\n", Hundred, Ten, One);
	//printf("각 자리의 수를 합하면 %d입니다.", Hundred + Ten + One);

	//파일 용량 환산기
	//메가바이트(MB) 단위의 파일 크기를 입력받아, 킬로바이트(KB)와 바이트(Byte) 단위로 환산해 출력하는 프로그램
	//공식 : 1MB = 1024KB, 1KB = 1024Byte
	//int FileSize = 0;
	//printf("파일 용량을 MB 단위로 입력해 주세요 : ");
	//cin >> FileSize;
	//printf("%dMB = %dKB = %dByte", FileSize, FileSize * 1024, FileSize * 1024 * 1024);

	//타일 개수 계산기(면적 구하기)
	//직사각형 방의 가로, 세로 길이(cm)를 입력받고, 가로 30cm, 세로 30cm인 타일로 이 방을 채우려면 타일이 총 몇 개 필요한지 출력하기
	//int Width = 0, Height = 0;
	//const int TileSize = 30;	
	//printf("방의 가로 세로 길이를 입력하세요 : ");
	//cin >> Width >> Height;
	//int WidthCount = (Width + (TileSize - 1)) / TileSize;
	//int HeightCount = (Height + (TileSize - 1)) / TileSize;
	//printf("필요한 총 타일의 개수는 [%d]개가 필요합니다.", WidthCount * HeightCount);