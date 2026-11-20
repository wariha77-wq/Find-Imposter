#ifndef SUSPECT_H
#define SUSPECT_H
#include "Character.h"

class Suspect : public Character {
private:
    string background;
    string alibi;
    bool interviewed;

public:
    Suspect(int id, string n, string o, int age, string b, string a);

    int getSusId() const;
    string getBackground() const;
    string getAlibi() const;
    bool isInterviewed() const;
    void conductInterview();
    void displaySuspect() const;
    void display() const override;
};

#endif
