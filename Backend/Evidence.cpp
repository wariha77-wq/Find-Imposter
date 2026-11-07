#include "Evidence.h"


Evidence::Evidence(int id,string t,string d,string location){
    EvidenceId = id;
    title = t;
    description = d;
    foundAt = location;
    discovered = false;
}

int Evidence::getEvidenceID(){
    return EvidenceId;
}

string Evidence::getTitle(){
    return title;
}
string Evidence::getDescription(){
    return description;
}

string Evidence::getLocation(){
    return foundAt;
}

bool Evidence::isDiscovered(){
    return discovered;
}

void Evidence::discover(){
    discovered = true;
}
void Evidence::displayEvidence(){
    if (discovered){
        cout << "Evidence: " << title<<endl;
        cout << "Description: " << description<<endl;
        cout << "Found at: " << foundAt << endl;
    }
}



