#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../game-source-code/CollisionHandler.h"
#include "../game-source-code/GameEntity.h"
#include "../game-source-code/GameUpdater.h"
#include "../game-source-code/Laser.h"
#include "../game-source-code/LaserCanon.h"
#include "../game-source-code/MovingEntity.h"
#include "doctest.h"

//--------------------------------GameEntityTests---------------------------------------------------

TEST_CASE("Testing for Invalid Coordinates of the Game Entity class")
{
    auto xPosition = -4;
    auto yPosition = 400;
    CHECK_THROWS_AS(GameEntity(xPosition, yPosition, false, 3), InvalidEntityPositions);

    xPosition = 360;
    yPosition = 620;
    CHECK_THROWS_AS(GameEntity(xPosition, yPosition, false, 3), InvalidEntityPositions);

    xPosition = 620;
    yPosition = 500;
    CHECK_THROWS_AS(GameEntity(xPosition, yPosition, false, 3), InvalidEntityPositions);

    xPosition = 20;
    yPosition = -500;
    CHECK_THROWS_AS(GameEntity(xPosition, yPosition, false, 3), InvalidEntityPositions);
}

TEST_CASE("Testing if Game Entity does not create a dead object")
{
    auto xPosition = 190;
    auto yPosition = 480;
    auto numberOfLives = 0;
    CHECK_THROWS_AS(GameEntity(xPosition, yPosition, false, numberOfLives), NumberOfLivesCannotBeZero);
}

//------------------------------------------LaserTests-------------------------------------------------

TEST_CASE("LaserCanon is able to initialize Laser coordinates")
{
    auto xPosition = 190;
    auto yPosition = 480;
    auto _laserCanon = LaserCanon{ xPosition, yPosition, 1, 3 };
    auto _laser = Laser{ _laserCanon, 1 };

    auto [x_position, y_position] = _laser.entityPosition();
    CHECK(x_position == xPosition);
    CHECK(y_position == yPosition);
}

TEST_CASE("Laser is able to move up the screen")
{
    auto xPosition = 190;
    auto yPosition = 480;
    auto _laserCanon = LaserCanon{ xPosition, yPosition, 1, 3 };

    auto _laser = Laser{ _laserCanon, 1 };
    _laser.move(Direction::UP);
    auto y_position = get<1>(_laser.entityPosition());
    CHECK(y_position == yPosition - _laser.getEntitySpeed());
}

TEST_CASE("Laser is able to move down the screen")
{
    auto xPosition = 190;
    auto yPosition = 40;
    auto _laserCanon2 = LaserCanon{ xPosition, yPosition, 2, 3 };

    auto _laser2 = Laser{ _laserCanon2, 1 };
    _laser2.move(Direction::DOWN);
    auto y_position = get<1>(_laser2.entityPosition());
    CHECK(y_position == yPosition + _laser2.getEntitySpeed());
}

TEST_CASE("Able to set the laser alive and also destroy it")
{
    auto xPosition = 190;
    auto yPosition = 480;
    auto _laserCanon1 = LaserCanon{ xPosition, yPosition, 1, 3 };

    auto _laser1 = Laser{ _laserCanon1, 1 };
    CHECK(_laser1.isAlive() == false);
    _laser1.giveEntityLife();
    CHECK(_laser1.isAlive() == true);
    _laser1.destroyEntity();
    CHECK(_laser1.isAlive() == false);
}

TEST_CASE("Laser does not go above the upper screen boundary, it gets distroyed and goes back to the canon")
{
    auto xPosition = 190;
    auto yPosition = 480;
    auto _laserCanon1 = LaserCanon{ xPosition, yPosition, 1, 3 };

    auto _laser1 = Laser{ _laserCanon1, 1 };

    _laser1.setYposition(get<2>(_laserCanon1.getMovementBoundaries()));
    _laser1.giveEntityLife();

    auto _gameUpdater = GameUpdater{};
    _gameUpdater.updateLaser1Position(_laserCanon1, _laser1);

    CHECK(_laser1.isAlive() == false);
    _gameUpdater.updateLaser1Position(_laserCanon1, _laser1);
    auto y_position = get<1>(_laser1.entityPosition());
    auto y_position_ = get<1>(_laserCanon1.entityPosition());
    CHECK(y_position == y_position_ + 5); // laser offsets from laser canon by 5 units.
}

