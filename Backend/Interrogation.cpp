#include "Interrogation.h"

Interrogation::Interrogation(Suspect* s) { suspect = s; }

void Interrogation::addQA(string q, string a, int clueId) {
    QA item;
    item.question = q; item.answer = a; item.contradictedByClue = clueId;
    list.push_back(item);
    asked.push_back(false);
}
int Interrogation::getQuestionCount() const { return (int)list.size(); }
string Interrogation::getQuestion(int n) const {
    if (n < 1 || n > (int)list.size()) return "";
    return list[n - 1].question;
}
string Interrogation::getAnswer(int n) const {
    if (n < 1 || n > (int)list.size()) return "";
    return list[n - 1].answer;
}
void Interrogation::displayQuestions() const {
    cout << "\nQuestions for " << suspect->getName() << ":" << endl;
    for (size_t i = 0; i < list.size(); i++)
        cout << "  " << i + 1 << ". " << list[i].question << endl;
}
string Interrogation::ask(int n) {
    if (n < 1 || n > (int)list.size()) {
        cout << "Invalid question." << endl;
        return "";
    }
    suspect->conductInterview();
    asked[n - 1] = true;
    cout << "\nYou: " << list[n - 1].question << endl;
    cout << suspect->getName() << ": " << list[n - 1].answer << endl;
    return list[n - 1].answer;
}
int Interrogation::checkContradictions(Case& c) {
    int found = 0;
    for (size_t i = 0; i < list.size(); i++) {
        int cid = list[i].contradictedByClue;
        if (!asked[i] || cid == 0) continue;
        Clue* clue = c.findClue(cid);
        if (clue && clue->isDiscovered()) {
            cout << "\nCONTRADICTION FOUND! " << suspect->getName()
                 << " said: \"" << list[i].answer << "\"" << endl;
            cout << "But Clue #" << cid << " (" << clue->getTitle() << ") shows: "
                 << clue->getDescription() << endl;
            found++;
        }
    }
    if (found == 0)
        cout << "\nNo contradictions found for " << suspect->getName() << " yet." << endl;
    return found;
}
