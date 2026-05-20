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