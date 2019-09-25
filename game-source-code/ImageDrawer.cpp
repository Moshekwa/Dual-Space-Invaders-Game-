#include "ImageDrawer.h"
#include <sstream>

ImageDrawer::ImageDrawer(shared_ptr<RenderWindow> window)
    : _window{ window }
{
    _imageLoader.loadImagesAndSetSprites();
    _sprites = _imageLoader.getSprites();
    _texts = _imageLoader.getTexts();
}

void ImageDrawer::drawLaserCanon(const LaserCanon& _laserCanon1)
{
    if(_laserCanon1.isAlive()) {
        auto [x_position, y_position] = _laserCanon1.entityPosition();
        if(y_position == 40) {
            _sprites.at(1)->setScale(0.5f, 0.5f);
            _sprites.at(1)->setPosition(x_position, y_position);
            _window->draw(*_sprites.at(1));
        } else {
            _sprites.at(0)->setScale(0.5f, 0.5f);
            _sprites.at(0)->setPosition(x_position, y_position);
            _window->draw(*_sprites.at(0));
        }
    }
}
void ImageDrawer::drawLaserCanon2(const LaserCanon& _laserCanon2)
{
    if(_laserCanon2.isAlive()) {
        auto [x_position, y_position] = _laserCanon2.entityPosition();
        if(y_position == 480) {
            _sprites.at(0)->setScale(0.5f, 0.5f);
            _sprites.at(0)->setPosition(x_position, y_position);
            _window->draw(*_sprites.at(0));
        } else {
            _sprites.at(1)->setScale(0.5f, 0.5f);
            _sprites.at(1)->setPosition(x_position, y_position);
            _window->draw(*_sprites.at(1));
        }
    }
}

void ImageDrawer::drawLaserCanonShields(const LaserCanonShield& _canonShield, int shieldNumber, int shieldState)
{
    if(_canonShield.isAlive()) {
        auto [x_position, y_position] = _canonShield.entityPosition();
        if(shieldNumber == 1) {

            switch(shieldState) {
            case 1:
                _sprites.at(30)->setScale(0.2f, 0.1f);
                _sprites.at(30)->setPosition(x_position, y_position);
                _window->draw(*_sprites.at(30));
                break;
            case 2:
                _sprites.at(28)->setScale(0.2f, 0.1f);
                _sprites.at(28)->setPosition(x_position, y_position);
                _window->draw(*_sprites.at(28));
                break;
            case 3:
                _sprites.at(26)->setScale(0.2f, 0.1f);
                _sprites.at(26)->setPosition(x_position, y_position);
                _window->draw(*_sprites.at(26));
                break;
            default:
                break;
            }
        } else if(shieldNumber == 2) {

            switch(shieldState) {
            case 1:
                _sprites.at(31)->setScale(0.2f, 0.1f);
                _sprites.at(31)->setPosition(x_position, y_position);
                _window->draw(*_sprites.at(31));
                break;
            case 2:
                _sprites.at(29)->setScale(0.2f, 0.1f);
                _sprites.at(29)->setPosition(x_position, y_position);
                _window->draw(*_sprites.at(29));
                break;
            case 3:
                _sprites.at(27)->setScale(0.2f, 0.1f);
                _sprites.at(27)->setPosition(x_position, y_position);
                _window->draw(*_sprites.at(27));
                break;
            default:
                break;
            }
        }
    }
}

void ImageDrawer::drawLaserCanonLives(const LaserCanonLife& _canonLife)
{
    if(_canonLife.isAlive()) {
        auto [x_position, y_position] = _canonLife.entityPosition();
        _sprites.at(32)->setScale(0.1f, 0.1f);
        _sprites.at(32)->setPosition(x_position, y_position);
        _window->draw(*_sprites.at(32));
    }
}

void ImageDrawer::drawLaser(const Laser& _laser1)
{
    if(_laser1.isAlive()) {
        auto [x_position, y_position] = _laser1.entityPosition();
        _sprites.at(2)->setScale(0.9f, 0.9f);
        _sprites.at(2)->setPosition(x_position, y_position);
        _window->draw(*_sprites.at(2));
    }
}

