#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "GameEntity.h"
#include "Laser.h"

class Player : public GameEntity
{
public:
    Player(int x, int y);
    void shootLaser();
    void moveLaser();
    Laser getLaser() const;
	void update_Laser_position();
    virtual void move(Direction _direction);

private:
    Laser _laser;
};

#endif // PLAYER_H_INCLUDED