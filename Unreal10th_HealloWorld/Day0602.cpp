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

void Tiger::MakeSound()
{
	printf("호랑이 : 어흥하고 소리를 냅니다.\n");
}

void Eagle::MakeSound()
{
	printf("독수리 : 빼액하고 소리를 냅니다.\n");
}

void Whale::MakeSound()
{
	printf("고래 : 고래하고 소리를 냅니다.\n");
}

void Day0602()
{
	//Day0602_class();

	// 간단 실습
	// Animal의 자식클래스 5개 이상 만들기.
	// 각 자식 클래스는 자신만의 기능이 있어야 한다.
	
	Day0602_virtual();
}

void Day0602_class()
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
}

void Day0602_virtual()
{
	Animal* Zoo[3] = { nullptr, };
	Zoo[0] = new Tiger("호랑이");
	Zoo[1] = new Eagle("독수리");
	Zoo[2] = new Whale("고래");

	for (Animal* anim : Zoo)
	{
		anim->ShowInfo();
		anim->MakeSound();
	}

	for (int i = 0; i < 3; i++)
	{
		delete Zoo[i];
		Zoo[i] = nullptr;
	}
}


void Eagle::Fly()
{
	printf("독수리가 하늘을 납니다.\n에너지가 %.0f만큼 감소합니다.\n", FlyEnergy);
	Energy -= FlyEnergy;
}

void Tiger::Roar()
{
	printf("호랑이가 울부짖습니다.\n");
}

void Whale::Swim()
{
	printf("고래가 해엄을 칩니다.\n");
}
