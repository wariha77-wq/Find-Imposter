#include "Clue.h"

Clue::Clue(int id, string t, string d, string loc, int suspectId) {
    clueId = id; title = t; description = d; location = loc;
    pointsTo = suspectId; discovered = false;
}
int Clue::getId() const { return clueId; }
string Clue::getTitle() const { return title; }
string Clue::getDescription() const { return description; }
string Clue::getLocation() const { return location; }
int Clue::getPointsTo() const { return pointsTo; }
bool Clue::isDiscovered() const { return discovered; }
void Clue::discover() { discovered = true; }
void Clue::display() const {
    cout << "Clue #" << clueId << " - " << title << " (" << location << "): "
         << description << endl;
}
