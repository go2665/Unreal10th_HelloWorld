#pragma once

const int InvalidPosition = -1;
const int InitHealth = 100;
const int InitMoney = 0;

struct Position
{
	int X = 0;
	int Y = 0;

	Position() = default;
	Position(int InX, int InY)
		: X(InX), Y(InY)
	{
	}

	Position operator+(const Position& InOther) const
	{
		return Position(X + InOther.X, Y + InOther.Y);
	}
	Position operator-(const Position& InOther) const
	{
		return Position(X - InOther.X, Y - InOther.Y);
	}
};