#ifndef SCOREBOARD_H_INCLUDED
#define SCOREBOARD_H_INCLUDED

class FileCannotBeOpened
{
};

class ScoreBoard
{
public:
    ScoreBoard();
    ~ScoreBoard();
    void setScore(int score);
    int getScore() const;
    void readHighScoreFromFile(int canonNumber);
    void readHighScoreIntoFile(int canonNumber);

private:
    int _score;
    int _highScore;
};

#endif // SCOREBOARD_H_INCLUDED