void ImageDrawer::drawLaser2(const Laser& _laser2)
{
    if(_laser2.isAlive()) {
        auto [x_position, y_position] = _laser2.entityPosition();
        _sprites.at(3)->setScale(0.9f, 0.9f);
        _sprites.at(3)->setPosition(x_position, y_position);
        _window->draw(*_sprites.at(3));
    }
}
void ImageDrawer::drawAlienLaser(const Laser& _alienLaser)
{
    if(_alienLaser.isAlive()) {
        auto [x_position, y_position] = _alienLaser.entityPosition();
        _sprites.at(25)->setScale(0.9f, 0.9f);
        _sprites.at(25)->setPosition(x_position, y_position);
        _window->draw(*_sprites.at(25));
    }
}

void ImageDrawer::drawGreenAliens(const Alien& _alien, int spriteNumber)
{
    if(_alien.isAlive()) {
        auto [x_position, y_position] = _alien.entityPosition();
        switch(spriteNumber) {
        case 1:
            _sprites.at(7)->setScale(0.7f, 0.72f);
            _sprites.at(7)->setPosition(x_position, y_position);
            _window->draw(*_sprites.at(7));
            break;
        case 2:
            _sprites.at(19)->setScale(0.7f, 0.72f);
            _sprites.at(19)->setPosition(x_position, y_position);
            _window->draw(*_sprites.at(19));
            break;
        case 3:
            _sprites.at(20)->setScale(0.7f, 0.72f);
            _sprites.at(20)->setPosition(x_position, y_position);
            _window->draw(*_sprites.at(20));
            break;
        default:
            break;
        }
    }
}

void ImageDrawer::drawPurpleAliens(const Alien& _alien, int spriteNumber)
{
    if(_alien.isAlive()) {
        auto [x_position, y_position] = _alien.entityPosition();
        switch(spriteNumber) {
        case 1:
            _sprites.at(8)->setScale(0.7f, 0.72f);
            _sprites.at(8)->setPosition(x_position, y_position);
            _window->draw(*_sprites.at(8));
            break;
        case 2:
            _sprites.at(21)->setScale(0.7f, 0.72f);
            _sprites.at(21)->setPosition(x_position, y_position);
            _window->draw(*_sprites.at(21));
            break;
        case 3:
            _sprites.at(22)->setScale(0.7f, 0.72f);
            _sprites.at(22)->setPosition(x_position, y_position);
            _window->draw(*_sprites.at(22));
            break;
        default:
            break;
        }
    }
}

void ImageDrawer::drawRedAliens(const Alien& _alien, int spriteNumber)
{
    if(_alien.isAlive()) {
        auto [x_position, y_position] = _alien.entityPosition();
        switch(spriteNumber) {
        case 1:
            _sprites.at(9)->setScale(0.7f, 0.72f);
            _sprites.at(9)->setPosition(x_position, y_position);
            _window->draw(*_sprites.at(9));
            break;
        case 2:
            _sprites.at(23)->setScale(0.7f, 0.72f);
            _sprites.at(23)->setPosition(x_position, y_position);
            _window->draw(*_sprites.at(23));
            break;
        case 3:
            _sprites.at(24)->setScale(0.7f, 0.72f);
            _sprites.at(24)->setPosition(x_position, y_position);
            _window->draw(*_sprites.at(24));
            break;
        default:
            break;
        }
    }
}

void ImageDrawer::drawUpGreenAliens(const Alien& _alien, int spriteNumber)
{
    if(_alien.isAlive()) {
        auto [x_position, y_position] = _alien.entityPosition();
        switch(spriteNumber) {
        case 1:
            _sprites.at(4)->setScale(0.7f, 0.72f);
            _sprites.at(4)->setPosition(x_position, y_position);
            _window->draw(*_sprites.at(4));
            break;
        case 2:
            _sprites.at(13)->setScale(0.7f, 0.72f);
            _sprites.at(13)->setPosition(x_position, y_position);
            _window->draw(*_sprites.at(13));
            break;
        case 3:
            _sprites.at(14)->setScale(0.7f, 0.72f);
            _sprites.at(14)->setPosition(x_position, y_position);
            _window->draw(*_sprites.at(14));
            break;
        default:
            break;
        }
    }
}

