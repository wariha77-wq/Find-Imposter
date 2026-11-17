#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <iostream>
#include <string>
using namespace std;

// One question the player can ask a suspect, and the suspect's answer.
class Dialogue{
private:
    int suspectId;          // which suspect answers
    string question;
    string answer;
    bool lie;               // true if the answer is a lie
    int unlocksEvidenceId;  // 0 means it unlocks nothing
public:
    Dialogue(int sid, string q, string a, bool isLie, int evidenceId);

    int getSuspectId();
    string getQuestion();
    string getAnswer();
    bool isLie();
    int getUnlocksEvidenceId();

    void displayDialogue();
};

#endif
