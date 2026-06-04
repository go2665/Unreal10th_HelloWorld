#include "Practice0604.h"
#include "Actor.h"

void Practice0604::Test()
{
	Actor* pTestActor1 = new Actor("테스터 1번", 300, 5, 15, 0.1f);
	Actor* pTestActor2 = new Actor("테스터 2번", 100, 5, 15, 0.1f);
	pTestActor1->PrintStatus();
	pTestActor2->PrintStatus();
	while (pTestActor2->IsAlive())
	{
		pTestActor1->Attack(pTestActor2);
	}

	delete pTestActor2;
	pTestActor2 = nullptr;
	delete pTestActor1;
	pTestActor1 = nullptr;
}
