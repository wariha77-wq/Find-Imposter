#ifndef EVIDENCE_H
#define EVIDENCE_H

#include <iostream>
#include <string>
using namespace std;

class Evidence {
protected:
    int EvidenceId;
    string title;
    string description;
    string foundAt;
    bool discovered;

public:
    Evidence(int id, string t, string d, string location);
    virtual ~Evidence();

    int getEvidenceID() const;
    string getTitle() const;
    string getDescription() const;
    string getLocation() const;
    bool isDiscovered() const;

    void discover();
    virtual void displayEvidence() const;
};

#endif
