/**
 * @file ImageDrawer.h
 * @class ImageDrawer
 * @brief This class is responsible for mapping the stored images and text with the positions where they are to be
 * displayed.
 * @bug No Known Bugs.
 * @version 3.0
 * @date 25/09/2019
 */

#ifndef ENTITYDRAWER_H_INCLUDED
#define ENTITYDRAWER_H_INCLUDED
#include "Alien.h"
#include "GameEntity.h"
#include "ImageLoader.h"
#include "Laser.h"
#include "LaserCanon.h"
#include "LaserCanonLife.h"
#include "LaserCanonShield.h"
#include "ScoreBoard.h"
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
    void drawLaserCanon(const LaserCanon& _laserCanon1);
    void drawLaserCanon2(const LaserCanon& _laserCanon2);
    void drawLaser(const Laser& _laser1);
    void drawLaser2(const Laser& _laser2);
    void drawAlienLaser(const Laser& _alienLaser);

    void drawGreenAliens(const Alien& _alien, int spriteNumber);
    void drawPurpleAliens(const Alien& _alien, int spriteNumber);
    void drawRedAliens(const Alien& _alien, int spriteNumber);

    void drawUpGreenAliens(const Alien& _alien, int spriteNumber);
    void drawUpPurpleAliens(const Alien& _alien, int spriteNumber);
    void drawUpRedAliens(const Alien& _alien, int spriteNumber);

    void drawLaserCanonShields(const LaserCanonShield& _canonShield, int shieldNumber, int shieldState);
    void drawLaserCanonLives(const LaserCanonLife& _canonLife);

    void drawScore(const ScoreBoard& _scoreBoard);
    void drawHighScore(const ScoreBoard& _scoreBoard);
    void drawGameMode(int gameMode);

    void drawHomeScreen();
    void drawGameWon();
    void drawGameLost();

private:
    shared_ptr<RenderWindow> _window;
    Sprites _sprites;
    Texts _texts;
    ImageLoader _imageLoader;
};

#endif // ENTITYDRAWER_H_INCLUDED