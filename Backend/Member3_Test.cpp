#include "CaseData.h"
#include "ScoreSystem.h"

int main(){
    CaseData myCase;
    ScoreSystem score;

    myCase.displayCaseIntro();

    // 1. Show all suspects
    cout << "\n===== SUSPECTS =====";
    for (int i = 0; i < myCase.getSuspectCount(); i++){
        myCase.getSuspect(i).displaySuspect();
    }

    // 2. Interview Hamza
    cout << "\n===== INTERVIEW =====";
    myCase.getSuspect(2).conductInterview();
    score.addInterview();

    // 3. Investigate the Security Room (it is location number 1 in the list)
    cout << "\n===== INVESTIGATE =====";
    int found = myCase.investigateLocation(1);
    for (int i = 0; i < found; i++){
        score.addClueFound();
    }

    // 4. Show Hamza's dialogue
    cout << "\n===== HAMZA'S DIALOGUE =====\n";
    for (int i = 0; i < myCase.getDialogueCount(); i++){
        if (myCase.getDialogue(i).getSuspectId() == 3){
            myCase.getDialogue(i).displayDialogue();
        }
    }

    // 5. Make an accusation
    cout << "\n===== ACCUSATION =====\n";
    int accusedId = 3;
    bool correct = myCase.isCulprit(accusedId);
    score.accuse(correct);
    if (correct){
        cout << "Correct! Hamza is the culprit.\n";
    }
    else{
        cout << "Wrong accusation.\n";
    }

    score.displayScore();
    return 0;
}
