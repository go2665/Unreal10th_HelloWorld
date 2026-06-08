#include "PlayerMap.h"
#include <iostream>

void PlayerMap::PrintMap() const
{
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
			switch (Cells[y][x])
			{
			case CellType::Hit:
				printf(" O ");
				break;
			case CellType::Miss:
				printf(" X ");
				break;
			default: // 나머지는 전부 빈공간으로 처리
				printf(" . ");	// 빈 공간임을 표시
				break;
			}
		}
		printf("\n");
	}
}
