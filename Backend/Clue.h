#ifndef CLUE_H
#define CLUE_H
#include <iostream>
#include <string>
using namespace std;

class Clue {
private:
    int clueId;
    string title;
    string description;
    string location;
    int pointsTo;        // suspect id this clue points to (0 = nobody)
    bool discovered;
public:
    Clue(int id, string t, string d, string loc, int suspectId);
    int getId() const;
    string getTitle() const;
    string getDescription() const;
    string getLocation() const;
    int getPointsTo() const;
    bool isDiscovered() const;
    void discover();
    void display() const;
};
#endif