TEST_CASE("Laser does not go below the bottom screen boundary, it gets destroyed and goes back to the canon")
{
    auto xPosition = 190;
    auto yPosition = 40;
    auto _laserCanon2 = LaserCanon{ xPosition, yPosition, 2, 3 };

    auto _laser2 = Laser{ _laserCanon2, 1 };

    _laser2.setYposition(get<3>(_laserCanon2.getMovementBoundaries()));
    _laser2.giveEntityLife();

    auto _gameUpdater = GameUpdater{};
    _gameUpdater.updateLaser2Position(_laserCanon2, _laser2);
    _gameUpdater.updateLaser2Position(_laserCanon2, _laser2);
    _gameUpdater.updateLaser2Position(_laserCanon2, _laser2);
    _gameUpdater.updateLaser2Position(_laserCanon2, _laser2);

    CHECK(_laser2.isAlive() == false);
    _gameUpdater.updateLaser2Position(_laserCanon2, _laser2);
    auto y_position = get<1>(_laser2.entityPosition());
    auto y_position_ = get<1>(_laserCanon2.entityPosition());
    CHECK(y_position == y_position_ + 5);
}

TEST_CASE("Both lasers get destroyed when they collide")
{
    auto canon1_Xposition = 190;
    auto canon1_Yposition = 480;
    auto _laserCanon1 = LaserCanon{ canon1_Xposition, canon1_Yposition, 1, 3 };
    auto _laser1 = Laser{ _laserCanon1, 1 };
    _laser1.giveEntityLife();

    auto canon2_Xposition = 190;
    auto canon2_Yposition = 40;
    auto _laserCanon2 = LaserCanon{ canon2_Xposition, canon2_Yposition, 2, 3 };
    auto _laser2 = Laser{ _laserCanon2, 1 };
    _laser2.giveEntityLife();

    _laser1.setYposition(200);
    _laser2.setYposition(200);
    auto _collisionHandler = CollisionHandler{};
    _collisionHandler.handleLaser1Laser2Collision(_laser1, _laser2);
    CHECK_FALSE(_laser1.isAlive());
    CHECK_FALSE(_laser2.isAlive());
}

TEST_CASE("Both lasers do not destroyed when did not collide")
{
    auto canon1_Xposition = 190;
    auto canon1_Yposition = 480;
    auto _laserCanon1 = LaserCanon{ canon1_Xposition, canon1_Yposition, 1, 3 };
    auto _laser1 = Laser{ _laserCanon1, 1 };
    _laser1.giveEntityLife();

    auto canon2_Xposition = 190;
    auto canon2_Yposition = 40;
    auto _laserCanon2 = LaserCanon{ canon2_Xposition, canon2_Yposition, 2, 3 };
    auto _laser2 = Laser{ _laserCanon2, 1 };
    _laser2.giveEntityLife();

    auto _collisionHandler = CollisionHandler{};
    _collisionHandler.handleLaser1Laser2Collision(_laser1, _laser2);
    CHECK(_laser1.isAlive());
    CHECK(_laser2.isAlive());
}

//-------------------------------------------------LaserCanonTests------------------------------------------

TEST_CASE("Exception thrown for Invalid Laser Canon Positions")
{
    auto xPosition = 500;
    auto yPosition = 0;
    CHECK_THROWS_AS(LaserCanon(xPosition, yPosition, 1, 3), InvalidEntityPositions);
    CHECK_THROWS_AS(LaserCanon(xPosition, yPosition, 2, 3), InvalidEntityPositions);
}

TEST_CASE("Exception thrown for invalid laser canon 1 starting position")
{
    // the acceptable positions should be x_position = 190 and y_position = 480;
    auto x_position = 190;
    auto y_position = 490;
    CHECK_THROWS_AS(LaserCanon(x_position, y_position, 1, 3), InvalidLaserCanonPosition);

    x_position = 200;
    y_position = 480;
    CHECK_THROWS_AS(LaserCanon(x_position, y_position, 1, 3), InvalidLaserCanonPosition);
}

TEST_CASE("Exception thrown for invalid laser canon 2 starting position")
{
    // the acceptable positions should be x_position = 190 and y_position = 40;
    auto x_position = 190;
    auto y_position = 490;
    CHECK_THROWS_AS(LaserCanon(x_position, y_position, 1, 3), InvalidLaserCanonPosition);

    x_position = 200;
    y_position = 40;
    CHECK_THROWS_AS(LaserCanon(x_position, y_position, 2, 3), InvalidLaserCanonPosition);
}

