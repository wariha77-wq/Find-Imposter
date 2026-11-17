#include "Contradiction.h"

Contradiction::Contradiction(int sid, string s, int eid){
    suspectId = sid;
    statement = s;
    evidenceId = eid;
    caught = false;
}

int Contradiction::getSuspectId(){
    return suspectId;
}

string Contradiction::getStatement(){
    return statement;
}

int Contradiction::getEvidenceId(){
    return evidenceId;
}

bool Contradiction::isCaught(){
    return caught;
}

void Contradiction::catchContradiction(){
    caught = true;
}

void Contradiction::displayContradiction(){
    cout << "Claim: " << statement << endl;
}
