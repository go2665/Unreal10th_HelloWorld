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