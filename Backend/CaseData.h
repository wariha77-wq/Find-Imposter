#ifndef CASEDATA_H
#define CASEDATA_H

#include <iostream>
#include <string>
#include <vector>
#include "Suspect.h"
#include "Location.h"
#include "Evidence.h"
#include "Dialogue.h"
#include "Contradiction.h"
using namespace std;

// Holds all the story content for one case: "The Missing Painting".
// Culprit: Hamza Malik (suspect ID 3).
class CaseData{
private:
    string title;
    string story;
    int culpritId;

    vector<Suspect> suspects;
    vector<Location> locations;
    vector<Evidence> evidences;
    vector<Dialogue> dialogues;
    vector<Contradiction> contradictions;

    // helper functions that fill the data (used only by the constructor)
    void createSuspects();
    void createLocations();
    void createEvidence();
    void createDialogues();
    void createContradictions();
public:
    CaseData();

    string getTitle();
    string getStory();
    int getCulpritId();
    bool isCulprit(int suspectId);

    int getSuspectCount();
    Suspect& getSuspect(int index);

    int getLocationCount();
    Location& getLocation(int index);

    int getEvidenceCount();
    Evidence& getEvidence(int index);

    int getDialogueCount();
    Dialogue& getDialogue(int index);

    int getContradictionCount();
    Contradiction& getContradiction(int index);

    // Investigates a location and discovers its clues.
    // Returns how many NEW clues were found.
    int investigateLocation(int index);

    // Discovers one clue by its ID. Returns true if it was new.
    bool discoverEvidenceById(int evidenceId);

    void displayCaseIntro();
};

#endif