TEST_CASE("Testing if player is able to create 2 Laser Canon objects at different initial positions")
{
    auto xPosition1 = 190;
    auto yPosition1 = 480;
    auto xPosition2 = 190;
    auto yPosition2 = 40;
    auto _laserCanon1 = LaserCanon{ xPosition1, yPosition1, 1, 3 };
    auto _laserCanon2 = LaserCanon{ xPosition2, yPosition2, 2, 3 };

    CHECK(get<0>(_laserCanon1.entityPosition()) == xPosition1);
    CHECK(get<0>(_laserCanon2.entityPosition()) == xPosition2);
    CHECK(get<1>(_laserCanon1.entityPosition()) == yPosition1);
    CHECK(get<1>(_laserCanon2.entityPosition()) == yPosition2);
}

TEST_CASE("Testing the setPosition functions for Laser Canon")
{
    auto xPosition = 180;
    auto yPosition = 490;

    auto _laserCanon = LaserCanon{ 190, 480, 1, 3 };

    _laserCanon.setXposition(xPosition);
    _laserCanon.setYposition(yPosition);

    CHECK(get<0>(_laserCanon.entityPosition()) == xPosition);
    CHECK(get<1>(_laserCanon.entityPosition()) == yPosition);
}

TEST_CASE("Lasor Canon 1 is able to move in the correct direction")
{
    auto xPosition = 190;
    auto yPosition = 480;

    auto _laserCanon = LaserCanon{ xPosition, yPosition, 1, 3 };

    auto _gameUpdater = GameUpdater{};
    _gameUpdater.updateLaserCanon1Position(_laserCanon, Direction::LEFT);
    CHECK(get<0>(_laserCanon.entityPosition()) == xPosition - _laserCanon.getEntitySpeed());
    _gameUpdater.updateLaserCanon1Position(_laserCanon, Direction::RIGHT);
    CHECK(get<0>(_laserCanon.entityPosition()) == xPosition);
    _gameUpdater.updateLaserCanon1Position(_laserCanon, Direction::UP);
    CHECK(get<1>(_laserCanon.entityPosition()) == yPosition - _laserCanon.getEntitySpeed());
    _gameUpdater.updateLaserCanon1Position(_laserCanon, Direction::DOWN);
    CHECK(get<1>(_laserCanon.entityPosition()) == yPosition);
}

TEST_CASE("Lasor Canon 2 is able to move in the correct direction")
{
    auto xPosition = 190;
    auto yPosition = 40;

    auto _laserCanon = LaserCanon{ xPosition, yPosition, 2, 3 };

    auto _gameUpdater = GameUpdater{};
    _gameUpdater.updateLaserCanon2Position(_laserCanon, Direction::LEFT);

    CHECK(get<0>(_laserCanon.entityPosition()) == xPosition - _laserCanon.getEntitySpeed());
    _gameUpdater.updateLaserCanon1Position(_laserCanon, Direction::RIGHT);
    CHECK(get<0>(_laserCanon.entityPosition()) == xPosition);
    _gameUpdater.updateLaserCanon1Position(_laserCanon, Direction::DOWN);
    CHECK(get<1>(_laserCanon.entityPosition()) == yPosition + _laserCanon.getEntitySpeed());
    _gameUpdater.updateLaserCanon1Position(_laserCanon, Direction::UP);
    CHECK(get<1>(_laserCanon.entityPosition()) == yPosition);
}

TEST_CASE("Laser Canon 1 obeys the left boundary restrictions")
{
    auto xPosition = 190;
    auto yPosition = 480;

    auto _laserCanon = LaserCanon{ xPosition, yPosition, 1, 3 };
    _laserCanon.setXposition(get<0>(_laserCanon.getMovementBoundaries()));

    auto _gameUpdater = GameUpdater{};
    _gameUpdater.updateLaserCanon1Position(_laserCanon, Direction::LEFT);
    CHECK_FALSE(get<0>(_laserCanon.entityPosition()) == xPosition - _laserCanon.getEntitySpeed());
    CHECK(get<0>(_laserCanon.entityPosition()) == get<0>(_laserCanon.getMovementBoundaries()));
}

TEST_CASE("Laser Canon 2 obeys the left boundary restrictions")
{
    auto xPosition = 190;
    auto yPosition = 40;

    auto _laserCanon = LaserCanon{ xPosition, yPosition, 2, 3 };
    _laserCanon.setXposition(get<0>(_laserCanon.getMovementBoundaries()));

    auto _gameUpdater = GameUpdater{};
    _gameUpdater.updateLaserCanon2Position(_laserCanon, Direction::LEFT);
    CHECK_FALSE(get<0>(_laserCanon.entityPosition()) == xPosition - _laserCanon.getEntitySpeed());
    CHECK(get<0>(_laserCanon.entityPosition()) == get<0>(_laserCanon.getMovementBoundaries()));
}

