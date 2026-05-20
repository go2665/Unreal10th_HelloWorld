#pragma once

//// 비트 연산자
//	// - 비트를 계산하는 연산자.
//	// - 비트 플래그를 사용하기 위해 필요하다.
//
//	// 비트 And
//	// - &
//	// - 양변에 있는 데이터의, 각 자리수 비트가 둘 다 1이면 1이다.
//	// - 특정 비트에 세팅된 값을 확인하기 위해 사용한다.
//int DataA = 6;
//int DataB = 7;
//printf("DataA & DataB = %d\n", DataA& DataB);
//
//// 비트 Or
//// - |
//// - 양변에 있는 데이터의, 각 자리수 비트가 하나라도 1이면 1이다.
//// - 특정 비트에 플래그를 세팅할 때 사용한다.
//printf("DataA | DataB = %d\n", DataA | DataB);
//
//// 비트 Not
//// - ~
//// - 비트값이 반전된다.
//unsigned int DataC = 6;
//printf("~DataC = %u\n", ~DataC);
//
//// 비트 XOR
//// - ^
//// - 양변에 있는 데이터의 각 자리수 비트가 다르면 1, 같으면 0
//// - 특정 비트를 토글할 때 사용(모두 0으로 채우고 토글할 비트만 1로 세팅한 후 XOR를 하면 된다)
//printf("Bit toggle : %d\n", DataA ^ 1);
//printf("Bit toggle : %d\n", (DataA ^ 1) ^ 1);
//
//// 비트 쉬프트
//// - 왼쪽 쉬프트 <<,  오른쪽 쉬프트 >>
//// - 왼쪽 쉬프트는 마스크 생성용으로 유용, 곱하기 2로도 사용 가능
//printf("Bit Left Shift : %d", DataA << 1);
//printf("Bit Right Shift : %d", DataA >> 1);
////1 << 4;	// 5번째 비트 세팅
//
//// enum
//// - 상수의 집합
//enum WeekDays
//{
//	Mon,	// 별도의 설정이 없으면 첫번째 enum값은 0이고 1씩 증가
//	Tue,
//	Wed,
//	Thu,
//	Fri,
//	Sat = 10,	// 따로 설정하면 그 값부터 다시 1씩 증가
//	Sun
//};
//
//int EnumTest1 = Mon;
//
//enum BitFlagTest		// 비트 플래그용 마스크 설정하는 기본 방식
//{
//	Up = 1 << 0,
//	Down = 1 << 1,
//	Left = 1 << 2,
//	Right = 1 << 3
//};
//
//int Direction = Up | Right;	// 오른쪽 위
//Direction = Up | Down | Left | Right;	// 모든 방향
//
//switch (Direction)
//{
//case Up:
//	break;
//case Down:
//	break;
//case Left:
//	break;
//case Right:
//	break;
//default:
//	break;
//}

