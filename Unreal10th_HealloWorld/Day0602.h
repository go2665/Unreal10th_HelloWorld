#pragma once
#include <iostream>
#include <string>

void Day0602();
void Day0602_class();
void Day0602_virtual();
// 객체 지향
//	- 프로그래밍 패러다임 중 하나.
//	- 객체(Object)를 만들고 객체간의 상호작용으로 프로그램이 돌아가게 만드는 방식.
//	- 4대 특성
//		- 추상화
//			- 불필요한 세부사항을 숨기고, 핵심적인 부분만 말하는 것
//			- 중요한 개념과 기능만을 드러내는 것(상위 개념으로 묶기)
//			- 코드의 복잡성을 낮출 수 있다.
//		- 캡슐화
//			- 접근제한자를 통한 데이터의 접근 제어.
//			- 몰라도 되는 것은 안보이게 하는 것.
//			- 데이터를 보호하고 코드의 안정성을 높힌다. 그리고 결합도도 낮춘다.
//			- 접근제한자를 이용해 캡슐화를 한다.
//		- 상속
//			- 부모클래스의 데이터와 기능을 물려받는 자식클래스를 만드는 것.
//			- 코드의 재사용성이 높아진다. 계층 구조가 형성된다.(위 아래가 생긴다)
//		- 다형성
//			- 동일한 인터페이스를 통해 다양한 처리를 하는 것.
//			- 가상함수의 오버라이드를 통한 다형성 구현

// 클래스
//	- 객체(Object)를 만들기 위한 설계도
//	- 객체가 가지게 될 상태(데이터, 변수)와 동작(기능, 함수)을 하나로 묶어 놓은 것
//	- 구성요소(Member)
//		- 생성자
//			- 구조체와 같이 객체를 생성했을 때 자동 호출되는 함수 같은 것
//			- 예 : 클래스이름()
//		- 소멸자
//			- 구조체나 클래스의 객체가 해제될 때(delete가 되거나, 지역변수일 때 함수 종료되는 시점) 자동으로 호출되는 함수 같은 것
//			- 목적
//				- 객체가 사용하던 자원을 깨끗하게 정리하는 역할
//				- 주로 객체가 동적할당한 메모리를 해제하는데 사용.
//				- 그 외 기타 자원들(파일, 네트워크 연결 닫기)도 이곳에서 정리.
//			- 예 : ~클래스이름()
//		- 맴버 변수
//			- 객체의 상태나 데이터를 저장하는 변수
//			- 속성, 필드라고도 한다.
//		- 맴버 함수
//			- 객체가 할 수 있는 동작이나 기능을 정의한 함수
//			- 메서드(Method)라고도 한다.
//	- 객체, 인스턴스(Instance)		
//		- 특정 클래스를 이용해 실제 메모리에 할당된 실체

// 접근제한자(Access Modifier)
//	- 특정 객체의 내부를 누구까지 볼 수 있을 것인가를 설정
//	- public, protected, private
//		- public : public맴버는 모두에게 공개 되어 있다. 구조체는 따로 설정 안하면 public.
//		- protected : protected맴버는 상속된 자식(파생) 클래스까지는 볼 수 있다.
//		- private : private맴버는 자기 자신만 볼 수 있다. 클래스는 따로 설정 안하면 private.

// 상속
//	- 부모 클래스의 내용을 물려받는 행동(자식은 보모 클래스를 확장/파생 시킨다)
//	- 특징
//		- 코드 재사용성 증가
//		- 계층구조로 객체들간의 관계를 명확히 함
//		- 부모 클래스의 포인터나 참조로 자식 클래스를 다룰 수 있다.

// 가상함수
//	- virtual 키워드 사용
//	- 함수를 선언할 때 가상함수로 만들 맴버 함수 앞에서 붙인다.
//	- 가상함수가 있는 클래스를 상속받은 자식클래스는 해당함수를 override(덮어쓰기) 할 수 있다.
//  - 상속하거나 상속받았는데 소멸자를 만들었으면 무조건 virtual을 붙여라.
//	- 가상 함수처리를 위해서 가상 테이블(vtable)을 사용한다. 가상함수가 하나 이상 있을 때만 만들어짐.

