#pragma once

//// 이진수
//	// - 0과 1로만 표현되는 숫자
//	//	- ex) int i = 8;	// 메모리 : 0000 0000 0000 0000 0000 0000 0000 1000
//
//	// float(부동소수점)
//	// - 32bit
//	// - 소수점이 있는 숫자를 저장한다.
//	// - 구조적으로 오차가 있는 데이터 타입. 같다는 비교를 조심해서 해야한다.
//	// - 숫자 뒤에 f를 붙여야 한다.
//
//	// double(부동소수점)
//	// - 64bit
//
//float RealNumber = 0.0f;	// 0.0f는 float
////RealNumber = 0.1;			// 0.1는 double -> 암시적 변환이 일어나 float으로 저장됨 -> 워닝 발생
//RealNumber = (float)0.1;	// 명시적 변환, Casting
//
//printf("이것은 실수입니다 : %f\n", RealNumber);
//
//RealNumber = 0.1f + 0.5f;
//printf("이것은 실수입니다 : %.2f\n", RealNumber);	// 소수점 아래 둘째자리까지 출력
//RealNumber -= 0.2f;
//printf("이것은 실수입니다 : %8.2f\n", RealNumber);	// 소수점 포함 전체 8자리, 소수점 아래 둘째자리까지 출력
//printf("float타입의 사이즈는 [%d]byte입니다.\n\n", (int)(sizeof(float)));
//
//// bool(불리언 타입)
//// - true, false 이 둘만 저장하는 데이터 타입
//// - 프로그램의 각종 분기를 결정할 때 사용
//// - 8bit
//bool bTest = false;
//bTest = true;
//printf("bool타입의 사이즈는 [%d]byte입니다.\n", (int)(sizeof(bool)));
//
//// char(캐릭터 타입)
//// - 글자 하나를 저장하는 데이터 타입
//// - 8bit짜리 정수형 데이터 타입
//char TestCharacter = 'a';
//TestCharacter = 'b';
//TestCharacter = 'B';
//
//printf("char c = %c\n", TestCharacter);
//
//// 문자열
//// - char*, std::string 
//std::string TestString = "Hello World!\n";
//
//// 부호없는 인티저(32bit, 숫자 범위 0~42억)
//unsigned int TestInteger = 0;
//
//// 64bit 인티저
//long long TestInteger64 = 0;
//unsigned long long TestInteger64_2 = 0;
//
//// 유니코드 캐릭터
//wchar_t UnicodeChar = L'가';
//
//int Size = 100;
//printf("\n한변이 %d인 정사각형의 넓이는 %d입니다.\n", Size, Size* Size);
//Size = 50000;
//printf("한변이 %d인 정사각형의 넓이는 %u입니다.\n", Size, (unsigned int)Size* (unsigned int)Size);
//
//// 상수
//// - 절대 변하지 않는 숫자
//// - 코드의 안정성과 가독성을 높여준다.
//const int TestConst = 10;
//// TestConst = 20;	// 컴파일 에러

//	// 간단 실습
//	// 1. 원의 반지름 입력 받고 넓이 구하기
//float Radius = 0.0f;
//printf("반지름을 입력하세요(cm) : ");
//cin >> Radius;
//printf("원의 넓이는 [%.2f]제곱센티미터입니다.\n\n", Radius* Radius * 3.141592f);
//
//// 2. 3개의 값을 입력 받고 평균값 구하기
//float Num1 = 0.0f, Num2 = 0.0f, Num3 = 0.0f;
//printf("숫자 3개를 입력하세요 : ");
//cin >> Num1 >> Num2 >> Num3;
//float Average = 0.0f;
//Average = (Num1 + Num2 + Num3) / 3;
//printf("[%.1f], [%.1f], [%.1f]의 평균값은 [%.1f]입니다.\n\n", Num1, Num2, Num3, Average);
//
//// 3. 정가와 할인율을 입력받고 할인된 가격 구하기
//float Price = 0.0f;
//float Discount = 0.0f;
//printf("정가와 할인율(퍼센트)을 입력해 주세요 : ");
//cin >> Price >> Discount;
//float FinalPrice = Price - Price * (Discount * 0.01f);
//printf("최종 가격은 %d원입니다.\n\n", (int)FinalPrice);

