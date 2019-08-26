#ifndef ENTITYDRAWER_H_INCLUDED
#define ENTITYDRAWER_H_INCLUDED
#include "GameEntity.h"
#include "EntityCoordinates.h"
#include "EntityImageLoader.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

using std::shared_ptr;
using std::vector;
using namespace sf;

class EntityDrawer
{
public:
    EntityDrawer(shared_ptr<RenderWindow> window);
    void drawPlayer(const EntityCoordinates& _coordinates);
    void drawLaser(const EntityCoordinates& _coordinates);
private:
    shared_ptr<RenderWindow> _window;
    Sprites _sprites;
    EntityImageLoader _entityImageLoader;
    
};

#endif // ENTITYDRAWER_H_INCLUDED