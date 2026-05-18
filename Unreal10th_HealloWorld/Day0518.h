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