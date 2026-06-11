#include "Day0611.h"
#include "TLinkedList.h"
#include "TFixedStack.h"
#include <vector>
#include <algorithm>
#include <functional>

bool DescGlobal(int a, int b) 
{ 
	return a > b; 
};

void Day0611::Day0611_Main()
{
	//TestTLinkedList();
	//TestTLinkedList2();
	//TestTStack();
	//TestSTL_Algorithm();
	TestLambda();
}

void Day0611::TestTLinkedList()
{
	TLinkedList<int>* MyList = nullptr;
	MyList = new TLinkedList<int>();

	printf("--- 초기 리스트 생성 ---\n");
	MyList->Add(10);
	MyList->Add(20);
	MyList->Add(30);
	MyList->PrintList();

	printf("\n--- 1. InsertAt 테스트 ---\n");
	printf("1-1. 위치가 Size보다 클 때 (마지막에 추가):\n");
	MyList->InsertAt(40, 100);
	MyList->PrintList();
	printf("\n1-2. 정상적인 추가 (위치 0에 5 추가, 위치 2에 15 추가):\n");
	MyList->InsertAt(5, 0);
	MyList->PrintList();
	MyList->InsertAt(15, 2);
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
	MyList->RemoveAt(5); // 현재 크기는 5이므로, 인덱스 5는 범위를 벗어남
	MyList->RemoveAt(99);
	MyList->PrintList();
	printf("\n3-2. 정상적인 삭제 (위치 1의 10 삭제):\n");
	MyList->RemoveAt(1);
	MyList->PrintList();

	printf("\n--- 4. Search 테스트 ---\n");
	printf("4-1. 찾는 노드가 있는 경우 (30 탐색):\n");
	int ValueToFind = 30;
	TListNode<int>* FoundNode = MyList->Search(ValueToFind);
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
	MyList->PrintList();
	delete MyList;
	MyList = nullptr;
}

void Day0611::TestTLinkedList2()
{
	TLinkedList<float>* MyList = nullptr;
	MyList = new TLinkedList<float>();

	printf("--- 초기 리스트 생성 ---\n");
	MyList->Add(10.0f);
	MyList->Add(20.0f);
	MyList->Add(30.0f);
	MyList->PrintList();

	printf("\n--- 1. InsertAt 테스트 ---\n");
	printf("1-1. 위치가 Size보다 클 때 (마지막에 추가):\n");
	MyList->InsertAt(40.0f, 100);
	MyList->PrintList();
	printf("\n1-2. 정상적인 추가 (위치 0에 5 추가, 위치 2에 15 추가):\n");
	MyList->InsertAt(5.0f, 0);
	MyList->PrintList();
	MyList->InsertAt(15.0f, 2);
	MyList->PrintList();

	printf("\n--- 2. Remove 테스트 ---\n");
	printf("2-1. 삭제할 노드가 있는 경우 (20 삭제):\n");
	MyList->Remove(20.0f);
	MyList->PrintList();
	printf("\n2-2. 삭제할 노드가 없는 경우 (99 삭제 시도):\n");
	MyList->Remove(99.0f);
	MyList->PrintList();

	printf("\n--- 3. RemoveAt 테스트 ---\n");
	printf("3-1. 위치가 Size와 같거나 클 때:\n");
	MyList->RemoveAt(5); // 현재 크기는 5이므로, 인덱스 5는 범위를 벗어남
	MyList->RemoveAt(99);
	MyList->PrintList();
	printf("\n3-2. 정상적인 삭제 (위치 1의 10 삭제):\n");
	MyList->RemoveAt(1);
	MyList->PrintList();

	printf("\n--- 4. Search 테스트 ---\n");
	printf("4-1. 찾는 노드가 있는 경우 (30 탐색):\n");
	float ValueToFind = 30.0f;
	TListNode<float>* FoundNode = MyList->Search(ValueToFind);
	if (FoundNode != nullptr)
	{
		std::cout << "결과: " << ValueToFind << " 값을 가진 노드를 찾았습니다. (주소: " 
			<< (void*)FoundNode << ", 데이터: " << FoundNode->Data << ")" << std::endl;
	}
	else
	{
		std::cout << "결과: " << ValueToFind << " 값을 가진 노드를 찾지 못했습니다.\n";
	}
	printf("\n4-2. 찾는 노드가 없는 경우 (123 탐색):\n");
	ValueToFind = 123.0f;
	FoundNode = MyList->Search(ValueToFind);
	if (FoundNode != nullptr)
	{
		std::cout << "결과: " << ValueToFind << " 값을 가진 노드를 찾았습니다.\n";

	}
	else
	{
		std::cout << "결과: " << ValueToFind << " 값을 가진 노드를 찾지 못했습니다.\n";
	}

	printf("\n--- 프로그램 종료 (소멸자 호출) ---\n");
	MyList->Clear();
	MyList->PrintList();
	delete MyList;
	MyList = nullptr;
}

