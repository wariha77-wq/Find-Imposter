#include "Suspect.h"

Suspect::Suspect(int id,string n,string o,string b,string a){
    
    suspectId = id;
    name = n;
    occupation = o;
    background =b;
    alibi = a;
    interviewed = false;
}

string Suspect::getName(){
    return name;
}

int Suspect::getSusId(){
    return suspectId;
}
string Suspect::getOccupation(){
    return occupation;
}
string Suspect::getBackground(){
    return background;
}
string Suspect::getAlibi(){
    return alibi;
}

bool Suspect::isInterviewed(){
    return interviewed;
}

void Suspect::conductInterview(){
    interviewed = true;
    
    cout << "\nInterviewing: " << name << endl;
    cout << "Background: " << background << endl;
    cout << "Alibi: " << alibi << endl;

}

void Suspect::displaySuspect(){
    cout << "\nSuspect ID: " << suspectId;
    cout << "\nName: " << name;
    cout << "\nOccupation: " << occupation << endl;
}


