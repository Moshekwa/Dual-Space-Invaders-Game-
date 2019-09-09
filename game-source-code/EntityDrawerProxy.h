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
    
    void _drawGreenAliens(const Alien& _alien);
    void _drawPurpleAliens(const Alien& _alien);
    void _drawRedAliens(const Alien& _alien);
    
    void _drawUpGreenAliens(const Alien& _alien);
    void _drawUpPurpleAliens(const Alien& _alien);
    void _drawUpRedAliens(const Alien& _alien);
    
    void _drawHomeScreen();

private:
    shared_ptr<EntityDrawer> _entityDrawer;
};

#endif // ENTITYDRAWERPROXY_H_INCLUDED