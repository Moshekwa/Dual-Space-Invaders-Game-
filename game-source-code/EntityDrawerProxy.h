#ifndef ENTITYDRAWERPROXY_H_INCLUDED
#define ENTITYDRAWERPROXY_H_INCLUDED
#include "EntityDrawer.h"
#include "LaserCanon.h"
#include "Alien.h"
#include <memory>
using std::shared_ptr;

class EntityDrawerProxy
{
public:
    EntityDrawerProxy(shared_ptr<EntityDrawer> entityDrawer);
    void _drawPlayer(const LaserCanon& _laserCanon1, const LaserCanon& _laserCanon2) const;
    void _drawAliens(const Alien& _alien);

private:
    shared_ptr<EntityDrawer> _entityDrawer;
};

#endif // ENTITYDRAWERPROXY_H_INCLUDED