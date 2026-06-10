#pragma once
#include <type_traits>

template <typename T>
struct Coordinate
{
	T x;
	T y;

	// 기본 생성자
	Coordinate() : x{}, y{} {}

	// 매개변수 생성자
	Coordinate(T InX, T InY) : x(InX), y(InY) {}

	// printf를 사용하여 좌표를 출력하는 멤버 함수
	void Print() const
	{
		// 둘 다 C++17부터 지원. 프로젝트 속성에서 C++17 이상으로 설정 필요
		// if constexpr : 컴파일 타임에 타입 비교 후 true인 경우에만 코드 생성하고 else는 생성하지 않음
		// std::is_same_v : 두 타입이 같은지 비교하는 템플릿 (true/false). 
		if constexpr (std::is_same_v<T, int>) {
			printf("(%d, %d)\n", x, y);
		}
		else if constexpr (std::is_same_v<T, unsigned int>) {
			printf("(%u, %u)\n", x, y);
		}
		else if constexpr (std::is_same_v<T, float>) {
			printf("(%f, %f)\n", x, y);
		}
		else if constexpr (std::is_same_v<T, double>) {
			printf("(%lf, %lf)\n", x, y);
		}
		else {
			std::cout << "(" << x << ", " << y << ")" << std::endl;
		}
	}
};

// --- 전역 함수로 분리된 연산자 오버로딩 ---

// 덧셈 연산자 오버로딩 (전역 함수)
template <typename T>
Coordinate<T> operator+(const Coordinate<T>& Left, const Coordinate<T>& Right)
{
	return Coordinate<T>(Left.x + Right.x, Left.y + Right.y);
}

// 뺄셈 연산자 오버로딩 (전역 함수)
template <typename T>
Coordinate<T> operator-(const Coordinate<T>& Left, const Coordinate<T>& Right)
{
	return Coordinate<T>(Left.x - Right.x, Left.y - Right.y);
}

// 등호 연산자 오버로딩 (전역 함수)
template <typename T>
bool operator==(const Coordinate<T>& Left, const Coordinate<T>& Right)
{
	bool Result = false;
	if constexpr (std::is_same_v<T, float>) {
		float diffX = Left.x - Right.x;
		float diffY = Left.y - Right.y;
		if (diffX < 0) diffX *= -1;
		if (diffY < 0) diffY *= -1;
		Result = diffX < 0.001f && diffY < 0.001f;
	}
	else if constexpr (std::is_same_v<T, double>) {
		double diffX = Left.x - Right.x;
		double diffY = Left.y - Right.y;
		if (diffX < 0) diffX *= -1;
		if (diffY < 0) diffY *= -1;
		Result = diffX < 0.001f && diffY < 0.001f;
	}
	else {
		Result = ((Left.x == Right.x) && (Left.y == Right.y));
	}
	return Result;
}

// 부등호 연산자 오버로딩 (전역 함수)
template <typename T>
bool operator!=(const Coordinate<T>& Left, const Coordinate<T>& Right)
{
	// 이미 구현된 operator== 를 재사용합니다.
	return !(Left == Right);
}