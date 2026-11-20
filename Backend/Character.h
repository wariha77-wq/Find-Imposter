#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>
using namespace std;

class Character {
protected:
    int id;
    string name;
    string occupation;   // e.g. "The Owner"
    int age;
public:
    Character(int i, string n, string o, int a);
    virtual ~Character();
    int getId() const;
    string getName() const;
    string getOccupation() const;
    int getAge() const;
    virtual void display() const;
};
#endif
