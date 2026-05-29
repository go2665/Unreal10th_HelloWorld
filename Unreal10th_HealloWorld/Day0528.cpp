#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "Day0528.h"

using namespace std;

void Day0528()
{
	Day0528_String();
	//Day0528_FileIO();
	//Day0528_Structure();

}

void Day0528_String()
{
	// 파싱(Parsing)
	//	- 문자열이나 데이터 구조를 분석하여 의미있는 정보로 변환하는 과정
	//	- csv, json, xml 등등

	//const char* TestString = "Orc, 10, 5, 10";
	//int Size = strlen(TestString);
	//for (int i = 0; i < Size; i++)
	//{
	//	if(TestString[i] == ',')
	//	{ }
	//}
	//char Name[256];
	//int Strength;

	//char Input[256];
	////std::cin >> Input;
	////printf("%s", Input);
	//std::cin.getline(Input, 256);	// 띄워쓰기 포함 입력 받을 때 사용
	//printf("%s\n", Input);

	// std::string
	//	- C++의 문자열 타입

	const char* Temp = "Hello World!\n";	// C 스타일의 문자열
	std::string Str1 = "Hello";
	printf("%s\n", Str1.c_str());
	string Str2 = "World!";
	printf("%s\n", Str2.c_str());
	string Str3 = Str1 + " " + Str2 + "\n";
	printf("%s\n", Str3.c_str());

	string Str4("Hello World?\n");	// 생성자를 사용하는 방식
	Str4 += Temp;					// 문자열 합치기(+=, +)
	Str4.append("Append\n");		// 문자열 합치기 함수
	printf("%s\n", Str4.c_str());

	// 문자열 길이 확인
	string Str5 = "Hello";
	//Str4.length();	// 둘 다 같은 기능
	//Str4.size();
	printf("%s : %d\n", Str5.c_str(), (int)Str5.size());

	if (Str1 == Str5)
	{
		printf("Str1과 Str5는 같습니다.\n");
	}
	if (Str1 != Str2)
	{
		printf("Str1과 Str2는 다릅니다.\n");
	}
	if (Str1 < Str2)	// 사전순으로 비교
	{
		printf("Str1이 Str2보다 앞에 있습니다.\n");
	}

	// 문자열에서 특정 문자 위치 찾기
	int ePos = (int)Str1.find('e');
	printf("%s에서 'e'는 %d 인덱스에 있습니다.\n", Str1.c_str(), ePos);

	// 특정 문자열 모두 찾기
	size_t Pos = Str1.find('l');
	while (Pos != string::npos)	// npos는 못찾았을 경우
	{
		printf("%s에서 'l'은 %d 인덱스에 있습니다.\n", Str1.c_str(), (int)Pos);
		Pos = Str1.find('l', Pos + 1);
	}

	// 인덱스로 문자열의 특정 위치 접근하기
	printf("%s의 첫번째 글자는 %c입니다.\n", Str1.c_str(), Str1[0]);
	printf("%s의 네번째 글자는 %c입니다.\n", Str1.c_str(), Str1[4]);

	// 간단 실습
	// std::string과 char를 파라메터로 받아서 string에 char가 어디에 있었는지 출력하는 함수 만들기
	//	- 여러개 있으면 모두 출력
	//	- 없으면 없다고 출력
	FindCharacter("Hello", 'l');
	FindCharacter(Str1, 'o');
	FindCharacter(Str1, 'x');

	printf("%s -> %s\n", Str1.c_str(), Str1.substr(1).c_str());
	printf("%s -> %s\n", Str1.c_str(), Str1.substr(0, 3).c_str());
	string str6 = "123456789";
	int integer = std::stoi(str6);
	printf("%d\n", integer);

	// std::stringstream
	// std::getline
}

void Day0528_FileIO()
{
	// 파일입력
	const string FilePath = ".\\Data\\DataFile.txt";	// .은 현재 워킹 폴더(기본적으로 파일이 실행되는 곳)
	std::ifstream InputFile(FilePath);	// 입력용 파일스트림 만들기
	if (InputFile.is_open())
	{
		std::string FileTexts(
			(std::istreambuf_iterator<char>(InputFile)),
			std::istreambuf_iterator<char>()
		);
		printf("파일 내용 : \n%s\n", FileTexts.c_str());
		InputFile.close();
	}
	else
	{
		// 파일이 없거나 다른 이유로 열리지 않았다.
		printf("파일을 열 수 없습니다.\n");
	}

	// 파일출력
	const string OutputFilePath = ".\\Data\\OutTest.txt";
	std::ofstream OutFile(OutputFilePath);	// 기존 파일 덮어쓰기
	//std::ofstream OutFile(OutputFilePath, std::ios::app);	// 덧붙이기
	if (OutFile.is_open())
	{
		OutFile << "Hello World\n";
		OutFile << "안녕하세요2.\n";
		OutFile.close();
	}
	else
	{
		printf("파일을 생성하는데 실패했습니다.");
	}

	// 간단 실습
	// - 이름과 돈을 입력받고 파일로 저장하기
	// - 파일을 불러와서 저장된 이름과 돈을 출력하기
}

