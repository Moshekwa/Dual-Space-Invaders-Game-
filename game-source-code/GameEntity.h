#ifndef GAMEENTITY_H_INCLUDED
#define GAMEENTITY_H_INCLUDED

#include "EntityCoordinates.h"
#include <memory>

using std::shared_ptr;

enum Direction { UP, DOWN, LEFT, RIGHT };

class GameEntity
{
public:
    GameEntity(int x, int y, int speed, bool _life);
    void setXposition(int x);
    void setYposition(int y);
    int getEntitySpeed() const;
    void setEntityLife(bool life);
    bool isAlive() const;
    EntityCoordinates getEntityCoordinates() const;
    virtual void move(Direction _direction) = 0;

private:

    EntityCoordinates _coordinates;
    int _entitySpeed;
    bool _life;
};

#endif // GAMEENTITY_H_INCLUDED