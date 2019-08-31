#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "GameEntity.h"
#include "Laser.h"

class Player : public GameEntity
{
public:
    Player(int x, int y);
    void shootLaser(int laser_number);
    void moveLaser();
    Laser getLaser(int laser_number) const;
    void update_Laser_position(int laser_number);
    virtual void move(Direction _direction);

private:
    Laser _laser;
    Laser _laser2;
};

#endif // PLAYER_H_INCLUDED