void Day0528_Structure()
{
	// 구조체(Structure)
	//	- 관련된 데이터 집합을 표현하는데 사용.
	//		- 여러 종류의 데이터타입을 하나로 묶어서 사용
	//	- 프로그램의 가독성과 유지보수성도 향상



	Enemy Orc;	// Orc라는 변수로 4가지의 정보에 접근 가능
	Enemy Orcs[5];	// Enemy 5개

	// 인스턴스
	//	- 변수 그자체
	//	-  int a; // int타입의 인스턴스 a를 만들었다.

	// 구조체 맴버 접근법
	//	- .을 이용한다.(실제 인스턴스일 때)
	//	- ->를 이용한다.(주소를 가지고 있을 때)
	
	Orc.Name = "돌쇠";			// .을 이용해 각 맴버에 접근
	Orc.Health = 100.0f;
	Orc.AttackPower = 10.0f;
	Orc.Reward = 5;

	Enemy* OrcAddress = &Orc;
	printf("오크의 이름은 [%s]입니다.\n", OrcAddress->Name.c_str());
	printf("오크의 체력은 [%.1f]입니다.\n", OrcAddress->Health);

	TestStruct(Orc);
	// 간단 실습
	// Enemy의 데이터를 출력하는 함수 만들기
	//	- Enemy의 참조를 파라메터로 받는 함수
	//	- Enemy의 주소를 파라메터로 받는 함수

	Enemy* HighOrc = new Enemy();
	delete HighOrc;
	HighOrc = nullptr;

	PrintEnemyData(Orc);
	PrintEnemyData(&Orc);

	// 생성자
	//	- 구조체나 클래스의 객체가 만들어 질때(인스턴스 생성시) 자동으로 호출되는 특별한 함수 같은 것
	//	- 주로 맴버 변수 초기화에 사용
	//	- 특징
	//		- 이름이 구조체 이름과 같다.
	//		- 반환형이 없다
	//		- 객체가 생성될때 자동으로 호출
	//		- 생성자가 여러개 일 수도 있다.

	// 초기화 방법
	// 1. 맴버 직접 초기화
	//		- 구조체 선언할 때 직접 값을 넣어 놓는 것
	// 2. 중괄호 초기화
	//		- 인스턴스를 생성할 때 한번에 만드는 방식
	// 3. 생성자 초기화 리스트
	//		- 생성자에서 맴버가 선언된 순서대로 데이터 설정
	// 4. 생성자 내부 대입
	//		- 이미 생성된 객체에 값을 대입 처리
	//		- 별도의 추가 연산이라 속도가 위 방법들에 비해 늦다.


	int Test[] = { 1,2,3,4,5 };
	EnemyOrc TestOrc = { std::string("쓰랄"), 200.0f, 50.0f, 100 };	// 2. 중괄호 초기화
	PrintEnemyData(&TestOrc);
	EnemyOrc* TestOrc2 = new EnemyOrc(3.0f);
	PrintEnemyData(TestOrc2);
	delete TestOrc2;
	TestOrc2 = nullptr;
}

void FindCharacter(const std::string& Str, const char Target)
{
	bool bFound = false;
	size_t Pos = Str.find(Target);	// 일단 찾기 시도(Str에서 처음부터 찾아라)
	while (Pos != string::npos)		// 찾았으면 while안으로 들어가기(npos는 못찾았을 경우)
	{
		printf("%s에서 '%c'은 %d 인덱스에 있습니다.\n", Str.c_str(), Target, (int)Pos);
		Pos = Str.find(Target, Pos + 1);	// Str에서 Target을 찾는데 Pos(이전에 찾은 위치) 다음부터 찾아라. (find의 두번째 파라메터는 시작 위치)
		bFound = true;	// 찾았다고 표시
	}

	if (!bFound)
	{
		// 찾은것이 없다.
		printf("%s에서 '%c'는 없습니다.\n", Str.c_str(), Target);
	}
}

void TestStruct(Enemy Target)
{
	printf("오크의 이름은 [%s]입니다.\n", Target.Name.c_str());
	printf("오크의 체력은 [%.1f]입니다.\n", Target.Health);
}

void PrintEnemyData(Enemy& Target)
{
	printf("적의 이름은 [%s]입니다.\n", Target.Name.c_str());
	printf("적의 체력은 [%.1f]입니다.\n", Target.Health);
	printf("적의 공격력은 [%.1f]입니다.\n", Target.AttackPower);
	printf("적의 보상은 [%d]입니다.\n", Target.Reward);
}

void PrintEnemyData(Enemy* Target)
{
	printf("적의 이름은 [%s]입니다.\n",		Target->Name.c_str());
	printf("적의 체력은 [%.1f]입니다.\n",		Target->Health);
	printf("적의 공격력은 [%.1f]입니다.\n",	Target->AttackPower);
	printf("적의 보상은 [%d]입니다.\n",		Target->Reward);
	//(*Target).Health; // 이것도 가능
}

void PrintEnemyData(EnemyOrc* Target)
{
	printf("적의 이름은 [%s]입니다.\n", Target->Name.c_str());
	printf("적의 체력은 [%.1f]입니다.\n", Target->Health);
	printf("적의 공격력은 [%.1f]입니다.\n", Target->AttackPower);
	printf("적의 보상은 [%d]입니다.\n", Target->Reward);
}
