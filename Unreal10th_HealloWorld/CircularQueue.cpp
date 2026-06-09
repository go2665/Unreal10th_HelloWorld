#include <iostream>
#include "CircularQueue.h"

CircularQueue2::CircularQueue2(unsigned int InSize)
{
    if (InSize == 0)
    {
        printf("Warnning : 크기가 0입니다. 강제로 1로 수정합니다.\n");
        InSize = 1;
    }

    MaxSize = static_cast<int>(InSize);
    Data = new int[MaxSize];
}

CircularQueue2::~CircularQueue2()
{
    delete[] Data;
    Data = nullptr;
}

void CircularQueue2::Enqueue(int InValue)
{
    if (IsFull())
    {
        printf("ERROR : 큐가 가득 차 있습니다!\n");
        return;
    }
    if (IsEmpty())
    {
        Front = 0;
    }
    Rear = (Rear + 1) % MaxSize;
    Data[Rear] = InValue;
}

int CircularQueue2::Dequeue()
{
    if (IsEmpty())
    {
        printf("ERROR : 큐가 비어있습니다!\n");
        return Empty;
    }

    int Value = Data[Front];
    if (Front == Rear)
    {
        Front = Empty;
        Rear = Empty;
    }
    else
    {
        Front = (Front + 1) % MaxSize;
    }
    return Value;
}

int CircularQueue2::Peek() const
{
    if (IsEmpty())
    {
        printf("ERROR : 큐가 비어있습니다!\n");
        return Empty;
    }
    return Data[Front];
}

void CircularQueue2::Print() const
{
    if (IsEmpty())
    {
        printf("ERROR : 큐가 비어있습니다!\n");
        return;
    }

    // 간단 실습
    // - Print 구현하기

    printf("현재 큐의 상태 : [ ");
    int Index = Front;
    printf("%d ", Data[Index]);
    while (Index != Rear)
    {
        Index = (Index + 1) % MaxSize;
        printf("%d ", Data[Index]);
    }
    printf("]\n");
}

void CircularQueue::Enqueue(int InValue)
{
    if (IsFull())
    {
        printf("ERROR : 큐가 가득 차 있습니다!\n");
        return;
    }
    if (IsEmpty())
    {
        Front = 0;
    }
    Rear = (Rear + 1) % MaxSize;
    Data[Rear] = InValue;
}

int CircularQueue::Dequeue()
{
    if (IsEmpty())
    {
        printf("ERROR : 큐가 비어있습니다!\n");
        return Empty;
    }

    int Value = Data[Front];
    if (Front == Rear)
    {
        Front = Empty;
        Rear = Empty;
    }
    else
    {
        Front = (Front + 1) % MaxSize;
    }
    return Value;
}

int CircularQueue::Peek() const
{
    if (IsEmpty())
    {
        printf("ERROR : 큐가 비어있습니다!\n");
        return Empty;
    }
    return Data[Front];
}

void CircularQueue::Print() const
{
    if (IsEmpty())
    {
        printf("ERROR : 큐가 비어있습니다!\n");
        return;
    }

    // 간단 실습
    // - Print 구현하기

    printf("현재 큐의 상태 : [ ");
    int Index = Front;
    printf("%d ", Data[Index]);
    while (Index != Rear)
    {
        Index = (Index + 1) % MaxSize;
        printf("%d ", Data[Index]);
    }
    printf("]\n");
}
