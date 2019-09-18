#ifndef MOVINGENTITY_H_INCLUDED
#define MOVINGENTITY_H_INCLUDED
#include "GameEntity.h"

enum Direction { UP, DOWN, LEFT, RIGHT };

class MovingEntity : public GameEntity
{
public:
    MovingEntity(int xPosition, int yPosition, int entitySpeed, bool life);
    int getEntitySpeed() const;
    virtual void move(Direction _direction) = 0;
    
private:
    int _entitySpeed;
};

#endif // MOVINGENTITY_H_INCLUDED