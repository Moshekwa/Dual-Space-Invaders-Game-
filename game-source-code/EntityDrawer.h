#ifndef ENTITYDRAWER_H_INCLUDED
#define ENTITYDRAWER_H_INCLUDED
#include "EntityCoordinates.h"
#include "EntityImageLoader.h"
#include "GameEntity.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

using std::shared_ptr;
using std::vector;
using namespace sf;

class EntityDrawer
{
public:
    EntityDrawer(shared_ptr<RenderWindow> window);
    void drawPlayer(const EntityCoordinates& _coordinates);
    void drawPlayer2(const EntityCoordinates& _coordinates);
    void drawLaser(const EntityCoordinates& _coordinates);
    void drawLaser2(const EntityCoordinates& _coordinates);
    
    void drawGreenAliens(const EntityCoordinates& _coordinates);
    void drawRedAliens(const EntityCoordinates& _coordinates);
    void drawPurpleAliens(const EntityCoordinates& _coordinates);
    
    void drawUpGreenAliens(const EntityCoordinates& _coordinates);
    void drawUpRedAliens(const EntityCoordinates& _coordinates);
    void drawUpPurpleAliens(const EntityCoordinates& _coordinates);
    
private:
    shared_ptr<RenderWindow> _window;
    Sprites _sprites;
    EntityImageLoader _entityImageLoader;
};

#endif // ENTITYDRAWER_H_INCLUDED