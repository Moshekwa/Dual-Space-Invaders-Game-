#ifndef GAMELOOP_H_INCLUDED
#define GAMELOOP_H_INCLUDED
#include "GameEntity.h"
#include "EntityDrawer.h"
#include "EntityDrawerProxy.h"
#include "KeyHandler.h"
#include "Laser.h"
#include "Player.h"
#include "WindowDisplay.h"
#include "GameUpdater.h"


#include <memory>
#include <vector>

using std::shared_ptr;
using std::unique_ptr;

class GameLoop
{
public:
    GameLoop();
    void PlayGame();

private:
    unique_ptr<WindowDisplay> _windowDisplay;
    shared_ptr<Player> _player;
    shared_ptr<EntityDrawer> _entityDrawer;
    KeyHandler _keyHandler;
    void timerCheck();
    void drawGameEntities();
};

#endif // GAMELOOP_H_INCLUDED