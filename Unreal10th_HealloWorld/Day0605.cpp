#include "Day0605.h"
//#include <cstdint>
#include <stdint.h>
#include <type_traits>
#include "LinkedList.h"

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

	enum class AnimalType : int8_t		// 사이즈를 지정할 수 있다.
	{
		Eagle,
		Tiger,
		Whale
	};

	int Size = sizeof(AnimalType::Eagle);
	
	using RealType = std::underlying_type_t<AnimalType>;	// AnimalType의 실제 타입 받아오기
	

	// 비트 플래그 사용하기	
	Direction Dir = Direction::Up | Direction::Down;
	Dir |= Direction::Left;
	Dir &= Direction::Up;

	int i = 0;
}

void Day0605::TestList()
{
	LinkedList* MyList = nullptr;
	printf("--- 초기 리스트 생성 ---\n");
	MyList->Add(10);
	MyList->Add(20);
	MyList->Add(30);
	MyList->PrintList();

	printf("\n--- 1. InsertAt 테스트 ---\n");
	printf("1-1. 위치가 Size보다 클 때 (마지막에 추가):\n");
	MyList->InsertAt(40, 100);
	MyList->PrintList();
	printf("\n1-2. 정상적인 추가 (위치 0에 5 추가):\n");
	MyList->InsertAt(5, 0);
	MyList->PrintList();

	printf("\n--- 2. Remove 테스트 ---\n");
	printf("2-1. 삭제할 노드가 있는 경우 (20 삭제):\n");
	MyList->Remove(20);
	MyList->PrintList();
	printf("\n2-2. 삭제할 노드가 없는 경우 (99 삭제 시도):\n");
	MyList->Remove(99);
	MyList->PrintList();

	printf("\n--- 3. RemoveAt 테스트 ---\n");
	printf("3-1. 위치가 Size와 같거나 클 때:\n");
	MyList->RemoveAt(4); // 현재 크기는 4이므로, 인덱스 4는 범위를 벗어남
	MyList->RemoveAt(99);
	MyList->PrintList();
	printf("\n3-2. 정상적인 삭제 (위치 1의 30 삭제):\n");
	MyList->RemoveAt(1);
	MyList->PrintList();

	printf("\n--- 4. Search 테스트 ---\n");
	printf("4-1. 찾는 노드가 있는 경우 (10 탐색):\n");
	int ValueToFind = 10;
	ListNode* FoundNode = MyList->Search(ValueToFind);
	if (FoundNode != nullptr)
	{
		printf("결과: %d 값을 가진 노드를 찾았습니다. (주소: %p, 데이터: %d)\n", ValueToFind, (void*)FoundNode, FoundNode->Data);
	}
	else
	{
		printf("결과: %d 값을 가진 노드를 찾지 못했습니다.\n", ValueToFind);
	}
	printf("\n4-2. 찾는 노드가 없는 경우 (123 탐색):\n");
	ValueToFind = 123;
	FoundNode = MyList->Search(ValueToFind);
	if (FoundNode != nullptr)
	{
		printf("결과: %d 값을 가진 노드를 찾았습니다.\n", ValueToFind);
	}
	else
	{
		printf("결과: %d 값을 가진 노드를 찾지 못했습니다.\n", ValueToFind);
	}

	printf("\n--- 프로그램 종료 (소멸자 호출) ---\n");
	MyList->Clear();
	delete MyList;
	MyList = nullptr;
}

void Test0605_1::Fly()
{
	// 독수리처럼 날기
}

void Test0605_2::Fly()
{
	// 벌새처럼 날기
}
