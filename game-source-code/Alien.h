#ifndef ALIEN_H_INCLUDED
#define ALIEN_H_INCLUDED
#include "EntityCoordinates.h"
#include "GameEntity.h"

class Alien : public GameEntity
{
public:
    Alien(int x, int y);
    virtual void move(Direction _direction);
   bool getAlienRightDirection() const;
   void setAlienRightDirection(bool rightDirection);

private:
    bool alienRightDirection;
};

#endif // ALIEN_H_INCLUDED