TEST_CASE("Laser Canon 1 obeys the right boundary restrictions")
{
    auto xPosition = 190;
    auto yPosition = 480;

    auto _laserCanon = LaserCanon{ xPosition, yPosition, 1, 3 };
    _laserCanon.setXposition(get<1>(_laserCanon.getMovementBoundaries()));

    auto _gameUpdater = GameUpdater{};
    _gameUpdater.updateLaserCanon1Position(_laserCanon, Direction::RIGHT);
    CHECK_FALSE(get<0>(_laserCanon.entityPosition()) == xPosition + _laserCanon.getEntitySpeed());
    CHECK(get<0>(_laserCanon.entityPosition()) == get<1>(_laserCanon.getMovementBoundaries()));
}

TEST_CASE("Laser Canon 2 obeys the right boundary restrictions")
{
    auto xPosition = 190;
    auto yPosition = 40;

    auto _laserCanon = LaserCanon{ xPosition, yPosition, 2, 3 };
    _laserCanon.setXposition(get<1>(_laserCanon.getMovementBoundaries()));

    auto _gameUpdater = GameUpdater{};
    _gameUpdater.updateLaserCanon2Position(_laserCanon, Direction::RIGHT);
    CHECK_FALSE(get<0>(_laserCanon.entityPosition()) == xPosition + _laserCanon.getEntitySpeed());
    CHECK(get<0>(_laserCanon.entityPosition()) == get<1>(_laserCanon.getMovementBoundaries()));
}

TEST_CASE("Testing the destroyEntity function for laserCanon")
{
    auto xPosition = 190;
    auto yPosition = 480;
    auto laserCanonLives = 3;

    auto _laserCanon = LaserCanon{ xPosition, yPosition, 1, laserCanonLives };
    _laserCanon.destroyEntity();
    CHECK(_laserCanon.getNumberOfLives() == laserCanonLives - 1);
}

TEST_CASE("LaserCanon life is set false when it's number of lives is zero")
{
    auto xPosition = 190;
    auto yPosition = 480;
    auto laserCanonLives = 1;

    auto _laserCanon = LaserCanon{ xPosition, yPosition, 1, laserCanonLives };
    _laserCanon.destroyEntity();
    CHECK(_laserCanon.getNumberOfLives() == 0);
    CHECK(_laserCanon.isAlive() == false);
}

TEST_CASE("Collision detection of laserCanon1 and the laser from canon2 and they are both destroyed")
{
    auto laserCanon1_Xposition = 190;
    auto laserCanon1_Yposition = 480;
    auto laserCanon2_Xposition = 190;
    auto laserCanon2_Yposition = 40;

    auto laserCanonLives = 1;

    auto _laserCanon1 = LaserCanon{ laserCanon1_Xposition, laserCanon1_Yposition, 1, laserCanonLives };
    auto _laserCanon2 = LaserCanon{ laserCanon2_Xposition, laserCanon2_Yposition, 2, laserCanonLives };
    auto _laser1 = Laser{ _laserCanon1, 1 };
    auto _laser2 = Laser{ _laserCanon2, 1 };

    _laser2.setXposition(laserCanon1_Xposition);
    _laser2.setYposition(laserCanon1_Yposition);
    _laser2.giveEntityLife();

    auto _collisionHandler = CollisionHandler{};
    _collisionHandler.handleLaserCanonLaserCollision(_laserCanon1, _laserCanon2, _laser1, _laser2);
    CHECK_FALSE(_laserCanon1.isAlive());
    CHECK_FALSE(_laser2.isAlive());
}

TEST_CASE("Collision detection of laserCanon2 and the laser from canon1 and they both get destroyed")
{
    auto laserCanon1_Xposition = 190;
    auto laserCanon1_Yposition = 480;
    auto laserCanon2_Xposition = 190;
    auto laserCanon2_Yposition = 40;

    auto laserCanonLives = 1;

    auto _laserCanon1 = LaserCanon{ laserCanon1_Xposition, laserCanon1_Yposition, 1, laserCanonLives };
    auto _laserCanon2 = LaserCanon{ laserCanon2_Xposition, laserCanon2_Yposition, 2, laserCanonLives };
    auto _laser1 = Laser{ _laserCanon1, 1 };
    auto _laser2 = Laser{ _laserCanon2, 1 };

    _laser1.setXposition(laserCanon2_Xposition);
    _laser1.setYposition(laserCanon2_Yposition);
    _laser1.giveEntityLife();

    auto _collisionHandler = CollisionHandler{};
    _collisionHandler.handleLaserCanonLaserCollision(_laserCanon1, _laserCanon2, _laser1, _laser2);
    CHECK_FALSE(_laserCanon2.isAlive());
    CHECK_FALSE(_laser1.isAlive());
}

