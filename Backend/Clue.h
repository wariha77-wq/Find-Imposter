#ifndef CLUE_H
#define CLUE_H

#include "Evidence.h"

class Clue : public Evidence {
private:
    int pointsTo; // suspect id this clue points to (0 = nobody)

public:
    Clue(int id, string t, string d, string loc, int suspectId);

    int getId() const;
    int getPointsTo() const;
    void display() const;
    void displayEvidence() const override;
};

#endif
