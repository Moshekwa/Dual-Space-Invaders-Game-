#ifndef GAMEENTITY_H_INCLUDED
#define GAMEENTITY_H_INCLUDED

#include "EntityCoordinates.h"

class GameEntity
{
public:
    GameEntity(int xPosition, int yPosition, bool life);
    void setXposition(int x);
    void setYposition(int y);
    void giveEntityLife();
    void destroyEntity();
    bool isAlive() const;
    EntityCoordinates getEntityCoordinates() const;

private:
    EntityCoordinates _coordinates;
    bool _life;
};

#endif // GAMEENTITY_H_INCLUDED