#pragma once
#include "Day0602.h"
class Day0605
{
public:
	// 인터페이스
	//	- 이 인터페이스를 상속받은 클래스는 ~한 행동을 할 수 있다라는 것을 알리는 것이 목적.
	//	- 인터페이스의 주요 요소
	//		- 반드시 public 함수의 선언만 있다.(구현이 있으면 안된다.)
	//		- 맴버 변수도 없다.
	//		- 이름이 대문자 I로 시작한다.
	//	- C++은 인터페이스를 정식으로 지원하지 않는다.(추상 클래스를 인터페이스처럼 사용함)
	void Interface();
	//void Test();

	// enum class
	//	- 더 안전해진 enum, 더 불편해지는 부분도 있다.
	//	- 타입 안정성이 강화
	//		- 기존의 enum은 int와 암시적 변환이 가능하다. -> 편리하지만 논리적 오류가 발생할 수 있다.
	//	- 이름 겹침 문제를 줄일 수 있다.(enum class는 별도의 네임스페이스를 가지는 것과 유사하다.)
	//	- 사이즈를 지정할 수 있다.(정수형 타입이면 모두 가능)

	void EnumClass();

	// 자료구조(Data Structure)
	//	- 특정한 구조와 규칙을 가지고 데이터를 효율적으로 관리하는 방법
	//	- 필요한 이유
	//		- 더 빠르게(CPU)
	//		- 더 효율적이게(메모리)
	//		- 문제 해결을 위한 구조 제공 등
	//	- 주요 자료구조
	//		- 배열, 리스트, 스택, 큐, 트리, 그래프

	// 시간 복잡도
	//	- 알고리즘의 속도를 표현하기 위해 사용
	//	- 빅오 표기법 : O(1), O(n), O(logN)....


	// 배열
	//	- 장점 : 랜덤 엑세스가 빠르다.
	//	- 단점 : 크기가 고정이다. 데이터 추가 삽입/삭제가 오래걸린다.

	// 리스트
	//	- 배열의 단점을 해결한 자료구조
	//	- 장점 : 데이터 추가/삭제가 매우 빠르다. 크기가 동적으로 변할 수 있다.
	//			순서가 자주 바뀌거나, 추가 삭제가 많은 경우 유용(음악 재생 목록, 턴 순서 관리, 버프/디버프)
	//	- 단점 : 탐색속도가 느리다. 추가 메모리가 필요하다.
	//			랜덤 액세스가 많을 경우(중간에 확인하는 것), 데이터 개수가 고정인 경우 불리함.
	void TestList();

};

//class IFlyable	// IFlyable이라는 인터페이스가 있는데
//{
//public:
//	virtual void Fly() = 0;	// 날기라는 함수를 가진다.
//	virtual ~IFlyable() {};
//};

class Test0605_1 : public IFlyable	// Test0605는 IFlyable인터페이스를 상속받았으니까
{
public:
	virtual void Fly() override;	// 날기라는 함수가 반드시 있다.

	int Data = 10;
	
};

class Test0605_2 : public IFlyable	// Test0605는 IFlyable인터페이스를 상속받았으니까
{
public:
	virtual void Fly() override;	// 날기라는 함수가 반드시 있다.

	int Data = 20;
};

enum class Direction : uint8_t
{
	Up = 1 << 0,
	Down = 1 << 1,
	Left = 1 << 2,
	Right = 1 << 3
};

using DirectionType = std::underlying_type_t<Direction>;	

inline Direction operator|(Direction InLeft, Direction InRight)
{
	// InLeft와 InRight를 uint8로 캐스팅해서, |비트연산을 하고, 다시 Direction타입으로 캐스팅.
	return static_cast<Direction>(static_cast<DirectionType>(InLeft) | static_cast<DirectionType>(InRight));
}
inline Direction operator&(Direction InLeft, Direction InRight)
{
	return static_cast<Direction>(static_cast<DirectionType>(InLeft) & static_cast<DirectionType>(InRight));
}
inline Direction operator~(Direction InValue)
{
	return static_cast<Direction>(~static_cast<DirectionType>(InValue));
}
inline Direction& operator|=(Direction& InLeft, Direction InRight)
{
	InLeft = InLeft | InRight;	// 이미 정의해 놓은 연산 재활용하기
	return InLeft;
}
inline Direction& operator&=(Direction& InLeft, Direction InRight)
{
	InLeft = InLeft & InRight;
	return InLeft;
}

// |=
// &=