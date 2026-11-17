#ifndef CONTRADICTION_H
#define CONTRADICTION_H

#include <iostream>
#include <string>
using namespace std;

// A suspect's claim that is proven false by one piece of evidence.
class Contradiction{
private:
    int suspectId;
    string statement;   // what the suspect claimed
    int evidenceId;     // the clue that proves the claim false
    bool caught;        // has the player caught it yet?
public:
    Contradiction(int sid, string s, int eid);

    int getSuspectId();
    string getStatement();
    int getEvidenceId();
    bool isCaught();

    void catchContradiction();
    void displayContradiction();
};

#endif
