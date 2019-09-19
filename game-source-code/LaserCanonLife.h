#ifndef LASERCANONLIFE_H_INCLUDED
#define LASERCANONLIFE_H_INCLUDED
#include "GameEntity.h"

class LaserCanonLife : public GameEntity
{
public:
	LaserCanonLife(int xPosition, int yPosition, bool life);
	~LaserCanonLife();
	static int getNumberOfLives();
	
	void setEntityLife();
	
private:
	const static int numberOfLives;
};

#endif // LASERCANONLIFE_H_INCLUDED