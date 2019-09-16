#include "ImageDrawerProxy.h"

ImageDrawerProxy::ImageDrawerProxy(shared_ptr<ImageDrawer> imageDrawer)
    : _imageDrawer{ imageDrawer }
{
}

void ImageDrawerProxy::_drawLaserCanonsAndLasers(const LaserCanon& _laserCanon1, const LaserCanon& _laserCanon2) const
{
    auto laser1 = 1;
    auto laser2 = 2;

    if(_laserCanon1.isAlive()) {
	_imageDrawer->drawLaserCanon(_laserCanon1.getEntityCoordinates());
	if(_laserCanon1.getLaser(laser1).isAlive()) {
	    _imageDrawer->drawLaser(_laserCanon1.getLaser(laser1).getEntityCoordinates());
	}
    }
    if(_laserCanon2.isAlive()) {
	_imageDrawer->drawLaserCanon2(_laserCanon2.getEntityCoordinates());
	if(_laserCanon2.getLaser(laser2).isAlive()) {
	    _imageDrawer->drawLaser2(_laserCanon2.getLaser(laser2).getEntityCoordinates());
	}
    }
}

void ImageDrawerProxy::_drawGreenAliens(const Alien& _alien, int spriteNumber)
{
    if(_alien.isAlive()) {
	_imageDrawer->drawGreenAliens(_alien.getEntityCoordinates(), spriteNumber);
    }
}

void ImageDrawerProxy::_drawPurpleAliens(const Alien& _alien, int spriteNumber)
{
    if(_alien.isAlive()) {
	_imageDrawer->drawPurpleAliens(_alien.getEntityCoordinates(), spriteNumber);
    }
}

void ImageDrawerProxy::_drawRedAliens(const Alien& _alien, int spriteNumber)
{
    if(_alien.isAlive()) {
	_imageDrawer->drawRedAliens(_alien.getEntityCoordinates(), spriteNumber);
    }
}

void ImageDrawerProxy::_drawUpGreenAliens(const Alien& _alien, int spriteNumber)
{
    if(_alien.isAlive()) {
	_imageDrawer->drawUpGreenAliens(_alien.getEntityCoordinates(), spriteNumber);
    }
}

void ImageDrawerProxy::_drawUpPurpleAliens(const Alien& _alien, int spriteNumber)
{
    if(_alien.isAlive()) {
	_imageDrawer->drawUpPurpleAliens(_alien.getEntityCoordinates(), spriteNumber);
    }
}

void ImageDrawerProxy::_drawUpRedAliens(const Alien& _alien, int spriteNumber)
{
    if(_alien.isAlive()) {
	_imageDrawer->drawUpRedAliens(_alien.getEntityCoordinates(), spriteNumber);
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