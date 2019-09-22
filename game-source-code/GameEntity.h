#ifndef GAMEENTITY_H_INCLUDED
#define GAMEENTITY_H_INCLUDED

#include "EntityCoordinates.h"

class GameEntity
{
public:
    GameEntity(int xPosition, int yPosition, bool life, int numberOfLives);
    void setXposition(int x);
    void setYposition(int y);
    void giveEntityLife();
    void destroyEntity();
    bool isAlive() const;
    bool isEntityLifeDecreased();
    void resetLifeDecreasedFlag();
    int getNumberOfLives() const;
    EntityCoordinates getEntityCoordinates() const;

private:
    EntityCoordinates _coordinates;
    bool _life;
    int _numberOfLives;
    bool lifeDecreased;
};

#endif // GAMEENTITY_H_INCLUDED