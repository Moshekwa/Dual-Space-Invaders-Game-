#ifndef GAMEENTITY_H_INCLUDED
#define GAMEENTITY_H_INCLUDED

#include "EntityCoordinates.h"

class GameEntity
{
public:
    GameEntity(int xPosition, int yPosition, int entitySpeed, bool life);
    void setXposition(int x);
    void setYposition(int y);
    int getEntitySpeed() const;
    void giveEntityLife();
    void destroyEntity();
    bool isAlive() const;
    EntityCoordinates getEntityCoordinates() const;

private:
    EntityCoordinates _coordinates;
    int _entitySpeed;
    bool _life;
};

#endif // GAMEENTITY_H_INCLUDED