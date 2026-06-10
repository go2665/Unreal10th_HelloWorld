#include "Day0610.h"
#include "BitFlag.h"

void Day0610::TestMain()
{
	TestTemplateClass();
}

void Day0610::TestTemplateClass()
{
	TestEnumClass Test1 = TestEnumClass::Up;
	TestEnumClass Test2 = TestEnumClass::Down;
	TestEnumClass Test3 = Test1 | Test2;
	//TestEnumClass Test4 = Test1 & Test2;

	int i = 0;
}
