#ifndef EVIDENCE_H
#define EVIDENCE_H

#include<iostream>
#include<string>

using namespace std;

class Evidence{
private:
   int EvidenceId;
   string title;
   string description;
   string foundAt;
   bool discovered;  
public:
   Evidence(int id,string t,string d,string location);

   int getEvidenceID();
   string getTitle();
   string getDescription();
   string getLocation();

   bool isDiscovered();

   void discover();
   void displayEvidence();
};

#endif