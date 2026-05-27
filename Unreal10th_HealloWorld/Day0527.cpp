#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include "Day0527.h"

void Day0527()
{
	// 문자열(String)
	//	- 한 문장. 연속된 char.
	//	- C에서는 char*, char [] 사용
	//	- 항상 모든 문자열은 '\0'로 끝난다.
	const char* TestString1 = "Hello String!\n";	
	const char* TestString2 = "안녕 문자열!\n";		// 인코딩이 자동으로 처리되서 한글이 보이는거다.
	
	// wchar_t : 유니코드용 char.

	const char* TestString = "Hello";
	int Size = MyStrLen(TestString);
	printf("[%s]의 길이는 [%d]입니다.\n", TestString, Size);

	Size = (int)strlen(TestString);
	printf("[%s]의 길이는 [%d]입니다.\n", TestString, Size);

	char Buffer[32] = { 0, };
	strcpy(Buffer, TestString);
	printf("Buffer의 내용은 [%s]입니다.\n", Buffer);	// Buffer : Hello

	strcat(Buffer, TestString);
	printf("Buffer의 내용은 [%s]입니다.\n", Buffer);	// Buffer : HelloHello

	int Result = strcmp("abc", "abc");	// 같으면 0
	Result = strcmp("ab", "abc");		// 왼쪽이 작으면 -1
	Result = strcmp("abb", "abc");
	Result = strcmp("abc", "abb");		// 오른쪽이 작으면 +1
	Result = strcmp("abc", "ab");

	const char* TestStringNubmer1 = "123";
	int Number = atoi(TestStringNubmer1);
	printf("문자열 [%s]는 인티저 [%d]입니다.\n", TestStringNubmer1, Number);
	
	const char* TestStringNubmer2 = "12.3";
	float FloatNumber = (float)atof(TestStringNubmer2);
	printf("문자열 [%s]는 실수 [%f]입니다.\n", TestStringNubmer2, FloatNumber);

	// 간단 실습
	// 1. MyStrCpy
	// 2. MyStrCat
	// 3. MyStrCmp
	// 4. MyAtoI
	// 5. MyAtoF
	// 위 함수들 만들기. 파라메터와 리턴 타입은 원본과 같이 만들기

}

int MyStrLen(const char* str)
{
	// \0는 제외한 길이를 리턴
	int Length = 0;
	while (*(str + Length) != '\0')
	{
		Length++;
	}
	return Length;
}