//------------------------------------------------------LaserCanonShieldTests------------------------------------

TEST_CASE("Exception throw for invalid shield positions")
{
    // acceptable y_position = 70 or 450
    auto x_position = 180;
    auto y_position = 80;
    CHECK_THROWS_AS(LaserCanonShield(x_position, y_position, 1, 3), InvalidShieldPosition);
}

TEST_CASE("Shields can be created with valid positions")
{
    auto x_position = 180;
    auto y_position = 450;
    auto _shield = LaserCanonShield{ x_position, y_position, true, 3 };
    auto [shieldX, shieldY] = _shield.entityPosition();
    CHECK(x_position == shieldX);
    CHECK(y_position == shieldY);
}

TEST_CASE("Number of lives decrease when a shield is destroyed and it's life is set false when it runs out of lives")
{
    auto numberOfLives = 2;
    auto _shield = LaserCanonShield{ 180, 450, true, numberOfLives };
    CHECK(_shield.isAlive());
    _shield.destroyEntity();
    CHECK(_shield.isAlive());
    CHECK(_shield.getNumberOfLives() == numberOfLives - 1);
    _shield.destroyEntity();
    CHECK_FALSE(_shield.isAlive());
}

TEST_CASE("Shield  does not get destroyed when hit by a canon laser but the laser gets destroyed")
{
    auto x_position = 180;
    auto y_position = 450;
    auto _shield = LaserCanonShield{ x_position, y_position, true, 3 };
    auto _laserCanon = LaserCanon{ 190, 480, 1, 3 };
    auto _laser = Laser{ _laserCanon, 1 };

    _laser.setXposition(x_position);
    _laser.setYposition(y_position);
    _laser.giveEntityLife();
    auto _collisionHandler = CollisionHandler{};
    _collisionHandler.handleLaserCanonShieldLaserCollission(_shield, _laser, _laser);
    CHECK_FALSE(_laser.isAlive());
    CHECK(_shield.getNumberOfLives() == 3);
}

TEST_CASE("Both the shield and the alien laser gets destroyed when they collide")
{
    auto x_position = 180;
    auto y_position = 450;
    auto _shield = LaserCanonShield{ x_position, y_position, true, 1 };
    auto _alien = Alien{ 200, 200, 380, 0, 1, AlienColour::RED };
    auto _alienLaser = Laser{ _alien, 1 };
    _alienLaser.setXposition(x_position);
    _alienLaser.setYposition(y_position);
    _alienLaser.giveEntityLife();

    auto _collisionHandler = CollisionHandler{};
    _collisionHandler.handleLaserCanonShieldAlienLaserCollision(_shield, _alienLaser);
    CHECK_FALSE(_alienLaser.isAlive());
    CHECK_FALSE(_shield.isAlive());
}

//--------------------------------------------------AlienTests----------------------------------------

TEST_CASE("Exception throw for Invalid Alien Coordinates")
{
    auto x_position = 390;
    auto y_position = 400;
    CHECK_THROWS_AS(Alien(x_position, y_position, 380, 0, 1, AlienColour::GREEN), InvalidAlienCoordinates);

    x_position = 200;
    y_position = 490;
    CHECK_THROWS_AS(Alien(x_position, y_position, 380, 0, 1, AlienColour::GREEN), InvalidAlienCoordinates);

    x_position = 200;
    y_position = 39;
    CHECK_THROWS_AS(Alien(x_position, y_position, 380, 0, 1, AlienColour::GREEN), InvalidAlienCoordinates);
}

TEST_CASE("Testing if the Alien class is able to create a valid object with initial positions")
{
    auto xPosition = 200;
    auto yPosition = 200;

    auto _alien = Alien{ xPosition, yPosition, 380, 0, 1, AlienColour::GREEN };
    auto [alien_Xposition, alien_Yposition] = _alien.entityPosition();
    CHECK(alien_Xposition == xPosition);
    CHECK(alien_Yposition == yPosition);
}

