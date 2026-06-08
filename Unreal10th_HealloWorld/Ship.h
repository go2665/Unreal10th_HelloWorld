#pragma once
#include "Position.h"
class Ship
{
public:
	static constexpr int MaxShipSize = 5;

	// 배의 위치 결정(초기화에 가까움)
	void Initialize(int InSize, const Position* InPosition);

	// 배가 맞았는지 확인하고 맞았으면 맞은 처리
	bool HitCheckAndProcess(const Position& InHitPos);

	// 침몰여부 확인하는 함수
	inline bool IsSunk() const { return Hits >= Size; }

private:
	int Size = 0;						// 배의 크기
	Position Positions[MaxShipSize];	// 배가 배지된 좌표 정보
	int Hits = 0;						// 맞은 회수
};

