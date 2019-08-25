#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "GameEntity.h"
#include "Laser.h"

class Player : public GameEntity
{
public:
    Player(int x, int y);
    void shoot();
    Laser getLaser();
  virtual  void move(Direction _direction);

private:
    Laser _laser;
};

#endif // PLAYER_H_INCLUDED