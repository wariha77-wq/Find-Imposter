#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <string>
using namespace std;

class Location
{
private:
    int locationID;
    string name;
    string description;
    bool investigated;

public:
    Location(int id, string n, string d);

    int getLocationID();
    string getName();
    string getDescription();

    bool hasBeenInvestigated();

    void investigate();
    void displayLocation();
};

#endif