#include "ScoreBoard.h"
#include <fstream>
using namespace std;

ScoreBoard::ScoreBoard()
    : _score{ 0 }
{
    readHighScoreFromFile();
}

void ScoreBoard::setScore(int score)
{
    _score = score;
    if(_score > _highScore) {
        _highScore = _score;
    }
}

int ScoreBoard::getScore() const
{
    return _score;
}

int ScoreBoard::getHighScore() const
{
    return _highScore;
}

void ScoreBoard::readHighScoreFromFile()
{
    ifstream infile("HighScore.txt");

    if(!infile) {
        throw FileCannotBeOpened{};
    }
    infile >> _highScore;
}

void ScoreBoard::readHighScoreIntoFile()
{

    ofstream outfile("HighScore.txt");
    if(!outfile) {
        throw FileCannotBeOpened{};
    }
    outfile << _highScore;
}