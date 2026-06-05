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

	void EnumClass();

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