TEST_CASE("Testing the move fuction")
{
    auto xPosition = 200;
    auto yPosition = 200;

    auto _alien = Alien{ xPosition, yPosition, 380, 0, 1, AlienColour::GREEN };

    _alien.move(Direction::LEFT);
    CHECK(get<0>(_alien.entityPosition()) == xPosition - _alien.getEntitySpeed());

    _alien.move(Direction::RIGHT);
    CHECK(get<0>(_alien.entityPosition()) == xPosition);

    _alien.move(Direction::UP);
    CHECK(get<1>(_alien.entityPosition()) == yPosition - 2 * _alien.getEntitySpeed());

    _alien.move(Direction::DOWN);
    CHECK(get<1>(_alien.entityPosition()) == yPosition);
}

TEST_CASE("Testing the move function at right boundary")
{
    auto xPosition = 380;
    auto yPosition = 200;

    auto _alien = Alien{ xPosition, yPosition, 380, 0, 1, AlienColour::GREEN };
    _alien.move(Direction::RIGHT);
    CHECK(get<0>(_alien.entityPosition()) == xPosition);
}

TEST_CASE("Testing the move function at left boundary")
{
    auto xPosition = 0;
    auto yPosition = 200;

    auto _alien = Alien{ xPosition, yPosition, 380, 0, 1, AlienColour::GREEN };
    _alien.move(Direction::LEFT);
    CHECK(get<0>(_alien.entityPosition()) == xPosition);
}

TEST_CASE("Testing the move function at upper boundary")
{
    auto xPosition = 0;
    auto yPosition = 80;

    auto _alien = Alien{ xPosition, yPosition, 380, 0, 1, AlienColour::GREEN };
    _alien.move(Direction::UP);
    CHECK(get<1>(_alien.entityPosition()) == yPosition);
}

TEST_CASE("Testing the move function at bottom boundary")
{
    auto xPosition = 380;
    auto yPosition = 460;

    auto _alien = Alien{ xPosition, yPosition, 380, 0, 1, AlienColour::GREEN };
    _alien.move(Direction::DOWN);
    CHECK(get<1>(_alien.entityPosition()) == yPosition);
}

TEST_CASE("Alien gets destroyed when hit by a laserCanon laser")
{
    auto alienXposition = 200;
    auto alienYposition = 200;
    auto alienLives = 1;

    auto _laserCanon1 = LaserCanon{ 190, 480, 1, 3 };
    auto _laserCanon2 = LaserCanon{ 190, 40, 2, 3 };
    auto _laser1 = Laser{ _laserCanon1, 1 };
    auto _laser2 = Laser{ _laserCanon2, 1 };

    auto _alien = Alien{ alienXposition, alienYposition, 380, 0, alienLives, AlienColour::GREEN };
    auto _scoreBoard = ScoreBoard{};

    _laser1.setXposition(alienXposition);
    _laser1.setYposition(alienYposition);
    _laser1.giveEntityLife();

    auto _collisionHandler = CollisionHandler{};
    _collisionHandler.handleLaserAlienCollision(_laser1, _laser2, _alien, _scoreBoard);
    CHECK(_alien.isAlive() == false);
    CHECK_FALSE(_laser1.isAlive());
}

TEST_CASE("Score gets updated correctly for green aliens")
{
    auto alienXposition = 200;
    auto alienYposition = 200;
    auto alienLives = 1;

    auto _laserCanon1 = LaserCanon{ 190, 480, 1, 3 };
    auto _laserCanon2 = LaserCanon{ 190, 40, 2, 3 };
    auto _laser1 = Laser{ _laserCanon1, 1 };
    auto _laser2 = Laser{ _laserCanon2, 1 };

    auto _alien = Alien{ alienXposition, alienYposition, 380, 0, alienLives, AlienColour::GREEN };
    auto _scoreBoard = ScoreBoard{};

    _laser1.setXposition(alienXposition);
    _laser1.setYposition(alienYposition);
    _laser1.giveEntityLife();

    CHECK(_scoreBoard.getScore() == 0);
    auto _collisionHandler = CollisionHandler{};
    _collisionHandler.handleLaserAlienCollision(_laser1, _laser2, _alien, _scoreBoard);
    CHECK(_scoreBoard.getScore() == _alien.alienPoints(_alien.getAlienColour()));
}

