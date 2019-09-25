#include "GameEntity.h"

GameEntity::GameEntity(int xPosition, int yPosition, bool life, int numberOfLives)
    : _Xposition{ xPosition }
    , _Yposition{ yPosition }
    , _life{ life }
    , _numberOfLives{ numberOfLives }
{
    if(xPosition < 0 || xPosition > 400 || yPosition < 0 || yPosition > 500) {
        throw InvalidEntityPositions{};
    }

    if(numberOfLives == 0) {
        throw InvalidEntityPositions{};
    }
}

void GameEntity::setXposition(int x)
{
    if(x >= 0 || x <= 400) {
        _Xposition = x;
    }
}

void GameEntity::setYposition(int y)
{
    if(y >= 0 || y <= 500) {
        _Yposition = y;
    }
}

tuple<int, int> GameEntity::entityPosition() const
{
    return { _Xposition, _Yposition };
}

void GameEntity::giveEntityLife()
{
    _life = true;
}

void GameEntity::destroyEntity()
{
    if(getNumberOfLives() != 0) {
        _numberOfLives = _numberOfLives - 1;
        if(getNumberOfLives() == 0) {
            _life = false;
        }
    } else {
        _life = false;
    }
}

bool GameEntity::isAlive() const
{
    return _life;
}

int GameEntity::getNumberOfLives() const
{
    return _numberOfLives;
}
