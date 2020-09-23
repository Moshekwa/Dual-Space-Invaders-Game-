/**
 * @file ScoreBoard.h
 * @class ScoreBoard
 * @brief This class is responsible for keeping the score and high score of the player or players.
 * @bug No Known Bugs.
 * @version 3.0
 * @date 25/09/2019
 */

#ifndef SCOREBOARD_H_INCLUDED
#define SCOREBOARD_H_INCLUDED

class FileCannotBeOpened
{
};

class ScoreBoard
{
public:
    ScoreBoard();
    void setScore(int score);
    int getHighScore() const;
    int getScore() const;
    void readHighScoreFromFile();
    void readHighScoreIntoFile();
    ~ScoreBoard(){};
private:
    int _score;
    int _highScore;
};

#endif // SCOREBOARD_H_INCLUDED