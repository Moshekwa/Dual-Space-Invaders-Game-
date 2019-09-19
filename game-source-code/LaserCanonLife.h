#ifndef LASERCANONLIFE_H_INCLUDED
#define LASERCANONLIFE_H_INCLUDED
#include "GameEntity.h"
#include "LaserCanon.h"

class LaserCanonLife : public GameEntity
{
public:
	LaserCanonLife(int xPosition, int yPosition, bool life, int numberOfLives);
	~LaserCanonLife();
    
   

private:
	
};

#endif // LASERCANONLIFE_H_INCLUDED