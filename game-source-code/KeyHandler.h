#ifndef KEYHANDLER_H_INCLUDED
#define KEYHANDLER_H_INCLUDED

#include "LaserCanon.h"
#include <memory>
using std::shared_ptr;

class KeyHandler
{
public:
    KeyHandler();
    void KeyCheck(LaserCanon& _laserCanon1);
    void KeyCheck2(LaserCanon& _laserCanon2);
    void singleModeKeyCheck(LaserCanon& _laserCanon1, LaserCanon& _laserCanon2);

private:
};

#endif // KEYHANDLER_H_INCLUDED