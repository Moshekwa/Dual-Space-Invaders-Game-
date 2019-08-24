#include "Player.h"

Player::Player(int _xPosition, int _yPosition, bool life)
{
    xPosition = _xPosition;
    yPosition = _yPosition;
    Life = life;
}

void Player::setXposition(int x)
{
    xPosition = x;
}
void Player::setYposition(int y)
{
    yPosition = y;
}
void Player::move(int x, int y)
{
    setXposition(x);
    setYposition(y);
}

int Player::getXposition()
{
    return xPosition;
}
int Player::getYposition()
{
    return yPosition;
}

void Player::setLife(bool _life){
    Life = _life;
}

bool Player::getLife(){
    return Life;
}