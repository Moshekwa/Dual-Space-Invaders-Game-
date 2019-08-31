#include "EntityDrawerProxy.h"

EntityDrawerProxy::EntityDrawerProxy(shared_ptr<EntityDrawer> entityDrawer)
    : _entityDrawer{ entityDrawer }
{
}

void EntityDrawerProxy::_drawPlayer(const Player& _player, const Player _player2) const
{
    auto laser1 = 1;
    auto laser2 = 2;
    
    if(_player.isAlive()) {
        _entityDrawer->drawPlayer(_player.getEntityCoordinates());
        _entityDrawer->drawLaser(_player.getLaser(laser1).getEntityCoordinates());
    }
    if(_player2.isAlive()) {
        _entityDrawer->drawPlayer2(_player2.getEntityCoordinates());
        _entityDrawer->drawLaser2(_player2.getLaser(laser2).getEntityCoordinates());
    }
}