#include "CaseData.h"

CaseData::CaseData(){
    title = "The Missing Painting";
    story = "On Friday night, the painting 'Blue Horizon' was stolen from the city museum "
            "between 8:45 and 9:15 PM. The gallery glass was smashed to look like a break-in, "
            "but the evidence suggests someone with inside access did it.";
    culpritId = 3;

    createSuspects();
    createLocations();
    createEvidence();
    createDialogues();
    createContradictions();
}

void CaseData::createSuspects(){
    suspects.push_back(Suspect(1, "Ali Raza", "Night Guard",
        "Has worked at the museum for 5 years. Known to be struggling with money.",
        "I was doing my rounds near the Gallery at 9 PM."));

    suspects.push_back(Suspect(2, "Sara Khan", "Museum Curator",
        "Has worked at the museum for 10 years. Argued against the painting being sold.",
        "I left at 6 PM and was home all night. My neighbor saw me arrive."));

    suspects.push_back(Suspect(3, "Hamza Malik", "Art Restorer",
        "Restores paintings for the museum. Quiet, hardworking, and rarely socializes.",
        "I was working in the Staff Office until 10 PM."));
}

void CaseData::createLocations(){
    locations.push_back(Location(1, "Back Entrance", "A narrow door behind the museum. The ground outside is muddy."));
    locations.push_back(Location(2, "Security Room", "A small room full of monitors. One camera screen is blank."));
    locations.push_back(Location(3, "Gallery", "The main hall where the painting hung. Glass covers the floor."));
    locations.push_back(Location(4, "Staff Office", "A messy office with locked drawers and restoration tools."));
}

void CaseData::createEvidence(){
    // NOTE: the last word must match a Location name exactly.
    evidences.push_back(Evidence(1, "Muddy Footprints",
        "Size 9 shoe prints lead from the back door toward the staff area.", "Back Entrance"));

    evidences.push_back(Evidence(2, "Torn Note",
        "A note reading 'Meet me at 8:45. Bring the key.' The neat handwriting looks like restoration labels.", "Security Room"));

    evidences.push_back(Evidence(3, "Broken Glass",
        "The display case was smashed from the inside, so the thief was already in the gallery.", "Gallery"));

    evidences.push_back(Evidence(4, "Spare Key",
        "A duplicate gallery key on a keychain tagged 'H.M.'", "Staff Office"));

    evidences.push_back(Evidence(5, "Security Log",
        "Camera 2 was switched off at 8:50 PM. Staff card H.M. was used at the Back Entrance at 8:48 PM.", "Security Room"));
}

void CaseData::createDialogues(){
    // Dialogue(suspectId, question, answer, isLie, unlocksEvidenceId)

    // Ali
    dialogues.push_back(Dialogue(1, "Where were you at 9 PM?", "On my rounds near the Gallery.", true, 0));
    dialogues.push_back(Dialogue(1, "Why was Camera 2 off?", "I fell asleep in the Security Room. I did not touch it.", false, 5));
    dialogues.push_back(Dialogue(1, "What is your shoe size?", "Size 11.", false, 0));

    // Sara
    dialogues.push_back(Dialogue(2, "Where were you at 9 PM?", "At home. My neighbor saw me arrive.", false, 0));
    dialogues.push_back(Dialogue(2, "Who has gallery keys?", "Me, Ali, and the restorer, Hamza.", false, 4));

    // Hamza
    dialogues.push_back(Dialogue(3, "Where were you at 9 PM?", "In the Staff Office all night.", true, 0));
    dialogues.push_back(Dialogue(3, "Do you have a gallery key?", "Only for restoration work.", true, 0));
    dialogues.push_back(Dialogue(3, "Did you use the back door?", "No, never.", true, 0));
}

void CaseData::createContradictions(){
    // Contradiction(suspectId, claim, evidenceIdThatProvesItFalse)
    contradictions.push_back(Contradiction(3, "I was in the Staff Office all night.", 5));
    contradictions.push_back(Contradiction(3, "I never used the back door.", 5));
    contradictions.push_back(Contradiction(1, "I was doing my rounds at 9 PM.", 5));
}

string CaseData::getTitle(){
    return title;
}

string CaseData::getStory(){
    return story;
}

int CaseData::getCulpritId(){
    return culpritId;
}

bool CaseData::isCulprit(int suspectId){
    return suspectId == culpritId;
}

int CaseData::getSuspectCount(){
    return suspects.size();
}

Suspect& CaseData::getSuspect(int index){
    return suspects[index];
}

int CaseData::getLocationCount(){
    return locations.size();
}

Location& CaseData::getLocation(int index){
    return locations[index];
}

int CaseData::getEvidenceCount(){
    return evidences.size();
}

Evidence& CaseData::getEvidence(int index){
    return evidences[index];
}

int CaseData::getDialogueCount(){
    return dialogues.size();
}

Dialogue& CaseData::getDialogue(int index){
    return dialogues[index];
}

int CaseData::getContradictionCount(){
    return contradictions.size();
}

Contradiction& CaseData::getContradiction(int index){
    return contradictions[index];
}

int CaseData::investigateLocation(int index){
    int newClues = 0;
    locations[index].investigate();

    for (int i = 0; i < evidences.size(); i++){
        if (evidences[i].getLocation() == locations[index].getName()){
            if (!evidences[i].isDiscovered()){
                evidences[i].discover();
                evidences[i].displayEvidence();
                newClues++;
            }
        }
    }
    return newClues;
}

bool CaseData::discoverEvidenceById(int evidenceId){
    for (int i = 0; i < evidences.size(); i++){
        if (evidences[i].getEvidenceID() == evidenceId){
            if (!evidences[i].isDiscovered()){
                evidences[i].discover();
                return true;
            }
        }
    }
    return false;
}

void CaseData::displayCaseIntro(){
    cout << "CASE: " << title << endl;
    cout << story << endl;
}
