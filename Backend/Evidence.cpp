#include "Evidence.h"

Evidence::Evidence(int id, string t, string d, string location) {
    EvidenceId = id;
    title = t;
    description = d;
    foundAt = location;
    discovered = false;
}

Evidence::~Evidence() {}

int Evidence::getEvidenceID() const {
    return EvidenceId;
}

string Evidence::getTitle() const {
    return title;
}

string Evidence::getDescription() const {
    return description;
}

string Evidence::getLocation() const {
    return foundAt;
}

bool Evidence::isDiscovered() const {
    return discovered;
}

void Evidence::discover() {
    discovered = true;
}

void Evidence::displayEvidence() const {
    if (discovered) {
        cout << "Evidence: " << title << endl;
        cout << "Description: " << description << endl;
        cout << "Found at: " << foundAt << endl;
    }
}