void ImageDrawer::drawUpPurpleAliens(const Alien& _alien, int spriteNumber)
{
    if(_alien.isAlive()) {
        auto [x_position, y_position] = _alien.entityPosition();
        switch(spriteNumber) {
        case 1:
            _sprites.at(5)->setScale(0.7f, 0.72f);
            _sprites.at(5)->setPosition(x_position, y_position);
            _window->draw(*_sprites.at(5));
            break;
        case 2:
            _sprites.at(15)->setScale(0.7f, 0.72f);
            _sprites.at(15)->setPosition(x_position, y_position);
            _window->draw(*_sprites.at(15));
            break;
        case 3:
            _sprites.at(16)->setScale(0.7f, 0.72f);
            _sprites.at(16)->setPosition(x_position, y_position);
            _window->draw(*_sprites.at(16));
            break;
        default:
            break;
        }
    }
}

void ImageDrawer::drawUpRedAliens(const Alien& _alien, int spriteNumber)
{
    if(_alien.isAlive()) {
        auto [x_position, y_position] = _alien.entityPosition();
        switch(spriteNumber) {
        case 1:
            _sprites.at(6)->setScale(0.7f, 0.72f);
            _sprites.at(6)->setPosition(x_position, y_position);
            _window->draw(*_sprites.at(6));
            break;
        case 2:
            _sprites.at(17)->setScale(0.7f, 0.72f);
            _sprites.at(17)->setPosition(x_position, y_position);
            _window->draw(*_sprites.at(17));
            break;
        case 3:
            _sprites.at(18)->setScale(0.7f, 0.72f);
            _sprites.at(18)->setPosition(x_position, y_position);
            _window->draw(*_sprites.at(18));
            break;
        default:
            break;
        }
    }
}

void ImageDrawer::drawScore(ScoreBoard& _scoreBoard1)
{

    auto int_score = _scoreBoard1.getScore();
    stringstream ss;
    ss << int_score;
    auto x = "Canon1:"s;
    _texts.at(0)->setString(x + ss.str().c_str());
    _texts.at(0)->setCharacterSize(11);
    _texts.at(0)->setPosition(0, 0);
    _window->draw(*_texts.at(0));
}

void ImageDrawer::drawScore2(ScoreBoard& _scoreBoard2)
{
    auto int_score2 = _scoreBoard2.getScore();
    stringstream ss2;
    ss2 << int_score2;
    auto x = "Canon2:"s;
    _texts.at(1)->setString(x + ss2.str().c_str());
    _texts.at(1)->setCharacterSize(11);
    _texts.at(1)->setPosition(0, 15);
    _window->draw(*_texts.at(1));
}

void ImageDrawer::drawHighScore1(ScoreBoard& _scoreBoard1)
{
    auto int_score = _scoreBoard1.getScore();
    stringstream ss1;
    ss1 << int_score;
    auto x = "HighScore1:"s;
    _texts.at(2)->setString(x + ss1.str().c_str());
    _texts.at(2)->setCharacterSize(11);
    _texts.at(2)->setPosition(140, 0);
    _window->draw(*_texts.at(2));
}

void ImageDrawer::drawHighScore2(ScoreBoard& _scoreBoard2)
{
    auto int_score = _scoreBoard2.getScore();
    stringstream ss1;
    ss1 << int_score;
    auto x = "HighScore2:"s;
    _texts.at(3)->setString(x + ss1.str().c_str());
    _texts.at(3)->setCharacterSize(11);
    _texts.at(3)->setPosition(140, 15);
    _window->draw(*_texts.at(3));
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
