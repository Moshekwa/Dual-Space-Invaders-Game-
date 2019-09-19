#ifndef ENTITYDRAWER_H_INCLUDED
#define ENTITYDRAWER_H_INCLUDED
#include "EntityCoordinates.h"
#include "ImageLoader.h"
#include "GameEntity.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

using std::shared_ptr;
using std::vector;
using namespace sf;

class ImageDrawer
{
public:
    ImageDrawer(shared_ptr<RenderWindow> window);
    void drawLaserCanon(const EntityCoordinates& _coordinates);
    void drawLaserCanon2(const EntityCoordinates& _coordinates);
    void drawLaser(const EntityCoordinates& _coordinates);
    void drawLaser2(const EntityCoordinates& _coordinates);
    void drawAlienLaser(const EntityCoordinates& _coordinates);

    void drawGreenAliens(const EntityCoordinates& _coordinates, int spriteNumber);
    void drawPurpleAliens(const EntityCoordinates& _coordinates, int spriteNumber);
    void drawRedAliens(const EntityCoordinates& _coordinates, int spriteNumber);

    void drawUpGreenAliens(const EntityCoordinates& _coordinates, int spriteNumber);
    void drawUpPurpleAliens(const EntityCoordinates& _coordinates, int spriteNumber);
    void drawUpRedAliens(const EntityCoordinates& _coordinates, int spriteNumber);
    
    void drawLaserCanonShields(const EntityCoordinates& _coordinates, int shieldNumber);
	void drawLaserCanonLives(const EntityCoordinates& _coordinates, int numberOfLives);
	
    void drawHomeScreen();
    void drawGameWon();
    void drawGameLost();

private:
    shared_ptr<RenderWindow> _window;
    Sprites _sprites;
    ImageLoader _imageLoader;
};

#endif // ENTITYDRAWER_H_INCLUDED