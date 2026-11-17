#ifndef SCORESYSTEM_H
#define SCORESYSTEM_H

#include <iostream>
using namespace std;

// Keeps track of the player's points.
class ScoreSystem{
private:
    int score;
    int clueFoundPoints;
    int interviewPoints;
    int contradictionPoints;
    int rightAccusationPoints;
    int wrongAccusationPoints;
public:
    ScoreSystem();

    void addClueFound();
    void addInterview();
    void addContradiction();
    void accuse(bool correct);

    int getScore();
    void displayScore();
};

#endif
