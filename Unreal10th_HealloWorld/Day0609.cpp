#include <iostream>
#include <stack>
#include <string>
#include "Day0609.h"
#include "FixedStack.h"

void Day0609::Day0609_Main()
{
	//Day0609_Stack();
    //TestStack();
    //Reverse();
    //ReverseSTL();
    Day0609_Queue();
}

void Day0609::Day0609_Stack()
{
	std::stack<int> TestStack;
	TestStack.push(10);
	TestStack.push(20);
	TestStack.push(30);
	TestStack.push(40);
	TestStack.push(50);

	int Value = TestStack.top();
	TestStack.pop();
	Value = TestStack.top();
	TestStack.pop();
	Value = TestStack.top();
	TestStack.pop();
	Value = TestStack.top();
	TestStack.pop();
	Value = TestStack.top();
	TestStack.pop();
	Value = TestStack.top();	
	//TestStack.pop();

	int i = 0;

	// 간단 실습
	// 1. FixedStack 구현하기
    // 2. 문자열 입력 받고 거꾸로 출력하기(FixedStack과 std::stack 둘다 해보기)
}

void Day0609::Day0609_Queue()
{

}

void Day0609::TestStack()
{
    printf("--- FixedStack 테스트 시작 ---\n\n");

    FixedStack stack;

    // 1. 초기 상태 테스트
    printf("1. 초기 상태 테스트\n");
    printf("스택이 비었나요? %s\n", stack.IsEmpty() ? "예" : "아니요");
    printf("현재 크기: %d\n", stack.GetSize());
    printf("\n");

    // 2. Push 테스트
    printf("2. Push 테스트\n");
    printf("Push: 10\n");
    stack.Push(10);
    printf("Top: %d, Size: %d\n", stack.Top(), stack.GetSize());

    printf("Push: 20\n");
    stack.Push(20);
    printf("Top: %d, Size: %d\n", stack.Top(), stack.GetSize());

    printf("Push: 30\n");
    stack.Push(30);
    printf("Top: %d, Size: %d\n", stack.Top(), stack.GetSize());
    printf("\n");

    // 3. Pop 테스트
    printf("3. Pop 테스트\n");
    printf("Pop 실행\n");
    stack.Pop();
    printf("Top: %d, Size: %d\n", stack.Top(), stack.GetSize());
    printf("\n");

    // 4. 경계 테스트: 스택 오버플로우 (Stack Overflow)
    printf("4. 경계 테스트: 오버플로우\n");
    printf("스택을 가득 채웁니다...\n");
    // 현재 2개의 원소(10, 20)가 있으므로, 8개를 더 추가하면 가득 참 (용량: 10)
    for (int i = 3; i <= 10; ++i) {
        int value = i * 10;
        printf("Push: %d\n", value);
        stack.Push(value);
    }
    printf("스택이 꽉 찼나요? %s\n", stack.IsFull() ? "예" : "아니요");
    printf("Top: %d, Size: %d\n", stack.Top(), stack.GetSize());

    printf("\n오버플로우 시도: Push 110\n");
    stack.Push(110); // "오류: 스택이 꽉 찼습니다!" 메시지 출력 예상
    printf("Top: %d, Size: %d\n", stack.Top(), stack.GetSize()); // 변화 없음
    printf("\n");

    // 5. 경계 테스트: 스택 언더플로우 (Stack Underflow)
    printf("5. 경계 테스트: 언더플로우\n");
    printf("모든 원소를 Pop 합니다...\n");
    while (!stack.IsEmpty()) {
        printf("Popping: %d\n", stack.Top());
        stack.Pop();
    }
    printf("스택이 비었나요? %s\n", stack.IsEmpty() ? "예" : "아니요");
    printf("Size: %d\n", stack.GetSize());

    printf("\n언더플로우 시도 (Pop)\n");
    stack.Pop(); // "오류: 스택이 비어있습니다!" 메시지 출력 예상

    printf("\n언더플로우 시도 (Top)\n");
    int topValue = stack.Top(); // "오류: ..." 메시지 출력 예상
    printf("Top 호출 결과: %d\n", topValue); // Empty(-1) 값 출력 예상
    printf("\n");

    printf("--- FixedStack 테스트 종료 ---\n");
}

void Day0609::Reverse()
{
    std::string Input;
    printf("영어 단어를 입력하세요(최대 10자) : ");
    std::cin >> Input;

    FixedStack MyStack;
    for (char c : Input)
    {
        MyStack.Push(static_cast<int>(c));
    }
    //for (int i = 0; i < Input.size(); i++)
    //{
    //    char c = Input[i];
    //}
    printf("입력된 단어 : %s\n", Input.c_str());

    std::string ReveseString;
    while (!MyStack.IsEmpty())
    {
        char Temp[2] = { static_cast<char>(MyStack.Pop()), '\0' };
        ReveseString.append(Temp);
    }
    printf("뒤집힌 단어 : %s\n", ReveseString.c_str());
    
}

void Day0609::ReverseSTL()
{
    std::string Input;
    printf("영어 단어를 입력하세요 : ");
    std::cin >> Input;

    std::stack<char> StackSTL;
    for (char c : Input)
    {
        StackSTL.push(c);
    }
    printf("입력된 단어 : %s\n", Input.c_str());

    std::string ReveseString;
    while (!StackSTL.empty())
    {
        char Temp[2] = { StackSTL.top(), '\0'};
        ReveseString.append(Temp);
        StackSTL.pop();
    }
    printf("뒤집힌 단어 : %s\n", ReveseString.c_str());
}
