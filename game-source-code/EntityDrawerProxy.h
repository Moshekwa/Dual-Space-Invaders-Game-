#ifndef ENTITYDRAWERPROXY_H_INCLUDED
#define ENTITYDRAWERPROXY_H_INCLUDED
#include "Alien.h"
#include "EntityDrawer.h"
#include "LaserCanon.h"
#include <memory>
using std::shared_ptr;

class EntityDrawerProxy
{
public:
    EntityDrawerProxy(shared_ptr<EntityDrawer> entityDrawer);
    void _drawLaserCanonsAndLasers(const LaserCanon& _laserCanon1, const LaserCanon& _laserCanon2) const;

    void _drawGreenAliens(const Alien& _alien, int spriteNumber);
    void _drawPurpleAliens(const Alien& _alien, int spriteNumber);
    void _drawRedAliens(const Alien& _alien, int spriteNumber);

    void _drawUpGreenAliens(const Alien& _alien, int spriteNumber);
    void _drawUpPurpleAliens(const Alien& _alien, int spriteNumber);
    void _drawUpRedAliens(const Alien& _alien, int spriteNumber);

    void _drawHomeScreen();
    void _drawGameWon();
    void _drawGameLost();

private:
    shared_ptr<EntityDrawer> _entityDrawer;
};

#endif // ENTITYDRAWERPROXY_H_INCLUDED