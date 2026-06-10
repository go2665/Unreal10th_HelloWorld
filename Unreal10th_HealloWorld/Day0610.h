#pragma once
#include <stdexcept>    // 예외 처리용

class Day0610
{
public:
	void TestMain();

	void TestTemplateClass();
};

// 간단실습
// 1. 템플릿을 이용한 계산기 클래스 만들기
//	- Add, Sub, Multiple, Divid
//	- int * int, float * int, int * float, float * float 가능해야함
// 2. Bitflag용 비트 연산자 추가하기
//	- &, |=, &=, 

class Calculator {
public:
    // 덧셈
    template <typename T1, typename T2>
    auto Add(T1 a, T2 b) const {
        return a + b; // C++이 자동으로 더 큰 타입으로 변환하여 반환합니다.
    }

    // 뺄셈
    template <typename T1, typename T2>
    auto Subtract(T1 a, T2 b) const {
        return a - b;
    }

    // 곱셈
    template <typename T1, typename T2>
    auto Multiply(T1 a, T2 b) const {
        return a * b;
    }

    // 나눗셈
    template <typename T1, typename T2>
    auto Divide(T1 a, T2 b) const {
        if (b == 0) {
            throw std::runtime_error("0으로 나눌 수 없습니다!");
        }
        return a / b;
    }
};