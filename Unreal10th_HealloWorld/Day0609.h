#pragma once
class Day0609
{
public:
	void Day0609_Main();
	void Day0609_Stack();
	void Day0609_Queue();

private:
	void TestStack();
	void Reverse();
	void ReverseSTL();
	void TestQueue();
	void TestQueue2();
	void TestQueueSTL();
	void SwallowCopy();
};

// 큐(Queue)
// 특징
//	- 선입선출 구조(First In First Out, FIFO)
//	- 가장 먼저 들어온 데이터가 가장 먼저 나간다.(줄서기, 번호표 등)
//	- Rear에 데이터를 추가(Enqueue)하고 Front에서 데이터를 삭제(Dequeue).
// 장점
//	- 데이터가 들어온 순서대로 처리해야 할 때 유용함
//	- 대기표, 매칭 큐, 메세지 큐 등에 활용됨
// 단점
//	- 중간에 있는 데이터에는 접근하거나 탐색할 수 없음
//	- 활용도가 제한적

// 깊은 복사와 얕은 복사
// 깊은 복사(Deep Copy)
//	- 데이터의 완전한 사본을 만드는 복사
// 얕은 복사(Swallow Copy)
//	- 복사를 할 때 포인터의 경우 사본을 만들지 않고 주소만 복사하는 것