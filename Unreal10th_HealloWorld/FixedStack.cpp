#include <iostream>
#include "FixedStack.h"

void FixedStack::Push(int InValue) 
{
    if (IsFull()) 
    {
        printf("오류: 스택이 꽉 찼습니다! (Stack Overflow)\n");
        return;
    }
    TopIndex++;
    Data[TopIndex] = InValue;
}

// 스택에서 원소를 제거합니다.
int FixedStack::Pop() 
{
    if (IsEmpty()) 
    {
        printf("오류: 스택이 비어있습니다! (Stack Underflow)\n");
        return Empty;
    }
    int Result = Data[TopIndex];
    TopIndex--;
    return Result;
}

// 스택의 최상단 원소를 확인합니다.
int FixedStack::Top() 
{
    if (IsEmpty()) 
    {
        printf("오류: 스택이 비어있습니다! 값을 반환할 수 없습니다.\n");
        return Empty;
    }
    return Data[TopIndex];
}