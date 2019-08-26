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