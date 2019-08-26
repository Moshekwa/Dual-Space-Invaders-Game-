#include "EntityDrawer.h"


EntityDrawer::EntityDrawer(shared_ptr<RenderWindow> window) : _window{window}
{
    _entityImageLoader.loadEntityImages();
    _sprites = _entityImageLoader.getSprites();
}

void EntityDrawer::drawPlayer(const EntityCoordinates& _coordinates)
{
    _sprites.at(0)->setScale(0.5f,0.5f);
    _sprites.at(0)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
    _window->draw(*_sprites.at(0));
}

void EntityDrawer::drawLaser(const EntityCoordinates& _coordinates)
{
    _sprites.at(2)->setScale(0.5f,0.5f);
    _sprites.at(2)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
    _window->draw(*_sprites.at(2));
}