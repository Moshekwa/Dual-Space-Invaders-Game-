#ifndef ENTITYDRAWERPROXY_H_INCLUDED
#define ENTITYDRAWERPROXY_H_INCLUDED
#include "EntityDrawer.h"
#include "Player.h"
#include <memory>
using std::shared_ptr;

class EntityDrawerProxy
{
public:
    EntityDrawerProxy(shared_ptr<EntityDrawer> entityDrawer);
    void _drawPlayer(const Player& _player) const;

private:
    shared_ptr<EntityDrawer> _entityDrawer;
};

#endif // ENTITYDRAWERPROXY_H_INCLUDED