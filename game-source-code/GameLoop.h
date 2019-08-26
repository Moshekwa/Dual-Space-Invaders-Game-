#ifndef GAMELOOP_H_INCLUDED
#define GAMELOOP_H_INCLUDED
#include "GameEntity.h"
#include "KeyHandler.h"
#include "Laser.h"
#include "Player.h"
#include "WindowDisplay.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::unique_ptr;

class GameLoop
{
public:
    GameLoop();
    void timerCheck();
    void drawPlayer();
    void PlayGame();

private:
    unique_ptr<WindowDisplay> _windowDisplay;
    shared_ptr<Player> _player;
    KeyHandler _keyHandler;
};

#endif // GAMELOOP_H_INCLUDED