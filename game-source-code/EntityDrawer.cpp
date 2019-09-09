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

void EntityDrawer::drawGreenAliens(const EntityCoordinates& _coordinates)
{
    _sprites.at(4)->setScale(0.7f, 0.72f);
    _sprites.at(4)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
    _window->draw(*_sprites.at(4));
}

void EntityDrawer::drawPurpleAliens(const EntityCoordinates& _coordinates)
{
    _sprites.at(5)->setScale(0.7f, 0.72f);
    _sprites.at(5)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
    _window->draw(*_sprites.at(5));
}

void EntityDrawer::drawRedAliens(const EntityCoordinates& _coordinates)
{
    _sprites.at(6)->setScale(0.7f, 0.72f);
    _sprites.at(6)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
    _window->draw(*_sprites.at(6));
}

void EntityDrawer::drawUpGreenAliens(const EntityCoordinates& _coordinates)
{
    _sprites.at(7)->setScale(0.7f, 0.72f);
    _sprites.at(7)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
    _window->draw(*_sprites.at(7));
}

void EntityDrawer::drawUpPurpleAliens(const EntityCoordinates& _coordinates)
{
    _sprites.at(8)->setScale(0.7f, 0.72f);
    _sprites.at(8)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
    _window->draw(*_sprites.at(8));
}

void EntityDrawer::drawUpRedAliens(const EntityCoordinates& _coordinates)
{
    _sprites.at(9)->setScale(0.7f, 0.72f);
    _sprites.at(9)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
    _window->draw(*_sprites.at(9));
}