//	// 비교 연산자
//	// - 두 변수를 비교하는 연산자(크다, 작다, 같다 등등을 계산)
//bool bTest = false;
//bTest = 10 > 5;		// true.	> 왼쪽 항목이 오른쪽 항목보다 큰지 확인하는 비교연산자
//bTest = 10 < 5;		// false
//bTest = 10 <= 5;	// false
//bTest = 10 >= 5;	// true
//bTest = 10 >= 10;	// true
//bTest = 10 > 10;	// false
//bTest = 10 == 10;	// true.	== 양변의 값이 같은지 확인하는 비교연산자ㅓ
//
//bTest = 0.1f + 0.2f == 0.3f;	// 이런식의 비교는 절대로 하면 안된다.
//
//int i = 0;
//
//// 조건문
//// - 특정 조건에 따라 다른 동작을 하게 만드는 문(statement)
//
//// if
//// - ()사이의 조건식이 true면 아래쪽 {}사이의 코드를 실행한다.
//int a = 30;
//int b = 20;
//if (a > b)
//{
//	printf("a(%d)가 b(%d)보다 큽니다.\n", a, b);
//}
//
//// if else
//// - ()사이의 조건식이 true면 아래쪽 {}사이의 코드를 실행하고 false면 else아래의 {} 사이의 코드를 실행한다.
//a = 10;
//if (a > b)
//{
//	printf("a(%d)가 b(%d)보다 큽니다.\n", a, b);
//}
//else
//{
//	printf("a(%d)가 b(%d)보다 작습니다..\n", a, b);
//}
//
//// else if
//// - if를 중첩하기
//if (a > (b * 2))
//{
//
//}
//else if (a > b)
//{
//
//}
//else if (a > (b / 2))
//{
//
//}
//else
//{
//
//}
//
//
//// switch
//// - 값이 여러가지 중 하나일 때 각각의 경우에 따라 다르게 처리할 때 사용
//a = 1;
//switch (a)
//{
//case 1:
//	printf("a는 1입니다.\n");
//	break;
//case 10:
//	printf("a는 10입니다.\n");
//	break;
//default:
//	printf("a는 %d입니다.\n", a);
//	break;
//}
//
//// 삼항 연산자
//int x = (a > 10) ? 1 : 0;	// ? 앞의 조건식이 참이면 ?와 :사이에 있는 값, 거짓이면 : 뒤에 있는 값.
//
//// 논리 연산자
//// - 참 아니면 거짓이 나오는 연산
//// - bool을 다루는 연산자.
//
//// &&
////  - And. 
////  - && 연산자 좌우의 값이 모두 true면 true, 아니면 false
////  - bool bTest = true && true;	// 이때만 bTest가 true.
//
//// ||
////  - Or.
////  - || 연산자 좌우의 값이 하나라도 true면 true, 둘 다 false일 때만 false 
////  - bool bTest = false || false;	// 이때만 bTest가 false
//
//// !
//// - Not
//// - true는 false로 만들고 false는 true로 변경
//// - bool bTest = true;  bTest = !bTest;	// bTest는 false
//
//int Point = 78;
//if ((Point < 90) && (Point >= 80))
//{
//	printf("B학점입니다.\n");
//}


	// 조건문 간단 실습(입력은 정수만)
	// 1. 숫자를 입력받아 양수인지 음수인지 0인지 판단하는 코드
	//int Number = 0;
	//printf("확인할 숫자를 입력해 주세요 : ");
	//cin >> Number;
	//if (Number > 0)	// 조건문에서는 항상 범위가 큰 것을 먼저 체크하는 것이 좋다.
	//{
	//	printf("%d는 양수입니다.\n", Number);
	//}
	//else if (Number < 0)
	//{
	//	printf("%d는 음수입니다.\n", Number);
	//}
	//else
	//{
	//	printf("%d는 0입니다.\n", Number);
	//}
	// 테스트는 경계값과 중간값을 꼭 체크해야한다.

	// 2. 숫자를 입력받아 홀수인지 짝수인지 판단하는 코드
	//printf("홀수인지 짝수인지 확인할 숫자를 입력해 주세요 : ");
	//cin >> Number;
	//if (Number % 2 == 0)
	//{
	//	printf("짝수입니다.\n");
	//}
	//else
	//{
	//	printf("홀수입니다.\n");
	//}

	// 3. 두 수를 입력 받아 더 큰 수를 출력하는 코드. 같을 경우 같다고 출력.
	//int Number2 = 0;
	//printf("숫자 두개를 입력해 주세요 : ");
	//cin >> Number >> Number2;
	//if (Number > Number2)
	//{
	//	printf("%d와 %d 중에 %d가 더 큽니다.\n", Number, Number2, Number);
	//}
	//else if (Number < Number2)
	//{
	//	printf("%d와 %d 중에 %d가 더 큽니다.\n", Number, Number2, Number2);
	//}
	//else
	//{
	//	printf("%d와 %d는 같은 수입니다.\n", Number, Number2);
	//}


	// 논리 연산자 간단 실습
	// 1. 나이와 키를 입력 받아, 6세 이상, 120cm 이상일 때 롤러코스터 탑승 가능, 그 외에는 불가능으로 출력하기
	//int Age = 0;
	//int Height = 0;
	//const int BaseAge = 6;
	//const int BaseHeight = 120;
	//printf("나이와 키를 입력해 주세요 : ");
	//cin >> Age >> Height;
	//if (Age >= 6 && Height >= 120)
	//{
	//	printf("롤러코스터를 탈 수 있습니다!\n");
	//}
	//else
	//{
	//	printf("롤러코스터를 탈 수 없습니다.\n");
	//}

	//// (Age >= 6 && Height >= 120)
	//// !(Age >= 6 && Height >= 120)
	//// Age < 6 || Height < 120


	// 2. 점수를 입력 받아 90점 이상은 A, 80점 이상은 B, 70점 이상은 C, 60점 이상은 D, 그 이하는 F라고 출력하기
	//const int GradeA = 90;
	//const int GradeB = 80;
	//const int GradeC = 70;
	//const int GradeD = 60;
	//int Score = 0;
	//printf("점수를 입력해 주세요 : ");
	//cin >> Score;
	//printf("입력한 점수는 %d입니다.\n", Score);
	//std::string Grade;
	//if (Score >= GradeA)
	//{
	//	Grade = "A학점";
	//}
	//else if(Score >= GradeB)
	//{
	//	Grade = "B학점";
	//}
	//else if (Score >= GradeC)
	//{
	//	Grade = "C학점";
	//}
	//else if (Score >= GradeD)
	//{
	//	Grade = "D학점";
	//}
	//else
	//{
	//	Grade = "F학점";
	//}
	//printf("당신의 학점은 [%s]입니다.", Grade.c_str());

	// 3. 세 과목의 점수를 입력받아, 세 과목의 평균점이 60점 이상이면 "합격", 아니면 "불합격"을 출력하는 프로그램을 작성하기
	//	  단 한과목이라도 40점 미만이면 불합격 출력하기
	//int Score1 = 0, Score2 = 0, Score3 = 0;
	//printf("세 과목의 점수를 입력해 주세요 : ");
	//cin >> Score1 >> Score2 >> Score3;
	//printf("입력된 점수는 다음과 같습니다.\n[%d], [%d], [%d]\n", Score1, Score2, Score3);

	//const int PassScore = 60;
	//const int FailScore = 40;
	//if (Score1 < FailScore || Score2 < FailScore || Score3 < FailScore)
	//{
	//	printf("불합격 입니다.\n");
	//}
	//else 
	//{
	//	float Average = (Score1 + Score2 + Score3) / 3;
	//	const float Threshold = 0.0001f;
	//	if ((Average + Threshold) >= PassScore)
	//	{
	//		printf("합격입니다.\n");
	//	}
	//	else
	//	{
	//		printf("불합격입니다.\n");
	//	}
	//}


