#include "Day0602.h"

void Animal::Move()	// Animal클래스의 맴버함수인 Move
{
	printf("이동합니다.\n");
	printf("에너지가 %.0f만큼 감소합니다.\n", MoveEnergy);
	Energy -= MoveEnergy;	// 움직이면 에너지 감소
}

void Animal::MakeSound()
{
	printf("으르렁하고 소리를 냅니다.\n");
}

void Animal::Eat()
{
	printf("먹습니다.\n");
	printf("에너지가 %.0f만큼 증가합니다.\n", EatEnergy);
	Energy += EatEnergy;
}

void Animal::Sleep()
{
	printf("쿨쿨잡니다.\n에너지가 완전 회복합니다.\n나이가 1살 증가합니다.\n");
	Energy = MaxEnegy;
	Age++;
}

void Animal::ShowInfo()
{
	printf("-------------------------------------\n");
	printf("이름\t: %s\n", Name.c_str());
	printf("나이\t: %d살\n", Age);
	printf("에너지\t: %.0f / %.0f\n", Energy, MaxEnegy);
	printf("-------------------------------------\n");

}

void Day0602()
{
	Animal* MyAnimal = new Animal();
	MyAnimal->ShowInfo();
	MyAnimal->Move();
	MyAnimal->MakeSound();
	MyAnimal->ShowInfo();
	MyAnimal->Move();
	MyAnimal->Move();
	MyAnimal->Move();
	MyAnimal->Move();
	MyAnimal->ShowInfo();
	MyAnimal->Eat();
	MyAnimal->ShowInfo();
	MyAnimal->Sleep();
	MyAnimal->ShowInfo();

	//MyAnimal->GetAge();
	//MyAnimal->Age;
	
	delete MyAnimal;
	MyAnimal = nullptr;

	Eagle* MyEagle = new Eagle("독수리");
	MyEagle->Fly();
	MyEagle->ShowInfo();
	
	Animal* pEagle = MyEagle;	// Animal이 Eagle의 부모이기 때문에 저장 가능하다.
	// pEagle는 Animal*이기 때문에 Ealge만의 맴버에 접근은 안된다.(하려면 캐스팅해야 한다.)	
	// (Eagle*)pEagle;	// C스타일의 캐스팅. 위험.
						//int* a;
						//Eagle* Test = (Eagle*)a; // 문법적으로 가능
	// dynamic_cast. C++ 스타일의 캐스팅. 안전. 느리다.
	
	delete MyEagle;
	MyEagle = nullptr;

	//pEagle->ShowInfo();	// pEagle는 댕글링 포인터다.(이미 유효하지 않은 주소)

	// 간단 실습
	// Animal의 자식클래스 5개 이상 만들기.
	// 각 자식 클래스는 자신만의 기능이 있어야 한다.

}


void Eagle::Fly()
{
	printf("하늘을 납니다.\n에너지가 %.0f만큼 감소합니다.\n", FlyEnergy);
	Energy -= FlyEnergy;
}
