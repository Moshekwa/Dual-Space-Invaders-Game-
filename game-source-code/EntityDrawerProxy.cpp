#include "EntityDrawerProxy.h"

EntityDrawerProxy::EntityDrawerProxy(shared_ptr<EntityDrawer> entityDrawer): _entityDrawer{entityDrawer}
{
}

void EntityDrawerProxy::_drawPlayer(const Player& _player) const
{
    if(_player.isAlive()){
        _entityDrawer->drawPlayer(_player.getEntityCoordinates());
        _entityDrawer->drawLaser(_player.getLaser().getEntityCoordinates());
    }
}

void EntityDrawerProxy::_drawPlayer2(const Player& _player2) const
{
    if(_player2.isAlive()){
        _entityDrawer->drawPlayer2(_player2.getEntityCoordinates());
        //_entityDrawer->drawLaser2(_player2.getLaser().getEntityCoordinates());
    }
}