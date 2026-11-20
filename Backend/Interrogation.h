#ifndef INTERROGATION_H
#define INTERROGATION_H
#include <vector>
#include "Suspect.h"
#include "Case.h"

struct QA {
    string question;
    string answer;
    int contradictedByClue;   // clue id that exposes this answer as a lie (0 = none)
};

class Interrogation {
private:
    Suspect* suspect;
    vector<QA> list;
    vector<bool> asked;
public:
    Interrogation(Suspect* s);
    void addQA(string q, string a, int contradictedByClue);
    int getQuestionCount() const;
    string getQuestion(int number) const;   // number starts at 1
    string getAnswer(int number) const;     // number starts at 1
    void displayQuestions() const;
    string ask(int number);                 // number starts at 1
    int checkContradictions(Case& c);       // returns how many were found
};
#endif
