#ifndef ENTITYDRAWERPROXY_H_INCLUDED
#define ENTITYDRAWERPROXY_H_INCLUDED
#include "Alien.h"
#include "ImageDrawer.h"
#include "LaserCanon.h"
#include "LaserCanonShield.h"
#include "Laser.h"
#include <memory>
using std::shared_ptr;

class ImageDrawerProxy
{
public:
    ImageDrawerProxy(shared_ptr<ImageDrawer> imageDrawer);
    void _drawLaserCanons(const LaserCanon& _laserCanon1, const LaserCanon& _laserCanon2) const;
    void _drawLasers(const Laser& _laser1, const Laser& _laser2) const;
    void _drawAlienLasers(const Laser& _alienLaser) const;

    void _drawGreenAliens(const Alien& _alien, int spriteNumber);
    void _drawPurpleAliens(const Alien& _alien, int spriteNumber);
    void _drawRedAliens(const Alien& _alien, int spriteNumber);

    void _drawUpGreenAliens(const Alien& _alien, int spriteNumber);
    void _drawUpPurpleAliens(const Alien& _alien, int spriteNumber);
    void _drawUpRedAliens(const Alien& _alien, int spriteNumber);
    
    void _drawLaserCanonShields(const LaserCanonShield& _laserCanonShield);

    void _drawHomeScreen();
    void _drawGameWon();
    void _drawGameLost();

private:
    shared_ptr<ImageDrawer> _imageDrawer;
};

#endif // ENTITYDRAWERPROXY_H_INCLUDED