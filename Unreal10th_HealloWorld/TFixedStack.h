#pragma once
#include <cstdio> // printf 사용을 위해 추가

// 다양한 타입을 지원하고, 스택 크기도 지정할 수 있는 템플릿 클래스
template <typename T, int Capacity = 10>
class TFixedStack
{
public:
    // 스택에 값을 추가하는 함수
    void Push(const T& InValue);

    // 스택의 Top에 위치한 값을 꺼내는 함수. 비어있으면 기본값을 반환.
    T Pop();

    // 스택의 Top에 있는 값을 확인하는 함수 (제거하지 않음).
    // 성공 시 값이 있는 주소를 반환 (읽기 전용).
    // 실패(스택이 비어있을 때) 시 nullptr을 반환.
    const T* Top() const;

    // 스택이 가득 찼는지 확인하는 함수
    inline bool IsFull() const
    {
        return TopIndex == (Capacity - 1);
    }

    // 스택이 비어있는지 확인하는 함수
    inline bool IsEmpty() const
    {
        return TopIndex == Empty;
    }

    // 스택의 현재 크기(저장된 요소의 수)를 반환하는 함수
    inline int GetSize() const
    {
        return TopIndex + 1;
    }

private:
    // 스택이 비어있음을 나타내는 인덱스
    static constexpr int Empty = -1;

    // 스택의 Top 위치. -1일 경우 비어있음을 의미.
    int TopIndex = Empty;

    // 데이터를 저장하는 배열
    T Data[Capacity];
};

template <typename T, int Capacity>
void TFixedStack<T, Capacity>::Push(const T& InValue)
{
    if (IsFull())
    {
        printf("오류: 스택이 가득 찼습니다! (Stack Overflow)\n");
        return;
    }
    TopIndex++;
    Data[TopIndex] = InValue;
}

template <typename T, int Capacity>
T TFixedStack<T, Capacity>::Pop()
{
    if (IsEmpty())
    {
        printf("오류: 비어있는 스택에서 값을 꺼낼 수 없습니다! 기본값을 반환합니다.\n");
        return T(); // 타입 T의 기본 생성자로 생성된 값을 반환 (예: int는 0, 클래스는 기본 객체)
    }
    T Result = Data[TopIndex];
    TopIndex--;
    return Result;
}

// 반환 타입을 const T* 로 수정
template <typename T, int Capacity>
const T* TFixedStack<T, Capacity>::Top() const
{
    if (IsEmpty())
    {
        printf("오류: 비어있는 스택의 값은 확인할 수 없습니다.\n");
        return nullptr;
    }
    // const 멤버 함수이므로 내부 데이터에 대한 const 포인터를 반환해야 합니다.
    return &Data[TopIndex];
}