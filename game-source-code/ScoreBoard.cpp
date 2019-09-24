#include "ScoreBoard.h"
#include <fstream>
using namespace std;

ScoreBoard::ScoreBoard()
    : _score{ 0 }
{
    readHighScoreFromFile(1);
   // readHighScoreFromFile(2);
}

ScoreBoard::~ScoreBoard()
{
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

void ScoreBoard::readHighScoreFromFile(int canonNumber)
{
    if(canonNumber == 1) {
        ifstream infile("HighScore.txt");

        if(!infile) {
            throw FileCannotBeOpened{};
        }
        infile >> _highScore;
    }
    if(canonNumber == 2) {
        ifstream infile2("HighScore2.txt");

        if(!infile2) {
            throw FileCannotBeOpened{};
        }
        infile2 >> _highScore;
    }
}

void ScoreBoard::readHighScoreIntoFile(int canonNumber)
{
    if(canonNumber == 1) {
        ofstream outfile("HighScore.txt");
        if(!outfile) {
            throw FileCannotBeOpened{};
        }
        outfile << _highScore;
    }
    if(canonNumber == 2) {
        ofstream outfile2("HighScore2.txt");
        if(!outfile2) {
            throw FileCannotBeOpened{};
        }
        outfile2 << _highScore;
    }
}