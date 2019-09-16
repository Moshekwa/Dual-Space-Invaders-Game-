#include "ImageDrawer.h"

ImageDrawer::ImageDrawer(shared_ptr<RenderWindow> window)
    : _window{ window }
{
    _imageLoader.loadImagesAndSetSprites();
    _sprites = _imageLoader.getSprites();
}

void ImageDrawer::drawLaserCanon(const EntityCoordinates& _coordinates)
{
    _sprites.at(0)->setScale(0.5f, 0.5f);
    _sprites.at(0)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
    _window->draw(*_sprites.at(0));
}

void ImageDrawer::drawLaserCanon2(const EntityCoordinates& _coordinates)
{
    _sprites.at(1)->setScale(0.5f, 0.5f);
    _sprites.at(1)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
    _window->draw(*_sprites.at(1));
}

void ImageDrawer::drawLaser(const EntityCoordinates& _coordinates)
{
    _sprites.at(2)->setScale(0.9f, 0.9f);
    _sprites.at(2)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
    _window->draw(*_sprites.at(2));
}

void ImageDrawer::drawLaser2(const EntityCoordinates& _coordinates)
{
    _sprites.at(3)->setScale(0.9f, 0.9f);
    _sprites.at(3)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
    _window->draw(*_sprites.at(3));
}

void ImageDrawer::drawAlienLaser(const EntityCoordinates& _coordinates)
{
    _sprites.at(25)->setScale(0.9f, 0.9f);
    _sprites.at(25)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
    _window->draw(*_sprites.at(25));
}

void ImageDrawer::drawGreenAliens(const EntityCoordinates& _coordinates, int spriteNumber)
{
    switch(spriteNumber) {
    case 1:
	_sprites.at(7)->setScale(0.7f, 0.72f);
	_sprites.at(7)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
	_window->draw(*_sprites.at(7));
	break;
    case 2:
	_sprites.at(19)->setScale(0.7f, 0.72f);
	_sprites.at(19)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
	_window->draw(*_sprites.at(19));
	break;
    case 3:
	_sprites.at(20)->setScale(0.7f, 0.72f);
	_sprites.at(20)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
	_window->draw(*_sprites.at(20));
	break;
    default:
	break;
    }
}

void ImageDrawer::drawPurpleAliens(const EntityCoordinates& _coordinates, int spriteNumber)
{
    switch(spriteNumber) {
    case 1:
	_sprites.at(8)->setScale(0.7f, 0.72f);
	_sprites.at(8)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
	_window->draw(*_sprites.at(8));
	break;
    case 2:
	_sprites.at(21)->setScale(0.7f, 0.72f);
	_sprites.at(21)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
	_window->draw(*_sprites.at(21));
	break;
    case 3:
	_sprites.at(22)->setScale(0.7f, 0.72f);
	_sprites.at(22)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
	_window->draw(*_sprites.at(22));
	break;
    default:
	break;
    }
}

void ImageDrawer::drawRedAliens(const EntityCoordinates& _coordinates, int spriteNumber)
{
    switch(spriteNumber) {
    case 1:
	_sprites.at(9)->setScale(0.7f, 0.72f);
	_sprites.at(9)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
	_window->draw(*_sprites.at(9));
	break;
    case 2:
	_sprites.at(23)->setScale(0.7f, 0.72f);
	_sprites.at(23)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
	_window->draw(*_sprites.at(23));
	break;
    case 3:
	_sprites.at(24)->setScale(0.7f, 0.72f);
	_sprites.at(24)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
	_window->draw(*_sprites.at(24));
	break;
    default:
	break;
    }
}

void ImageDrawer::drawUpGreenAliens(const EntityCoordinates& _coordinates, int spriteNumber)
{
    switch(spriteNumber) {
    case 1:
	_sprites.at(4)->setScale(0.7f, 0.72f);
	_sprites.at(4)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
	_window->draw(*_sprites.at(4));
	break;
    case 2:
	_sprites.at(13)->setScale(0.7f, 0.72f);
	_sprites.at(13)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
	_window->draw(*_sprites.at(13));
	break;
    case 3:
	_sprites.at(14)->setScale(0.7f, 0.72f);
	_sprites.at(14)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
	_window->draw(*_sprites.at(14));
	break;
    default:
	break;
    }
}

void ImageDrawer::drawUpPurpleAliens(const EntityCoordinates& _coordinates, int spriteNumber)
{
    switch(spriteNumber) {
    case 1:
	_sprites.at(5)->setScale(0.7f, 0.72f);
	_sprites.at(5)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
	_window->draw(*_sprites.at(5));
	break;
    case 2:
	_sprites.at(15)->setScale(0.7f, 0.72f);
	_sprites.at(15)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
	_window->draw(*_sprites.at(15));
	break;
    case 3:
	_sprites.at(16)->setScale(0.7f, 0.72f);
	_sprites.at(16)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
	_window->draw(*_sprites.at(16));
	break;
    default:
	break;
    }
}

void ImageDrawer::drawUpRedAliens(const EntityCoordinates& _coordinates, int spriteNumber)
{
    switch(spriteNumber) {
    case 1:
	_sprites.at(6)->setScale(0.7f, 0.72f);
	_sprites.at(6)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
	_window->draw(*_sprites.at(6));
	break;
    case 2:
	_sprites.at(17)->setScale(0.7f, 0.72f);
	_sprites.at(17)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
	_window->draw(*_sprites.at(17));
	break;
    case 3:
	_sprites.at(18)->setScale(0.7f, 0.72f);
	_sprites.at(18)->setPosition(_coordinates.getXposition(), _coordinates.getYposition());
	_window->draw(*_sprites.at(18));
	break;
    default:
	break;
    }
}

void ImageDrawer::drawHomeScreen()
{
    _sprites.at(10)->setScale(0.60, 0.99);
    _sprites.at(10)->setPosition(0, 50);
    _window->draw(*_sprites.at(10));
}

void ImageDrawer::drawGameWon()
{
    _sprites.at(11)->setScale(0.33, 0.60);
    _sprites.at(11)->setPosition(0, 50);
    _window->draw(*_sprites.at(11));
}

void ImageDrawer::drawGameLost()
{
    _sprites.at(12)->setScale(0.33, 0.60);
    _sprites.at(12)->setPosition(0, 50);
    _window->draw(*_sprites.at(12));
}