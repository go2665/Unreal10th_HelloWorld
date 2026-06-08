#pragma once
#include "Position.h"

enum class CellType
{
	Out	= -1,	// 맵 내부가 아님
	Empty = 0,	// 빈셀
	Ship,		// 배가 배치된 셀
	Hit,		// 공격이 맞은 셀
	Miss		// 공격이 빗나간 셀
};

class Map
{
public:
	static constexpr int MapSize = 10;

	Map()
	{
		for (int y = 0; y < MapSize; y++)
		{
			for (int x = 0; x < MapSize; x++)
			{
				Cells[y][x] = CellType::Empty;
			}
		}
		// memset : 특정 메모리영역을 특정 값으로 채우는 C 함수
	}
	virtual ~Map() = default;

	virtual void PrintMap() const = 0;

	inline static bool IsValidPosition(int InX, int InY) 
	{
		return InX >= 0 && InX < MapSize && InY >= 0 && InY < MapSize;
	}

	inline CellType GetCellType(int InX, int InY) const
	{
		if (!IsValidPosition(InX, InY))
		{
			return CellType::Out;	// 범위 벗어남
		}
		return Cells[InY][InX];
	}
	inline CellType GetCellType(const Position& InPosition) const
	{
		return GetCellType(InPosition.X, InPosition.Y);
	}

	inline void SetCellType(int InX, int InY, CellType InType)
	{
		if (IsValidPosition(InX, InY))
		{
			Cells[InY][InX] = InType;
		}
	}
	inline void SetCellType(const Position& InPosition, CellType InType)
	{
		SetCellType(InPosition.X, InPosition.Y, InType);
	}

protected:
	CellType Cells[MapSize][MapSize];
};

