#include "Clue.h"

Clue::Clue(int id, string t, string d, string loc, int suspectId)
    : Evidence(id, t, d, loc) {
    pointsTo = suspectId;
}

int Clue::getId() const {
    return EvidenceId;
}

int Clue::getPointsTo() const {
    return pointsTo;
}

void Clue::display() const {
    cout << "Clue #" << EvidenceId << " - " << title << " (" << foundAt << "): "
         << description << endl;
}

void Clue::displayEvidence() const {
    display();
}
