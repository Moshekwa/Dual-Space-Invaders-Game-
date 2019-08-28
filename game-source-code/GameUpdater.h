#ifndef GAMEUPDATER_H_INCLUDED
#define GAMEUPDATER_H_INCLUDED
#include "Player.h"
#include <memory>
#include <vector>

using std::shared_ptr;
using std::vector;

class GameUpdater
{
public:
    GameUpdater();
    void updatePlayerLaser(Player& _player);
	void updatePlayerLaser2(Player& _player2);

private:
};

#endif // GAMEUPDATER_H_INCLUDED