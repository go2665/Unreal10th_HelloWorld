#include <iostream>
#include <fstream>
#include <string.h>
#include "Day0528.h"

using namespace std;

void Day0528()
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