TEST_CASE("Score gets updated correctly for purple aliens")
{
    auto alienXposition = 200;
    auto alienYposition = 200;
    auto alienLives = 1;

    auto _laserCanon1 = LaserCanon{ 190, 480, 1, 3 };
    auto _laserCanon2 = LaserCanon{ 190, 40, 2, 3 };
    auto _laser1 = Laser{ _laserCanon1, 1 };
    auto _laser2 = Laser{ _laserCanon2, 1 };

    auto _alien = Alien{ alienXposition, alienYposition, 380, 0, alienLives, AlienColour::PURPLE };
    auto _scoreBoard = ScoreBoard{};

    _laser1.setXposition(alienXposition);
    _laser1.setYposition(alienYposition);
    _laser1.giveEntityLife();

    CHECK(_scoreBoard.getScore() == 0);
    auto _collisionHandler = CollisionHandler{};
    _collisionHandler.handleLaserAlienCollision(_laser1, _laser2, _alien, _scoreBoard);
    CHECK(_scoreBoard.getScore() == _alien.alienPoints(_alien.getAlienColour()));
}

TEST_CASE("Score gets updated correctly for red aliens")
{
    auto alienXposition = 200;
    auto alienYposition = 200;
    auto alienLives = 1;

    auto _laserCanon1 = LaserCanon{ 190, 480, 1, 3 };
    auto _laserCanon2 = LaserCanon{ 190, 40, 2, 3 };
    auto _laser1 = Laser{ _laserCanon1, 1 };
    auto _laser2 = Laser{ _laserCanon2, 1 };

    auto _alien = Alien{ alienXposition, alienYposition, 380, 0, alienLives, AlienColour::RED };
    auto _scoreBoard = ScoreBoard{};

    _laser1.setXposition(alienXposition);
    _laser1.setYposition(alienYposition);
    _laser1.giveEntityLife();

    CHECK(_scoreBoard.getScore() == 0);
    auto _collisionHandler = CollisionHandler{};
    _collisionHandler.handleLaserAlienCollision(_laser1, _laser2, _alien, _scoreBoard);
    CHECK(_scoreBoard.getScore() == _alien.alienPoints(_alien.getAlienColour()));
}

//--------------------------------------AlienLaserTests-------------------------------------------

TEST_CASE("Able to initialise alien laser positions")
{
    auto xPosition = 200;
    auto yPosition = 200;
    auto _alien = Alien{ xPosition, yPosition, 380, 0, 1, AlienColour::RED };
    auto _alienLaser = Laser{ _alien, 1 };

    auto [x_position, y_position] = _alienLaser.entityPosition();
    CHECK(x_position == xPosition);
    CHECK(y_position == yPosition);
}

TEST_CASE("Laser is able to move up the screen")
{
    auto xPosition = 200;
    auto yPosition = 200;
    auto _alien = Alien{ xPosition, yPosition, 380, 0, 1, AlienColour::RED };

    auto _alienLaser = Laser{ _alien, 1 };
    _alienLaser.move(Direction::UP);
    auto y_position = get<1>(_alienLaser.entityPosition());
    CHECK(y_position == yPosition - _alienLaser.getEntitySpeed());
}

TEST_CASE("Laser is able to move down the screen")
{
    auto xPosition = 200;
    auto yPosition = 200;
    auto _alien = Alien{ xPosition, yPosition, 380, 0, 1, AlienColour::RED };

    auto _alienLaser = Laser{ _alien, 1 };
    _alienLaser.move(Direction::DOWN);
    auto y_position = get<1>(_alienLaser.entityPosition());
    CHECK(y_position == yPosition + _alienLaser.getEntitySpeed());
}

TEST_CASE("Able to set the laser alive and also destroy it")
{
    auto xPosition = 200;
    auto yPosition = 200;
    auto _alien = Alien{ xPosition, yPosition, 380, 0, 1, AlienColour::RED };

    auto _alienLaser = Laser{ _alien, 1 };
    CHECK_FALSE(_alienLaser.isAlive());
    _alienLaser.giveEntityLife();
    CHECK(_alienLaser.isAlive());
    _alienLaser.destroyEntity();
    CHECK_FALSE(_alienLaser.isAlive());
}