// 간단 실습
	// 1. 비트 연산을 활용해서 홀짝을 판별하기.(입력 데이터는 무조건 양수이다)
	//int BitMask = 1;
	//int TargetNumber = 0;
	//printf("홀짝을 확인할 숫자를 입력하세요 : ");
	//cin >> TargetNumber;
	//if ((TargetNumber & BitMask) != 0)
	//{
	//	printf("홀수 입니다.\n");
	//}
	//else
	//{
	//	printf("짝수 입니다.\n");
	//}

	////// 2. 캐릭터가 사용 가능한 무기 enum만들기. 데이터 설정해서 특정 무기를 사용할 수 있는지 없는지 확인하는 코드 만들기
	//enum WeaponType
	//{
	//	Sword	= 1,
	//	Hammer	= 1 << 1,
	//	Bow		= 1 << 2,
	//	Spear	= 1 << 3,
	//	Sheild	= 1 << 4
	//};
	//const int NumOfWeaponType = 5;
	//int PlayerWeaponAvailiables = Sword | Spear | Sheild;	// 내 캐릭터는 칼, 창, 방패를 쓸 수 있다.
	//////printf("확인할 무기를 입력해주세요\n(1-Sword, 2-Hammer, 3-Bow, 4-Spear, 5-Shield) : ");
	//////int SelectWeapon = 0;
	//////cin >> SelectWeapon;
	//////switch (SelectWeapon)
	//////{
	//////case 1:
	//////	if ((PlayerWeaponAvailiables & Sword) != 0)
	//////	{
	//////		printf("검을 사용할 수 있습니다.\n");
	//////	}
	//////	else
	//////	{
	//////		printf("검을 사용할 수 없습니다.\n");
	//////	}
	//////	break;
	//////case 2:
	//////	if ((PlayerWeaponAvailiables & Hammer) != 0)
	//////	{
	//////		printf("망치를 사용할 수 있습니다.\n");
	//////	}
	//////	else
	//////	{
	//////		printf("망치를 사용할 수 없습니다.\n");
	//////	}
	//////	break;
	//////case 3:
	//////	if ((PlayerWeaponAvailiables & Bow) != 0)
	//////	{
	//////		printf("활을 사용할 수 있습니다.\n");
	//////	}
	//////	else
	//////	{
	//////		printf("활을 사용할 수 없습니다.\n");
	//////	}
	//////	break;
	//////case 4:
	//////	if ((PlayerWeaponAvailiables & Spear) != 0)
	//////	{
	//////		printf("창을 사용할 수 있습니다.\n");
	//////	}
	//////	else
	//////	{
	//////		printf("창을 사용할 수 없습니다.\n");
	//////	}
	//////	break;
	//////case 5:
	//////	if ((PlayerWeaponAvailiables & Sheild) != 0)
	//////	{
	//////		printf("방패를 사용할 수 있습니다.\n");
	//////	}
	//////	else
	//////	{
	//////		printf("방패를 사용할 수 없습니다.\n");
	//////	}
	//////	break;
	//////default:
	//////	break;
	//////}
	////////PlayerWeaponAvailiables & (1 << (SelectWeapon - 1))
	//
	//// 3. 캐릭터가 사용 가능한 무기를 추가 삭제하기
	//std::string WeaponNames[] = { "Sword", "Hammer", "Bow", "Spear", "Sheild" };
	//std::string WeaponList = "";
	//for (int i = 0; i < NumOfWeaponType; i++)
	//{
	//	if ((PlayerWeaponAvailiables & (1 << i)) != 0)
	//	{
	//		WeaponList += WeaponNames[i];
	//		WeaponList += " ";
	//	}
	//}
	//printf("플레이어가 사용 가능한 무기는 다음과 같습니다.\n");
	//printf("[ %s]\n", WeaponList.c_str());

	//printf("추가할 무기의 번호를 입력해주세요.\n");
	//printf("1)Sword, 2)Hammer, 3)Bow, 4)Spear, 5)Sheild :");
	//int Select = 0;
	//cin >> Select;
	//PlayerWeaponAvailiables = PlayerWeaponAvailiables | 1 << (Select - 1);
	//WeaponList = "";
	//for (int i = 0; i < NumOfWeaponType; i++)
	//{
	//	if ((PlayerWeaponAvailiables & (1 << i)) != 0)
	//	{
	//		WeaponList += WeaponNames[i];
	//		WeaponList += " ";
	//	}
	//}
	//printf("플레이어가 사용 가능한 무기는 다음과 같습니다.\n");
	//printf("[ %s]\n", WeaponList.c_str());

	//printf("제거할 무기의 번호를 입력해주세요.\n");
	//printf("1)Sword, 2)Hammer, 3)Bow, 4)Spear, 5)Sheild :");
	//cin >> Select;
	//int Mask = 1 << (Select - 1);
	//Mask = ~Mask;
	//PlayerWeaponAvailiables = PlayerWeaponAvailiables & Mask;
	//WeaponList = "";
	//for (int i = 0; i < NumOfWeaponType; i++)
	//{
	//	if ((PlayerWeaponAvailiables & (1 << i)) != 0)
	//	{
	//		WeaponList += WeaponNames[i];
	//		WeaponList += " ";
	//	}
	//}
	//printf("플레이어가 사용 가능한 무기는 다음과 같습니다.\n");
	//printf("[ %s]\n", WeaponList.c_str());

	//// 반복문
	//// - 특정 코드블록을 조건에 따라 여러번 반복해서 실행할 수 있게 해주는 문(Statement)
	//
	//// for
	//// - 반복 회수가 명확할 때 사용하기 좋다.	
	//for (int i = 0; i < 5; i++)	// (변수초기화;종료조건;증감부)
	//{
	//	printf("Hello For : %d \n", i);
	//}	

	//// while
	//// - 반복 회수가 명확하지 않고 조건에 따라 반복해야 할 때 사용하기 좋다.
	//int j = 0;
	////while (true){}	// 무한 루프
	//while(j < 5)
	//{
	//	printf("Hello while : %d\n", j);
	//	j++;
	//}

	//// do-while
	//// - while과 비슷한데 최소 한번은 실행해야 할 때 사용하기 좋다.
	//j = 0;
	//do
	//{
	//	printf("Hello do-while : %d\n", j);
	//	j++;
	//} while (j < 5);

