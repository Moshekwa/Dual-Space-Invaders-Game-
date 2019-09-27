/**
 * @file KeyHandler.h
 * @class KeyHandler
 * @brief This class used to check user key input from the keyboard and then act accordingly.
 * @bug No Known Bugs.
 * @version 3.0
 * @date 25/09/2019
 */

#ifndef KEYHANDLER_H_INCLUDED
#define KEYHANDLER_H_INCLUDED

#include "GameUpdater.h"
#include "Laser.h"
#include "LaserCanon.h"
#include <memory>
#include <tuple>
using std::make_shared;
using std::shared_ptr;

class KeyHandler
{
public:
    KeyHandler();
    /**
     * @brief checks the keys pressed by the user for setting the game modes or exiting the game screen
     * @return
     */
    tuple<bool, bool, bool> keyCheckGameMode();
    /**
     * @brief checks the keys pressed for moving and shooting the first player's game object
     * @param _laserCanon1
     * @param _laser1
     */
    void KeyCheck(LaserCanon& _laserCanon1, Laser& _laser1);
    /**
     * @brief checks the keys pressed for moving and shooting the second player's game object
     * @param _laserCanon2
     * @param _laser2
     */
    void KeyCheck2(LaserCanon& _laserCanon2, Laser& _laser2);
    /**
     * @brief checks the keys pressed for controlling the game objects when single play mode is active
     * @param _laserCanon1
     * @param _laserCanon2
     * @param _laser1
     * @param _laser2
     */
    void singleModeKeyCheck(LaserCanon& _laserCanon1, LaserCanon& _laserCanon2, Laser& _laser1, Laser& _laser2);
    ~KeyHandler(){};

private:
};

#endif // KEYHANDLER_H_INCLUDED