////1. 세 수 중 최댓값과 최솟값 찾기
	////	3개의 정수를 입력받아, 그중 가장 큰 수와 가장 작은 수를 출력
	//int Num1 = 0, Num2 = 0, Num3 = 0;
	//printf("정수를 3개 입력해 주세요 : ");
	//cin >> Num1 >> Num2 >> Num3;
	//int Max = 0;	
	//if (Num1 >= Num2 && Num1 >= Num3)
	//{
	//	Max = Num1;
	//}
	//else if ( Num2 >= Num1 && Num2 >= Num3)
	//{
	//	Max = Num2;
	//}
	//else
	//{
	//	Max = Num3;
	//}

	//int Min = 0;
	//if (Num1 <= Num2 && Num1 <= Num3)
	//{
	//	Min = Num1;
	//}
	//else if (Num2 <= Num1 && Num2 <= Num3)
	//{
	//	Min = Num2;
	//}
	//else
	//{
	//	Min = Num3;
	//}
	//printf("Max : %d, \tMin : %d", Max, Min);


	////2. 세 개의 선분 길이를 입력받아, 이 선분들로 삼각형을 만들 수 있는지 판별하기
	////	조건: 삼각형이 되려면 '한 변의 길이 < 나머지 두 변의 길이의 합'이어야 함.
	//int Num1 = 0, Num2 = 0, Num3 = 0;
	//printf("정수를 3개 입력해 주세요 : ");
	//cin >> Num1 >> Num2 >> Num3;

	//if (((Num1 + Num2) > Num3) && ((Num1 + Num3) > Num2) && ((Num2 + Num3) > Num1))
	//{
	//	printf("삼각형이 성립합니다.\n");
	//}
	//else
	//{
	//	printf("삼각형이 아닙니다.\n");
	//}

	//3. 미니 계산기
	//	두 개의 정수와 하나의 연산자(+, -, *, /)를 입력받아 결과를 출력
	//	단, 나눗셈에서 0으로 나누려고 하면 "0으로 나눌 수 없습니다"라는 에러 메시지를 출력
	//int Num1 = 0;
	//int Num2 = 0;
	//char Op = 0;
	//float Result = 0.0f;
	//cin >> Num1 >> Op >> Num2;
	//switch (Op)
	//{
	//case '+':
	//	Result = Num1 + Num2;		
	//	break;
	//case '-':
	//	Result = Num1 - Num2;
	//	break;
	//case '*':
	//	Result = Num1 * Num2;
	//	break;
	//case '/':
	//	if (Num2 != 0)
	//	{
	//		Result = Num1 / Num2;
	//	}
	//	else
	//	{
	//		printf("0으로 나눌 수 없습니다.\n");
	//	}
	//	break;
	//default:
	//	break;
	//}
	//if (Op != '/')
	//{
	//	printf("%d %c %d = %.0f\n", Num1, Op, Num2, Result);
	//}
	//else
	//{
	//	if (Num2 != 0)
	//	{
	//		printf("%d %c %d = %.2f\n", Num1, Op, Num2, Result);
	//	}
	//}

	//4. 윤년 판별기
	//	연도(예: 2024)를 입력받아 그 해가 윤년인지 평년인지 출력
	//	윤년의 조건:
	//	연도가 4로 나누어 떨어지면 윤년이다.
	//	하지만 100으로 나누어 떨어지면 평년이다.
	//	그럼에도 400으로 나누어 떨어지면 윤년이다.
	//int Year = 0;
	//printf("연도를 입력해 주세요 : ");
	//cin >> Year;
	//bool bLeap = (((Year % 4) == 0) && ((Year % 100) != 0)) || (Year % 400 == 0);
	//if (bLeap)
	//{
	//	printf("%d년은 윤년이다.", Year);
	//}
	//else
	//{
	//	printf("%d년은 평년이다.", Year);
	//}