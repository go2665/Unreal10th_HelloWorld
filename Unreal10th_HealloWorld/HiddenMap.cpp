#include "HiddenMap.h"
#include <iostream>

void HiddenMap::PrintMap() const
{
	printf("Enemy ships location : \n");
	printf("   ");
	for (int i = 0; i < Map::MapSize; i++)
	{
		printf("%2d ", i);
	}
	printf("\n");

	for (int y = 0; y < Map::MapSize; y++)
	{
		printf("%2d ", y);
		for (int x = 0; x < Map::MapSize; x++)
		{
			if (Cells[y][x] == CellType::Ship)
			{
				printf(" S ");	// 배가 배치되어 있음을 표시
			}
			else
			{
				printf(" . ");	// 빈 공간임을 표시
			}
		}
		printf("\n");
	}
}
