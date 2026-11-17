#include "Dialogue.h"

Dialogue::Dialogue(int sid, string q, string a, bool isLie, int evidenceId){
    suspectId = sid;
    question = q;
    answer = a;
    lie = isLie;
    unlocksEvidenceId = evidenceId;
}

int Dialogue::getSuspectId(){
    return suspectId;
}

string Dialogue::getQuestion(){
    return question;
}

string Dialogue::getAnswer(){
    return answer;
}

bool Dialogue::isLie(){
    return lie;
}

int Dialogue::getUnlocksEvidenceId(){
    return unlocksEvidenceId;
}

void Dialogue::displayDialogue(){
    cout << "Q: " << question << endl;
    cout << "A: " << answer << endl;
}
