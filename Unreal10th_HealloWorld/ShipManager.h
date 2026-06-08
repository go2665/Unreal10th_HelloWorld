#pragma once
#include "Ship.h"

class HiddenMap;

class ShipManager
{
public:
	ShipManager() = default; 

	void PlaceAllShips(HiddenMap* InMap);	// 모든 배를 맵에 배치

	bool AttackProcess(const Position& InHitPos);	// 특정 위치에 공격을 함. 거기에 배가 있으면 true 리턴
	
	inline bool WasShipJustSunk() const { return ShipJustSunk; }	// 배가 방금 공격 당했는지를 확인하는 함수
	inline bool IsAllSunk() const { return SunkShipCount >= ShipTypeCount; }	// 모든 배가 침몰되었는지 확인하는 함수
	inline int GetAliveShipCount() const { return ShipTypeCount - SunkShipCount; }	// 아직 침몰하지 않은 배의 수

private:
	static constexpr int ShipTypeCount = 4;
	
	Ship Ships[ShipTypeCount];	// 적 함선들

	int SunkShipCount = 0;		// 침몰한 함선 수
	bool ShipJustSunk = false;	// 배가 이번 공격으로 침몰했는지 여부

	bool CanPlaceShip(int InX, int InY, int InSize, bool InIsHorizontal, const HiddenMap* InMap) const;
};

