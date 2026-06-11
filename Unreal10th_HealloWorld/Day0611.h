#pragma once
#include <vector>

class Day0611
{
public:
	void Day0611_Main();

	void TestTLinkedList();
	void TestTLinkedList2();
	void TestTStack();

	void TestSTL_Algorithm();
	void PrintVector(const std::vector<int>& InData);
	void TestLambda();

	bool Desc(int a, int b) { return a > b; };
};


// STL(Standard Template Library)
// - C++의 기본적인 라이브러리
// - 구성요소
//		- 컨테이너 : vector, map, unordered_map, set
//		- 알고리즘 : 컨테이너에 들어있는 데이터를 여러 방식으로 조작하는 방법들(정렬, 탐색 등등)
//		- 반복자(Iterator) : 컨테이너의 특정 위치를 가리키는 변수
//		- 함수객체(Functor) : 알고리즘의 정렬 순서 같은 것을 커스텀으로 지정할 수 있게 됨(일반적으로 람다식으로 만듬)

// 람다(Lambda)
//	- 익명함수
//	- 짧은 코드의 함수를 코드 내에서 바로 정의하고 사용(1회용)
//	- 기본 구조
//		[캡쳐](매개변수) -> 반환타입 { 함수 본문 }
//		1. [캡처](Capture Clause): 람다 함수 외부의 변수에 어떻게 접근할지 지정하는 부분
//			-[]: 외부 변수에 접근하지 않습니다.
//			-[&]: 외부의 모든 변수를 참조(reference)로 캡처합니다. (값 변경 가능)
//			-[=]: 외부의 모든 변수를 복사(copy)로 캡처합니다. (값 변경 불가, 읽기 전용)
//			-[this]: 클래스 멤버 변수와 멤버 함수에 접근할 수 있습니다.
//			-[변수명]: 특정 변수만 복사로 캡처합니다.예: [myVar]
//			-[&변수명]: 특정 변수만 참조로 캡처합니다.예: [& myVar]
//			-[=, &변수명]: 변수명은 참조로, 나머지는 복사로 캡처합니다.
//		2. (매개변수)(Parameter List) : 일반 함수처럼 람다 함수가 받을 인자를 정의하는 부분입니다.
//		3. - > 반환타입(Return Type) : 람다 함수의 반환 타입을 명시적으로 지정합니다. 대부분의 경우 컴파일러가 return 문을 보고 자동으로 추론하므로 생략할 수 있습니다.
//		4. { 함수 본문 }(Function Body) : 실제 실행될 코드를 작성하는 부분입니다.
//	- 주의사항
//		명시적으로 캡쳐하는 것이 좋다(대규모 캡쳐는 퍼포먼스 문제가 있을 수 있다. &,=,this)
//		지연 실행시 참조 캡쳐와 포인터 캡쳐는 문제가 될 수 있다(댕글링 포인터나 참조)
//		값 캡쳐는 피하는 것이 좋다(퍼포먼스 문제)