class Animal
{
	// 맴버 변수
protected:
	// 동물의 이름
	std::string Name = "동물";	
	// 동물의 나이
	int Age = 0;
	// 동물의 현재 에너지
	float Energy = 100.0f;
	// 동물의 최대 에너지
	float MaxEnegy = 100.0f;

public:
	Animal() = default;
	Animal(const std::string& InName)
		:Name(InName)
	{ }
	//{
	//	// 생성자
	//}

	~Animal() = default;
	//{
	//	// 소멸자
	//}

	// 맴버 함수
	void Move();		// 움직이기
	virtual void MakeSound();	// 소리내기(가상함수)
	void Eat();			// 먹기
	void Sleep();		// 자기
	void ShowInfo();	// 자신의 모든 정보 출력

protected:
	// 움직일 때 사용하는 에너지
	const float MoveEnergy = 10.0f;
	// 먹으면 회복되는 에너지
	const float EatEnergy = 30.0f;

public:
	// getter/setter
	//int GetAge() const;	// 여기서 const는 함수내에서 다른 맴버 변수를 수정하지 않겠다라는 의미
	inline int GetAge() const { return Age; }		// Getter와 Setter는 프로그래머의 의도에 따라 사용처를 한정할 수 있어 좋다.
	inline void SetAge(int InAge) { Age = InAge; }
};


class IFlyable	// IFlyable이라는 인터페이스가 있는데
{
public:
	virtual void Fly() = 0;	// 날기라는 함수를 가진다.
	virtual ~IFlyable() = default;
};

class ICanSwim
{
public :
	virtual void Swim() = 0;
	virtual ~ICanSwim() = default;
};

class ICanBattle
{
public:
	virtual void Attack(ICanBattle* InTarget) = 0;
	virtual void Defence(int InDamage) = 0;

	virtual int GetHealth() const = 0;
};
	
// 간단 실습
//	- 동물 클래스 만들어보기
//		- 움직이면 에너지를 소비한다.
//		- 소리를 지를 수 있다.
//		- 먹을 수 있다.(먹으면 에너지가 증가한다.)
//		- 잠을 잘 수 있다.(잠을 자면 나이가 증가하고 에너지가 완전 회복된다.)
//		- 자신의 모든 정보를 출력할 수 있다.

class Eagle : public Animal, public IFlyable
{
public:
	Eagle()
		:Animal()
	{	}
	Eagle(const std::string& InName)
		:Animal(InName)
	{   }
	virtual ~Eagle() = default;			// 상속하거나 상속받았는데 소멸자를 만들었으면 무조건 virtual을 붙여라.

	virtual void Fly() override;
	virtual void MakeSound() override;	// 가상함수를 덮어쓰기 하겠다.

private:
	const float FlyEnergy = 20.0f;
};

class Tiger : public Animal, public ICanBattle
{
public:
	Tiger()
		:Animal()
	{
	}
	Tiger(const std::string& InName)
		:Animal(InName)
	{
	}
	virtual ~Tiger() = default;

	void Roar();
	virtual void MakeSound() override;	// 가상함수를 덮어쓰기 하겠다.
	

	// ICanBattle을(를) 통해 상속됨
	virtual void Attack(ICanBattle* InTarget) override;
	virtual void Defence(int InDamage) override;
	virtual int GetHealth() const override { return 100; }

};

class Whale : public Animal, public ICanSwim
{
public:
	Whale()
		:Animal()
	{
	}
	Whale(const std::string& InName)
		:Animal(InName)
	{
	}
	virtual ~Whale() = default;

	virtual void Swim() override;
	virtual void MakeSound() override;	// 가상함수를 덮어쓰기 하겠다.
};

// 간단 실습
// Move함수를 가상함수로 만들어 처리하기
//	- 고래는 수영
//	- 독수리는 날기
//	- 호랑이는 뛰기