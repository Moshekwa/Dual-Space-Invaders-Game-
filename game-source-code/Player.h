#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "GameEntity.h"
#include "Laser.h"

class Player : public GameEntity
{
public:
    Player(int x, int y);
    void shootLaser();
    void shootLaser2();
    void moveLaser();
    Laser getLaser() const;
    Laser getLaser2() const;
    void update_Laser_position();
    void update_Laser2_position();
    virtual void move(Direction _direction);

private:
    Laser _laser;
    Laser _laser2;
};

#endif // PLAYER_H_INCLUDED