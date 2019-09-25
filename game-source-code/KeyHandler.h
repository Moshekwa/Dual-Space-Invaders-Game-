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

#include "LaserCanon.h"
#include "Laser.h"
#include "GameUpdater.h"
#include <memory>
using std::shared_ptr;

class KeyHandler
{
public:
    KeyHandler();
    void KeyCheck(LaserCanon& _laserCanon1, Laser& _laser1);
    void KeyCheck2(LaserCanon& _laserCanon2, Laser& _laser2);
    void singleModeKeyCheck(LaserCanon& _laserCanon1, LaserCanon& _laserCanon2, Laser& _laser1, Laser& _laser2);

private:
};

#endif // KEYHANDLER_H_INCLUDED