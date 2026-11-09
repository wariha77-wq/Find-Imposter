#include "Location.h"

Location::Location(int id, string n, string d)
{
    locationID = id;
    name = n;
    description = d;
    investigated = false;
}

int Location::getLocationID()
{
    return locationID;
}

string Location::getName()
{
    return name;
}

string Location::getDescription()
{
    return description;
}

bool Location::hasBeenInvestigated()
{
    return investigated;
}

void Location::investigate()
{
    investigated = true;

    cout << "\nYou are investigating: " << name << endl;
    cout << description << endl;
}

void Location::displayLocation()
{
    cout << "\nLocation ID: " << locationID;
    cout << "\nName: " << name;
    cout << "\nDescription: " << description << endl;
}