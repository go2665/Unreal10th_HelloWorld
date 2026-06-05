#include "Day0605.h"

void Day0605::Interface()
{
	IFlyable* List[2];
	Test0605_1 Test1;
	Test0605_2 Test2;
	List[0] = &Test1;
	List[1] = &Test2;
	List[1]->Fly();

	Test1.Data = 100;
	// List[0]->Data	// 인스턴스 자체는 Test0605_1지만 현제 타입은 IFlyable기 때문에 IFlyable의 맴버만 접근 가능

	// 간단 실습
	// - Day0602에 있는 동물들에게 인터페이스 추가하기
	//	- 날 수 있다
	//	- 수영할 수 있다.
	//	- 전투 할 수 있다.

}

void Day0605::EnumClass()
{
	enum Color	{ Red, Greed, Blue	};
	//enum TrafficLight { Red, Yellow, Green };	// 재정의가 되어서 컴파일 에러
	enum Fruit	{ Apple, Orange, Banana	};

	Color MyColor = Red;
	Fruit MyFruit = Apple;
	if (MyColor == MyFruit)
	{
		// 색상과 과일이 같다. 논리적으로는 말이 안되지만 문법적으로는 가능.
	}

	enum class Color2 { Red, Green, Blue };
	enum class TrafficLight2 { Red, Yellow, Green };
	enum class Fruit2 { Apple, Orange, Banana };
	Color2 MyColor2 = Color2::Red;
	Fruit2 MyFruit2 = Fruit2::Apple;
	//if (MyColor2 == MyFruit2)
	//{
	//		문법적으로 불가능
	//}
	// int로 변경하려면 명시적 캐스팅 필요
	int ColorNumber = static_cast<int>(Color2::Green);	// (int)(Color2::Green)
}

void Test0605_1::Fly()
{
	// 독수리처럼 날기
}

void Test0605_2::Fly()
{
	// 벌새처럼 날기
}
