#include "Character.h"

Character::Character(int i, string n, string o, int a) {
    id = i; name = n; occupation = o; age = a;
}
Character::~Character() {}
int Character::getId() const { return id; }
string Character::getName() const { return name; }
string Character::getOccupation() const { return occupation; }
int Character::getAge() const { return age; }
void Character::display() const {
    cout << "\n" << occupation << " - Age " << age << "\n" << name << endl;
}