// 간단 실습
	// 1. 0을 입력 받을 때까지 입력 받은 숫자의 합을 출력
	//	- while이랑 do - while 둘 다 해보기
	// while
	//int InputNumber = 0;
	//printf("더할 숫자를 입력하세요 : ");
	//cin >> InputNumber;
	//int Sum = 0;
	//while (InputNumber != 0)
	//{
	//	Sum += InputNumber;
	//	printf("더할 숫자를 입력하세요 : ");
	//	cin >> InputNumber;
	//}
	//printf("모든 수의 합은 %d입니다.\n", Sum);

	// do-while
	//int InputNumber = 0;
	//int Sum = 0;
	//do
	//{
	//	printf("더할 숫자를 입력하세요 : ");
	//	cin >> InputNumber;
	//	Sum += InputNumber;
	//} while (InputNumber != 0);
	//printf("모든 수의 합은 %d입니다.\n", Sum);

	//// 2. 입력받은 수의 구구단 출력하기
	//int InputNumber = 0;
	//printf("출력할 구구단 단수를 입력하세요 : ");
	//cin >> InputNumber;
	//printf("%d 단을 출력합니다.\n", InputNumber);
	//for (int i = 1; i < 10; i++)
	//{
	//	printf("%d * %d = %d\n", InputNumber, i, InputNumber * i);
	//}

	//// 3. 1부터 입력받은 수까지 있는 수들 중 홀수만 출력하기
	//int InputNumber = 0;
	//printf("마지막 수를 입력하세요 : ");
	//cin >> InputNumber;
	//for (int i = 1; i <= InputNumber; i++)
	//{
	//	//if (i % 2 == 0)	// 짝수면 아래쪽 코드 스킵하기
	//	//{
	//	//	continue;	// 반복문에서 이번 반복만 스킵하는 것
	//	//}
	//	//printf("%d는 홀수입니다.\n", i);

	//	if (i % 2 == 1)
	//	{
	//		printf("%d는 홀수입니다.\n", i);
	//	}
	//}

	//// 4. 1~100 중에 7의 배수만 출력하기
	//for (int i = 1; i < 101; i++)
	//{
	//	if (i % 7 == 0)
	//	{
	//		printf("%d는 7의 배수입니다.\n", i);
	//	}
	//}

	//// 5. 팩토리얼 계산하기
	//int InputNumber = 0;
	//printf("팩토리얼을 계산할 수를 입력하세요 : ");
	//cin >> InputNumber;
	//int Sum = 1;
	//for (int i = 2; i <= InputNumber; i++)
	//{
	//	Sum *= i;
	//}
	//printf("결과 값은 [%d]입니다.", Sum);

	//// 6. *로 피라미드 모양의 삼각형 찍기
	//int InputNumber = 0;
	//printf("피라미드 층수를 입력하세요 : ");
	//cin >> InputNumber;
	//for (int i = 0; i < InputNumber; i++)	// 한번 반복될 때마다 한층씩 그리기 위한 반복문(for)
	//{
	//	for (int j = 0; j < InputNumber - 1 - i; j++)
	//	{
	//		printf(" ");
	//	}

	//	for (int j = 0; j < 2 * i + 1; j++)
	//	{
	//		printf("*");
	//	}
	//	printf("\n");
	//}


//	// 랜덤
//srand(time(0));	// 랜덤의 시드값을 현재 시간으로 설정하기(프로그램 실행할 때 한번만하면 된다.)
//
//int RandomNumber;
//int TestCount = 10000000;
//int Num1 = 0, Num2 = 0, Num3 = 0, Num4 = 0, Num5 = 0, Num6 = 0;
//for (int i = 0; i < TestCount; i++)
//{
//	RandomNumber = rand() % 6 + 1; // 1~6이 랜덤으로 골라진다.
//	//printf("Random : %d\n", RandomNumber);		
//	switch (RandomNumber)
//	{
//	case 1:
//		Num1++;
//		break;
//	case 2:
//		Num2++;
//		break;
//	case 3:
//		Num3++;
//		break;
//	case 4:
//		Num4++;
//		break;
//	case 5:
//		Num5++;
//		break;
//	case 6:
//		Num6++;
//		break;
//	default:
//		printf("ERROR!!! ERROR!!! ERROR!!! ERROR!!! ERROR!!! ERROR!!! ERROR!!! ERROR!!! ERROR!!! ");
//		break;
//	}
//}
//
//printf("Num1: [%d], Num2: [%d], Num3: [%d], Num4: [%d], Num5: [%d], Num6: [%d]\n",
//	Num1, Num2, Num3, Num4, Num5, Num6);