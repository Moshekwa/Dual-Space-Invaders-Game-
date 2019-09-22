#ifndef GAMELOOP_H_INCLUDED
#define GAMELOOP_H_INCLUDED
#include "CollisionDetector.h"
#include "ImageDrawerProxy.h"
#include "GameEntity.h"
#include "GameUpdater.h"
#include "KeyHandler.h"
#include "Laser.h"
#include "WindowDisplay.h"

#include <memory>
#include <vector>

using std::make_shared;
using std::shared_ptr;
using std::vector;

typedef vector<shared_ptr<Alien>> GreenAliens;
typedef vector<shared_ptr<Alien>> PurpleAliens;
typedef vector<shared_ptr<Alien>> RedAliens;

typedef vector<shared_ptr<Alien>> UpGreenAliens;
typedef vector<shared_ptr<Alien>> UpPurpleAliens;
typedef vector<shared_ptr<Alien>> UpRedAliens;

typedef vector<shared_ptr<Laser>> AlienLasers;
typedef vector<shared_ptr<LaserCanonShield>> LaserCanonShields;
typedef vector<shared_ptr<LaserCanonLife>> LaserCanonLives;

class GameLoop
{
public:
    GameLoop();
    void PlayGame();

private:
    shared_ptr<WindowDisplay> _windowDisplay;
    shared_ptr<LaserCanon> _laserCanon1;
    shared_ptr<LaserCanon> _laserCanon2;
    shared_ptr<Laser> _laser1;
    shared_ptr<Laser> _laser2;
    shared_ptr<ImageDrawer> _imageDrawer;
    shared_ptr<Alien> _alien;

    GreenAliens _greenAliens;
    PurpleAliens _purpleAliens;
    RedAliens _redAliens;

    UpGreenAliens _upGreenAliens;
    UpPurpleAliens _upPurpleAliens;
    UpRedAliens _upRedAliens;
    
    AlienLasers _alienLasers;
    LaserCanonShields _laserCanonShields;
	LaserCanonLives _laserCanonLife;
	
    KeyHandler _keyHandler;
    ImageDrawerProxy _imageDrawerProxy;
    
    void createLaserCanonShields();
    void createLaserCanonLives();
    void createAliens();
    void aliensInitialPositions();
    
    void gameActivities();
    void laserCanonActivities();
    void alienActivities();
    void laserCanonShieldActivities();
    
    void displayGameEntities();
    void displayGreenAlians(vector<int> spriteNumber, vector<int> spriteBoundaries);
    void displayPurpleAliens(vector<int> spriteNumber, vector<int> spriteBoundaries);
    void displayRedAliens(vector<int> spriteNumber, vector<int> spriteBoundaries);
    void displayLaserCanonLives();
    void displayLaserCanonShields();
    void displayLaserCanonsAndLasers();
    

    bool gameWon;
    bool gameLost;
    bool redAlienRowAlive;
    bool purpleAlienRowAlive;
    bool upRedAlienRowAlive;
    bool upPurpleAlienRowAlive;
};

#endif // GAMELOOP_H_INCLUDED