TEST_CASE("Laser does not go above the upper screen boundary, it gets distroyed and goes back to the alien")
{
    auto xPosition = 200;
    auto yPosition = 200;
    auto _alien = Alien{ xPosition, yPosition, 380, 0, 1, AlienColour::RED };

    auto _alienLaser = Laser{ _alien, 1 };
    auto upperBoundary = get<2>(_alienLaser.getMovementBoundaries());
    _alienLaser.setYposition(upperBoundary);
    _alienLaser.giveEntityLife();

    auto _gameUpdater = GameUpdater{};

    _gameUpdater.updateUpAlienLaserPosition(_alien, _alienLaser);
    CHECK_FALSE(_alienLaser.isAlive());
    _gameUpdater.updateUpAlienLaserPosition(_alien, _alienLaser);

    auto y_position = get<1>(_alien.entityPosition());
    auto y_position2 = get<1>(_alienLaser.entityPosition());
    CHECK(y_position + 5 == y_position2);
}

TEST_CASE("Laser does not go below the bottom screen boundary, it gets distroyed and goes back to the alien")
{
    auto xPosition = 200;
    auto yPosition = 200;
    auto _alien = Alien{ xPosition, yPosition, 380, 0, 1, AlienColour::RED };

    auto _alienLaser = Laser{ _alien, 1 };
    auto bottomBoundary = get<3>(_alienLaser.getMovementBoundaries());
    _alienLaser.setYposition(bottomBoundary);
    _alienLaser.giveEntityLife();

    auto _gameUpdater = GameUpdater{};
    _gameUpdater.updateAlienLaserPosition(_alien, _alienLaser);
    CHECK_FALSE(_alienLaser.isAlive());
    _gameUpdater.updateAlienLaserPosition(_alien, _alienLaser);
    auto y_position = get<1>(_alien.entityPosition());
    auto y_position2 = get<1>(_alienLaser.entityPosition());
    CHECK(y_position + 5 == y_position2);
}

TEST_CASE("Collision detector is able to detect the collision between alien laser and canon laser")
{
    auto alienXposition = 200;
    auto alienYposition = 200;
    auto canon1_Xposition = 190;
    auto canon1_Yposition = 480;
    auto canon2_Xposition = 190;
    auto canon2_Yposition = 40;

    auto _alien = Alien{ alienXposition, alienYposition, 380, 0, 1, AlienColour::RED };
    auto _alienLaser = Laser{ _alien, 1 };
    auto _laserCanon1 = LaserCanon{ canon1_Xposition, canon1_Yposition, 1, 3 };
    auto _laser1 = Laser{ _laserCanon1, 1 };
    auto _laserCanon2 = LaserCanon{ canon2_Xposition, canon2_Yposition, 2, 3 };
    auto _laser2 = Laser{ _laserCanon2, 1 };

    _laser1.giveEntityLife();
    _laser2.giveEntityLife();
    _alienLaser.giveEntityLife();
    _laser1.setYposition(300);
    _laser1.setXposition(300);
    _laser2.setYposition(300);
    _laser2.setXposition(300);
    _alienLaser.setYposition(300);
    _alienLaser.setXposition(300);

    auto _collisionDetector = CollisionDetector{};
    auto [isLaser1, isLaser2] = _collisionDetector.LaserAliensLaserCollision(_laser1, _laser2, _alienLaser);
    CHECK(isLaser1 == true);
    CHECK(isLaser2 == true);
}

TEST_CASE("Collision handler is able to destroy the alien laser and canon laser when they collide")
{
    auto alienXposition = 200;
    auto alienYposition = 200;
    auto canon1_Xposition = 190;
    auto canon1_Yposition = 480;
    auto canon2_Xposition = 190;
    auto canon2_Yposition = 40;

    auto _alien = Alien{ alienXposition, alienYposition, 380, 0, 1, AlienColour::RED };
    auto _alienLaser = Laser{ _alien, 1 };
    auto _laserCanon1 = LaserCanon{ canon1_Xposition, canon1_Yposition, 1, 3 };
    auto _laser1 = Laser{ _laserCanon1, 1 };
    auto _laserCanon2 = LaserCanon{ canon2_Xposition, canon2_Yposition, 2, 3 };
    auto _laser2 = Laser{ _laserCanon2, 1 };

    _laser1.giveEntityLife();
    _laser2.giveEntityLife();
    _alienLaser.giveEntityLife();
    _laser1.setYposition(300);
    _laser1.setXposition(300);
    _laser2.setYposition(300);
    _laser2.setXposition(300);
    _alienLaser.setYposition(300);
    _alienLaser.setXposition(300);

    auto _collisionHandler = CollisionHandler{};
    _collisionHandler.handleLaserAliensLaserCollision(_laser1, _laser2, _alienLaser);
    CHECK_FALSE(_laser1.isAlive());
    CHECK_FALSE(_laser2.isAlive());
    CHECK_FALSE(_alienLaser.isAlive());
}
