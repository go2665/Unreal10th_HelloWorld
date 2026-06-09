#pragma once

// 데이터는 int
class CircularQueue
{
public:
	void Enqueue(int InValue);
	int Dequeue();
	int Peek() const;
	void Print() const;
	
private:
	static constexpr int MaxSize = 10;
	static constexpr int Empty = -1;

	int Data[MaxSize];
	int Front = Empty;
	int Rear = Empty;

public:
	inline bool IsFull() const { return (Rear + 1) % MaxSize == Front; }	// Front와 Rear+1이 같으면 가득 차있다.
	inline bool IsEmpty() const { return Front == Empty; }	// 디큐할 때 Front와 Rear가 같으면 둘 다 Empty로 처리
	inline int GetSize() const { return (Rear - Front + MaxSize) % MaxSize + 1; }
};

