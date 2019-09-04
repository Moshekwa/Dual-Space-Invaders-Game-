#include "EntityDrawer.h"

EntityDrawer::EntityDrawer(shared_ptr<RenderWindow> window)
    : _window{ window }
{
    _entityImageLoader.loadEntityImages();
    _sprites = _entityImageLoader.getSprites();
}

void EntityDrawer::drawPlayer(const EntityCoordinates& _coordinates)
{
    _sprites.at(0)->setScale(0.5f, 0.5f);
    _sprites.at(0)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
    _window->draw(*_sprites.at(0));
}

void EntityDrawer::drawPlayer2(const EntityCoordinates& _coordinates)
{
    _sprites.at(1)->setScale(0.5f, 0.5f);
    _sprites.at(1)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
    _window->draw(*_sprites.at(1));
}

void EntityDrawer::drawLaser(const EntityCoordinates& _coordinates)
{
    _sprites.at(2)->setScale(0.9f, 0.9f);
    _sprites.at(2)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
    _window->draw(*_sprites.at(2));
}

void EntityDrawer::drawLaser2(const EntityCoordinates& _coordinates)
{
    _sprites.at(3)->setScale(0.9f, 0.9f);
    _sprites.at(3)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
    _window->draw(*_sprites.at(3));
}

void EntityDrawer::drawAliens(const EntityCoordinates& _coordinates)
{
    _sprites.at(4)->setScale(0.7f, 0.72f);
    _sprites.at(4)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
    _window->draw(*_sprites.at(4));
}