#include "ScoreSystem.h"

ScoreSystem::ScoreSystem(){
    score = 0;
    clueFoundPoints = 10;
    interviewPoints = 5;
    contradictionPoints = 10;
    rightAccusationPoints = 50;
    wrongAccusationPoints = -20;
}

void ScoreSystem::addClueFound(){
    score = score + clueFoundPoints;
}

void ScoreSystem::addInterview(){
    score = score + interviewPoints;
}

void ScoreSystem::addContradiction(){
    score = score + contradictionPoints;
}

void ScoreSystem::accuse(bool correct){
    if (correct){
        score = score + rightAccusationPoints;
    }
    else{
        score = score + wrongAccusationPoints;
    }
}

int ScoreSystem::getScore(){
    return score;
}

void ScoreSystem::displayScore(){
    cout << "Score: " << score << endl;
}
