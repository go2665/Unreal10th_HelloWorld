#pragma once
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
	bool operator==(const Position& InOther) const
	{
		return this->X == InOther.X && this->Y == InOther.Y;
	}
	bool operator!=(const Position& InOther) const
	{
		//return this->X != InOther.X || this->Y != InOther.Y;	// 비추천
		return !(*this == InOther);
	}
};