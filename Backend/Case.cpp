#include "Case.h"

Case::Case(string t, string s) {
    title = t; summary = s;
    culpritId = -1; accusedCorrectly = false;
}
void Case::addSuspect(const Suspect& s) { suspects.push_back(s); }
void Case::addClue(const Clue& c) { clues.push_back(c); }
void Case::addLocation(const Location& l) { locations.push_back(l); }
void Case::addValidLink(int a, int b) { validLinks.push_back(make_pair(a, b)); }
void Case::setCulprit(int id) { culpritId = id; }

Suspect* Case::findSuspect(int id) {
    for (size_t i = 0; i < suspects.size(); i++)
        if (suspects[i].getId() == id) return &suspects[i];
    return NULL;
}
Clue* Case::findClue(int id) {
    for (size_t i = 0; i < clues.size(); i++)
        if (clues[i].getId() == id) return &clues[i];
    return NULL;
}
Location* Case::findLocation(int id) {
    for (size_t i = 0; i < locations.size(); i++)
        if (locations[i].getLocationID() == id) return &locations[i];
    return NULL;
}
string Case::getTitle() const { return title; }
int Case::getClueCount() const { return (int)clues.size(); }
int Case::getSuspectCount() const { return (int)suspects.size(); }

void Case::displayIntro() const {
    cout << "=== " << title << " ===\n" << summary << endl;
}
void Case::displaySuspects() const {
    cout << "\n--- Suspects (" << suspects.size() << ") ---";
    for (size_t i = 0; i < suspects.size(); i++) suspects[i].displaySuspect();
}
void Case::investigateLocation(int locationId) {
    Location* l = findLocation(locationId);
    if (l) l->investigate();
}
bool Case::discoverClue(int id) {
    Clue* c = findClue(id);
    if (c == NULL || c->isDiscovered()) return false;
    c->discover();
    cout << "\n[New clue discovered] ";
    c->display();
    cout << "Clues recovered: " << discoveredCount() << "/" << clues.size() << endl;
    return true;
}
int Case::discoveredCount() const {
    int n = 0;
    for (size_t i = 0; i < clues.size(); i++)
        if (clues[i].isDiscovered()) n++;
    return n;
}
void Case::displayEvidenceBoard() const {
    cout << "\n--- Evidence Wall (" << discoveredCount() << "/" << clues.size() << ") ---" << endl;
    for (size_t i = 0; i < clues.size(); i++)
        if (clues[i].isDiscovered()) clues[i].display();
    for (size_t i = 0; i < madeLinks.size(); i++)
        cout << "Connection: Clue #" << madeLinks[i].first << " <-> Clue #"
             << madeLinks[i].second << endl;
}
bool Case::connectClues(int a, int b) {
    Clue* ca = findClue(a);
    Clue* cb = findClue(b);
    if (!ca || !cb || !ca->isDiscovered() || !cb->isDiscovered()) {
        cout << "\nYou need to discover both clues first." << endl;
        return false;
    }
    for (size_t i = 0; i < madeLinks.size(); i++)
        if ((madeLinks[i].first == a && madeLinks[i].second == b) ||
            (madeLinks[i].first == b && madeLinks[i].second == a)) {
            cout << "\nYou already made that connection." << endl;
            return false;
        }
    for (size_t i = 0; i < validLinks.size(); i++) {
        if ((validLinks[i].first == a && validLinks[i].second == b) ||
            (validLinks[i].first == b && validLinks[i].second == a)) {
            madeLinks.push_back(make_pair(a, b));
            cout << "\nClue connection successful: \"" << ca->getTitle()
                 << "\" and \"" << cb->getTitle() << "\" are linked!" << endl;
            return true;
        }
    }
    cout << "\nThose clues do not connect." << endl;
    return false;
}
int Case::connectionCount() const { return (int)madeLinks.size(); }

bool Case::accuse(int suspectId, int strongestClueId) {
    Suspect* s = findSuspect(suspectId);
    if (!s) return false;
    cout << "\nI ACCUSE... " << s->getName() << "!" << endl;
    Clue* c = findClue(strongestClueId);
    if (c && c->isDiscovered()) {
        cout << "Strongest evidence: " << c->getTitle() << endl;
        if (c->getPointsTo() == suspectId)
            cout << "That evidence supports your accusation." << endl;
        else
            cout << "That evidence does not really point to " << s->getName() << "." << endl;
    }
    accusedCorrectly = (suspectId == culpritId);
    if (accusedCorrectly) cout << "Correct accusation! The impostor is caught." << endl;
    else cout << "Wrong accusation. The real thief escapes." << endl;
    return accusedCorrectly;
}
int Case::getScore() const {
    int score = discoveredCount() * POINTS_PER_CLUE
              + connectionCount() * POINTS_PER_CONNECTION;
    if (accusedCorrectly) score += POINTS_CORRECT_ACCUSE;
    return score;
}
