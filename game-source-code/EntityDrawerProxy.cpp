#include "EntityDrawerProxy.h"

EntityDrawerProxy::EntityDrawerProxy(shared_ptr<EntityDrawer> entityDrawer)
    : _entityDrawer{ entityDrawer }
{
}

void EntityDrawerProxy::_drawPlayer(const LaserCanon& _laserCanon1, const LaserCanon& _laserCanon2) const
{
    auto laser1 = 1;
    auto laser2 = 2;

    if(_laserCanon1.isAlive()) {
        _entityDrawer->drawPlayer(_laserCanon1.getEntityCoordinates());
        _entityDrawer->drawLaser(_laserCanon1.getLaser(laser1).getEntityCoordinates());
    }
    if(_laserCanon2.isAlive()) {
        _entityDrawer->drawPlayer2(_laserCanon2.getEntityCoordinates());
        _entityDrawer->drawLaser2(_laserCanon2.getLaser(laser2).getEntityCoordinates());
    }
}

void EntityDrawerProxy::_drawGreenAliens(const Alien& _alien)
{
    if(_alien.isAlive()) {
        _entityDrawer->drawGreenAliens(_alien.getEntityCoordinates());
    }
}

void EntityDrawerProxy::_drawPurpleAliens(const Alien& _alien)
{
    if(_alien.isAlive()) {
        _entityDrawer->drawPurpleAliens(_alien.getEntityCoordinates());
    }
}

void EntityDrawerProxy::_drawRedAliens(const Alien& _alien)
{
    if(_alien.isAlive()) {
        _entityDrawer->drawRedAliens(_alien.getEntityCoordinates());
    }
}

void EntityDrawerProxy::_drawUpGreenAliens(const Alien& _alien)
{
    if(_alien.isAlive()) {
        _entityDrawer->drawUpGreenAliens(_alien.getEntityCoordinates());
    }
}

void EntityDrawerProxy::_drawUpPurpleAliens(const Alien& _alien)
{
    if(_alien.isAlive()) {
        _entityDrawer->drawUpPurpleAliens(_alien.getEntityCoordinates());
    }
}

void EntityDrawerProxy::_drawUpRedAliens(const Alien& _alien)
{
    if(_alien.isAlive()) {
        _entityDrawer->drawUpRedAliens(_alien.getEntityCoordinates());
    }
}