#ifndef CASE_H
#define CASE_H
#include <vector>
#include <utility>
#include "Suspect.h"
#include "Clue.h"
#include "Location.h"

// Scoring (change these numbers if your teacher wants different points)
const int POINTS_PER_CLUE      = 8;
const int POINTS_PER_CONNECTION = 10;
const int POINTS_CORRECT_ACCUSE = 20;

class Case {
private:
    string title;
    string summary;
    vector<Suspect> suspects;
    vector<Clue> clues;
    vector<Location> locations;
    vector<pair<int,int> > validLinks;
    vector<pair<int,int> > madeLinks;
    int culpritId;
    bool accusedCorrectly;
public:
    Case(string t, string s);
    void addSuspect(const Suspect& s);
    void addClue(const Clue& c);
    void addLocation(const Location& l);
    void addValidLink(int clueA, int clueB);
    void setCulprit(int suspectId);

    Suspect* findSuspect(int id);
    Clue* findClue(int id);
    Location* findLocation(int id);

    string getTitle() const;
    int getClueCount() const;
    int getSuspectCount() const;

    void displayIntro() const;
    void displaySuspects() const;
    void investigateLocation(int locationId);
    bool discoverClue(int id);
    int discoveredCount() const;
    void displayEvidenceBoard() const;
    bool connectClues(int a, int b);
    int connectionCount() const;
    bool accuse(int suspectId, int strongestClueId);
    int getScore() const;
};
#endif
