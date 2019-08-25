#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "GameEntity.h"

class Player : public GameEntity
{
public:
    Player(int x, int y);
  virtual  void move(Direction _direction);

private:
    
};

#endif // PLAYER_H_INCLUDED