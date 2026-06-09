#pragma once

// 데이터는 int
class CircularQueue
{
public:
	void Enqueue(int InValue);
	int Dequeue();
	int Peek() const;
	void Print() const;
	
	static constexpr int MaxSize = 10;
	static constexpr int Empty = -1;

private:

	int Data[MaxSize];
	int Front = Empty;
	int Rear = Empty;

public:
	inline bool IsFull() const { return (Rear + 1) % MaxSize == Front; }	// Front와 Rear+1이 같으면 가득 차있다.
	inline bool IsEmpty() const { return Front == Empty; }	// 디큐할 때 Front와 Rear가 같으면 둘 다 Empty로 처리
	inline int GetSize() const { return (Rear - Front + MaxSize) % MaxSize + 1; }
};

class CircularQueue2
{
public:
	CircularQueue2(unsigned int InSize = 10);
	~CircularQueue2();

	// 얕은 복사로 인해 문제가 생길만한 클래스는 복사생성자와 복사대입연산자를 제거하는 것이 좋다.
	// 복사 생성자
	CircularQueue2(const CircularQueue2&) = delete;	// 기본적으로 만들어지는 복사 생성자를 제거하겠다.
	// 복사 대입 연산자.
	CircularQueue2& operator=(const CircularQueue2&) = delete;

	void Enqueue(int InValue);
	int Dequeue();
	int Peek() const;
	void Print() const;

	static constexpr int Empty = -1;


private:
	int* Data = nullptr;
	int Front = Empty;
	int Rear = Empty;
	int MaxSize = 0;

public:
	inline bool IsFull() const { return (Rear + 1) % MaxSize == Front; }	// Front와 Rear+1이 같으면 가득 차있다.
	inline bool IsEmpty() const { return Front == Empty; }	// 디큐할 때 Front와 Rear가 같으면 둘 다 Empty로 처리
	inline int GetSize() const { return (Rear - Front + MaxSize) % MaxSize + 1; }
};