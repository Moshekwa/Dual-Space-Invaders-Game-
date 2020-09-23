/**
 * @file GameLoop.h
 * @class GameLoop
 * @brief Serves as the engine of the game. It is responsible for creating game entity objects, playing the game and
 * displaying the objects.
 * @bug No Known Bugs.
 * @version 3.0
 * @date 25/09/2019
 */

#ifndef GAMELOOP_H_INCLUDED
#define GAMELOOP_H_INCLUDED
#include "Alien.h"
#include "CollisionHandler.h"
#include "GameUpdater.h"
#include "ImageDrawer.h"
#include "KeyHandler.h"
#include "Laser.h"
#include "LaserCanon.h"
#include "LaserCanonLife.h"
#include "LaserCanonShield.h"
#include "ScoreBoard.h"
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
    /**
     *  @brief This is where the entire game is played.
     *  All game objects are created and exist within the scope of this function
     */
    void PlayGame();
    ~GameLoop(){};

private:
    shared_ptr<WindowDisplay> _windowDisplay;
    shared_ptr<LaserCanon> _laserCanon1;
    shared_ptr<LaserCanon> _laserCanon2;
    shared_ptr<Laser> _laser1;
    shared_ptr<Laser> _laser2;
    shared_ptr<ImageDrawer> _imageDrawer;
    shared_ptr<Alien> _alien;
    shared_ptr<ScoreBoard> _scoreBoard;
    shared_ptr<CollisionHandler> _collisionHandler;

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
    /**
     * @brief creates shared pointers to the laser canon and laser objects
     */
    void createLaserCanonsAndLasers();
    /**
     * @brief creates shared pointers to the laser canon shields objects
     */
    void createLaserCanonShields();
    /**
     * @brief creates shared pointers to the laser canon lives objects
     */
    void createLaserCanonLives();
    /**
     * @brief creates shared pointers to the alien objects
     */
    void createAliens();
    /**
     * @brief Resets the aliens to their initial positions
     */
    void aliensInitialPositions();
    /**
     * @brief Resets the laser canons to their initial positions
     */
    void laserCanonsInitialPositions();

    /**
     * @brief This function updates all game objects accordingly depending on operations that acted on them.
     */
    void gameActivities();
    /**
     * @brief Updates laser canon and laser object activities. It is called within the scope of gameActivities.
     */
    void laserCanonAndLaserActivities();
    /**
     * @brief Updates alien objects activities as the game is being played.
     */
    void alienActivities();
    /**
     * @brief This function updates the activities affecting the shields protecting the laser canon.
     */
    void laserCanonShieldActivities();

    /**
     * @brief displays all game objects that are alive on the game play screen
     */
    void displayGameEntities();

    /**
     *@brief displays the all the game texts: currently being the score, high score and the game mode being played
     */
    void displayTexts();
    /**
     * @brief displays green alien objects present in the game and represents it with an appropriate sprite at specific
     * positions for animation.
     * @param spriteNumber
     * @param spriteBoundaries
     */
    void displayGreenAlians(vector<int> spriteNumber, vector<int> spriteBoundaries);
    /**
     * @brief displays purple alien objects present in the game and represents it with an appropriate sprite at specific
     * positions for animation
     * @param spriteNumber
     * @param spriteBoundaries
     */
    void displayPurpleAliens(vector<int> spriteNumber, vector<int> spriteBoundaries);
    /**
     * @brief displays red alien objects present in the game and represents it with an appropriate sprite at specific
     * positions for animation
     * @param spriteNumber
     * @param spriteBoundaries
     */
    void displayRedAliens(vector<int> spriteNumber, vector<int> spriteBoundaries);
    /**
     * @brief represents the number of lives a player has as the game is being played
     */
    void displayLaserCanonLives();
    void displayLaserCanonShields();
    void displayLaserCanonsAndLasers();
    /**
    * This boolean is set true when the game is won
    */
    bool gameWon;
    /**
    * This boolean is set true when the game is lost
    */ 
    bool gameLost;
    /**
    * this boolean is set false when all the red alien objects in a row are no longer alive. 
    */ 
    bool redAlienRowAlive;
    /**
    * this boolean is set false when all the purple alien objects in a row are no longer alive. 
    */
    bool purpleAlienRowAlive;
    /**
    * this boolean is set false when all the upward-facing red alien objects in a row are no longer alive. 
    */
    bool upRedAlienRowAlive;
    /**
    * this boolean is set false when all the upward-facing purple alien objects in a row are no longer alive. 
    */
    bool upPurpleAlienRowAlive;
};

#endif // GAMELOOP_H_INCLUDED