void Day0611::TestTStack()
{
	TFixedStack<int> TestStack1;	// 10개짜리	
	TestStack1.Push(10);
	TestStack1.Push(20);
	TestStack1.Push(30);
	TestStack1.Push(40);
	TestStack1.Push(50);
	TestStack1.Push(15);
	TestStack1.Push(25);
	TestStack1.Push(35);
	TestStack1.Push(45);
	TestStack1.Push(55);
	TestStack1.Push(100);

	int Value = *(TestStack1.Top());
	TestStack1.Pop();
	Value = *(TestStack1.Top());
	TestStack1.Pop();
	Value = *(TestStack1.Top());
	TestStack1.Pop();
	Value = *(TestStack1.Top());
	TestStack1.Pop();
	Value = *(TestStack1.Top());
	TestStack1.Pop();
	Value = *(TestStack1.Top());

	TFixedStack<float, 3> TestStack2;	// 3개짜리
	TestStack2.Push(10.0f);
	TestStack2.Push(20.0f);
	TestStack2.Push(30.0f);
	TestStack2.Push(40.0f);
	TestStack2.Pop();
	TestStack2.Pop();
	TestStack2.Pop();
	TestStack2.Pop();
}

void Day0611::TestSTL_Algorithm()
{
	std::vector<int> Datas = { 10, 35, 55, 22, 47 };
	PrintVector(Datas);

	// 데이터 찾기
	std::vector<int>::iterator findIter = std::find(Datas.begin(), Datas.end(), 55);
	if (findIter != Datas.end())
	{
		printf("%d를 찾았다.\n", (*findIter));
	}
	else
	{
		printf("찾는 수가 없다.\n");	// end는 (*findIter)이렇게 접근 할 수 없음
	}
	findIter = std::find(Datas.begin(), Datas.end(), 100);
	if (findIter != Datas.end())
	{
		printf("%d를 찾았다.\n", (*findIter));
	}
	else
	{
		printf("찾는 수가 없다.\n");	
	}

	// 정렬하기
	std::sort(Datas.begin(), Datas.end());
	PrintVector(Datas);

	// 이진 탐색으로 찾기
	if (std::binary_search(Datas.begin(), Datas.end(), 55))
	{
		printf("%d를 찾았다.\n", 55);
	}
	else
	{
		printf("찾는 수가 없다.\n");	// end는 (*findIter)이렇게 접근 할 수 없음
	}
}

void Day0611::PrintVector(const std::vector<int>& InData)
{
	printf("Data : ");
	for (int e : InData)
	{
		printf("%d ", e);
	}
	printf("\n");
}

void Day0611::TestLambda()
{
	std::vector<int> Datas = { 10, 35, 55, 22, 47 };
	PrintVector(Datas);
	std::sort(Datas.begin(), Datas.end());
	PrintVector(Datas);
	// 맴버 함수 사용
	//std::sort(Datas.begin(), Datas.end(), 
	//	std::bind(&Day0611::Desc, this, std::placeholders::_1, std::placeholders::_2));
	//std::sort(Datas.begin(), Datas.end(), [this](int a, int b) { return this->Desc(a, b); });

	// 전역 함수 사용
	//std::sort(Datas.begin(), Datas.end(), DescGlobal);
	
	// 람다 사용
	//std::sort(Datas.begin(), Datas.end(), [](int a, int b) {return a > b; });
	PrintVector(Datas);

	int Line = 30;
	std::sort(Datas.begin(), Datas.end());
	auto iter = std::find_if(Datas.begin(), Datas.end(),
		[Line](int n) {
			return n > Line;
		});
	printf("%d보다 큰 첫번째 숫자는 %d입니다.\n", Line, *iter);
}
