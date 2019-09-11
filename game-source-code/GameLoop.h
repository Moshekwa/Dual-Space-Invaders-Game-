#ifndef GAMELOOP_H_INCLUDED
#define GAMELOOP_H_INCLUDED
#include "CollisionDetector.h"
#include "EntityDrawerProxy.h"
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

class GameLoop
{
public:
    GameLoop();
    void PlayGame();

private:
    shared_ptr<WindowDisplay> _windowDisplay;
    shared_ptr<LaserCanon> _laserCanon1;
    shared_ptr<LaserCanon> _laserCanon2;
    shared_ptr<EntityDrawer> _entityDrawer;

    GreenAliens _greenAliens;
    PurpleAliens _purpleAliens;
    RedAliens _redAliens;

    UpGreenAliens _upGreenAliens;
    UpPurpleAliens _upPurpleAliens;
    UpRedAliens _upRedAliens;

    KeyHandler _keyHandler;
    void timerCheck();
    void drawGameEntities();

    bool gameWon;
    bool gameLost;
	
};

#endif // GAMELOOP_H_INCLUDED