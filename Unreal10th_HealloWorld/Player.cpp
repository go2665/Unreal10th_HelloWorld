#include "Player.h"

void Player::Attack(Actor* InTarget) const
{
	printf("당신이 공격합니다.\n");
	Actor::Attack(InTarget);	// Player가 상속받은 Actor 클래스의 Attack 함수 사용하기
}

void Player::PrintStatus() const
{
	Actor::PrintStatus();
	printf("Money : %6d\n", Money);
	printf("-------------------------------------------\n");
}
