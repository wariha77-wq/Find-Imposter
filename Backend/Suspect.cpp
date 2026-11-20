#include "Suspect.h"

Suspect::Suspect(int id, string n, string o, int age, string b, string a)
    : Character(id, n, o, age) 
{
    background = b; alibi = a; interviewed = false;
}
int Suspect::getSusId() const {
	return id; 
}
string Suspect::getBackground() const {
	return background; 
}
string Suspect::getAlibi() const {
	return alibi; 
}
bool Suspect::isInterviewed() const {
	return interviewed; 
}
void Suspect::conductInterview() {
	interviewed = true; 
}
void Suspect::displaySuspect() const {
    cout << "\n" << occupation << " - Age " << age << endl;
    cout << name << endl;
    cout << background << endl;
    cout << "Alibi: " << alibi << endl;
}
void Suspect::display() const {
	displaySuspect(); 
}
