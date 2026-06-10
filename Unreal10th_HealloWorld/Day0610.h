#pragma once
#include <stdexcept>    // 예외 처리용
#include <set>

class Day0610
{
public:
	void TestMain();

	void TestTemplateClass();
    void TestTree();
    
    void TestSet();
    void PrintSet(const std::set<int>& InTarget);

    void TestMap();

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

struct SetTestData
{
    int a = 0; 
    float b = 0;

    SetTestData() = default;
    SetTestData(int InA, float InB) : a(InA), b(InB) {};

    bool operator<(const SetTestData& InOther) const
    {
        return a < InOther.a;
    }
};

struct SetTestDataFail
{
    int a = 0;
    float b = 0;

    SetTestDataFail() = default;
    SetTestDataFail(int InA, float InB) : a(InA), b(InB) {};
};

struct SetTestDataFunctor
{
    int a = 0;
    float b = 0;

    SetTestDataFunctor() = default;
    SetTestDataFunctor(int InA, float InB) : a(InA), b(InB) {};
};

struct CompareTest
{
    bool operator()(const SetTestDataFunctor& InLeft, const SetTestDataFunctor& InRight) const
    {
        return InLeft.a < InRight.a;
    }
};

enum class CharacterType
{
    Warrior,
    Mage,
    Cheif
};

struct CharacterData
{
    int Level;
    int HP;
    int Exp;
};

// set(집합)
// - 자동정렬, 중복 안됨, 빠른탐색(레드-블랙트리 알고리즘, O(logN))
// - 사용처
//      - 데이터의 유일성, 정렬, 빠른검색이 필요할 때 유용

// map
// - Key와 Value를 쌍으로 묶어 저장, 키는 중복 금지, 자동 정렬, 빠른 탐색(레드-블랙트리 알고리즘, O(logN))
// - 사용처
//      - 데이터에 중복이 없는 키 값이 설정되어 있고 필요할 때 빠르게 찾아야 하는 경우 유용
//      - 리소스 관리자, 데이터 드리븐, 다국어 지원 등등

// unordered_map
// - Key와 Value를 쌍으로 묶어 저장, 키는 중복 금지, 빠른 탐색(해시테이블(O(1)))
// - 사용처
//      - map을 써야하는데 정렬이 필요없는 경우(무조건)
//      - 리소스 관리자, 데이터 드리븐, 다국어 지원 등등