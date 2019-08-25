#ifndef LASER_H_INCLUDED
#define LASER_H_INCLUDED
#include "GameEntity.h"

class Laser : public GameEntity
{
public:
    Laser();
  virtual  void move(Direction _direction);

private:
    
};

#endif // LASER_H_INCLUDED