#include "Utils.h"
#include <float.h>
#include <math.h>

bool IsFloatEqual(float Num1, float Num2)
{
	return fabsf(Num1 - Num2) <= 0.001f;
}
