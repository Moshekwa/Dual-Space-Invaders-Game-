#include "ImageDrawerProxy.h"

ImageDrawerProxy::ImageDrawerProxy(shared_ptr<ImageDrawer> imageDrawer)
    : _imageDrawer{ imageDrawer }
{
}

void ImageDrawerProxy::_drawLaserCanons(const LaserCanon& _laserCanon1, const LaserCanon& _laserCanon2) const
{

    if(_laserCanon1.isAlive()) {
        _imageDrawer->drawLaserCanon(_laserCanon1);
    }
    if(_laserCanon2.isAlive()) {
        _imageDrawer->drawLaserCanon2(_laserCanon2);
    }
}

void ImageDrawerProxy::_drawLasers(const Laser& _laser1, const Laser& _laser2) const
{
    if(_laser1.isAlive()) {
        _imageDrawer->drawLaser(_laser1);
    }
    if(_laser2.isAlive()) {
        _imageDrawer->drawLaser2(_laser2);
    }
}

void ImageDrawerProxy::_drawAlienLasers(const Laser& _alienLaser) const
{
    if(_alienLaser.isAlive()){
        _imageDrawer->drawAlienLaser(_alienLaser);
    }
}

void ImageDrawerProxy::_drawGreenAliens(const Alien& _alien, int spriteNumber)
{
    if(_alien.isAlive()) {
        _imageDrawer->drawGreenAliens(_alien, spriteNumber);
    }
}

void ImageDrawerProxy::_drawPurpleAliens(const Alien& _alien, int spriteNumber)
{
    if(_alien.isAlive()) {
        _imageDrawer->drawPurpleAliens(_alien, spriteNumber);
    }
}

void ImageDrawerProxy::_drawRedAliens(const Alien& _alien, int spriteNumber)
{
    if(_alien.isAlive()) {
        _imageDrawer->drawRedAliens(_alien, spriteNumber);
    }
}

void ImageDrawerProxy::_drawUpGreenAliens(const Alien& _alien, int spriteNumber)
{
    if(_alien.isAlive()) {
        _imageDrawer->drawUpGreenAliens(_alien, spriteNumber);
    }
}

void ImageDrawerProxy::_drawUpPurpleAliens(const Alien& _alien, int spriteNumber)
{
    if(_alien.isAlive()) {
        _imageDrawer->drawUpPurpleAliens(_alien, spriteNumber);
    }
}

void ImageDrawerProxy::_drawUpRedAliens(const Alien& _alien, int spriteNumber)
{
    if(_alien.isAlive()) {
        _imageDrawer->drawUpRedAliens(_alien, spriteNumber);
    }
}

void ImageDrawerProxy::_drawLaserCanonShields(const LaserCanonShield& _laserCanonShield, int shieldNumber, int shieldState)
{
    if(_laserCanonShield.isAlive()){
    _imageDrawer->drawLaserCanonShields(_laserCanonShield, shieldNumber, shieldState);
    }
}

void ImageDrawerProxy::_drawLaserCanonLives(const LaserCanonLife& _laserCanonLife)
{
	if(_laserCanonLife.isAlive()){
    _imageDrawer->drawLaserCanonLives(_laserCanonLife);
    }
}
	
void ImageDrawerProxy::_drawHomeScreen()
{
    _imageDrawer->drawHomeScreen();
}

void ImageDrawerProxy::_drawGameWon()
{
    _imageDrawer->drawGameWon();
}

void ImageDrawerProxy::_drawGameLost()
{
    _imageDrawer->drawGameLost();
}
