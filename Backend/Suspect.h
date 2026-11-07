#ifndef SUSPECT_H
#define SUSPECT_H

#include <iostream>
#include <string>
using namespace std;

class Suspect{
private:
  int suspectId;
  string name;
  string occupation;
  string background;
  string alibi;
  bool interviewed;
public:
  Suspect(int id,string n,string o,string b,string a);
  int getSusId();
  string getName();
  string getOccupation();
  string getBackground();
  string getAlibi();
  bool isInterviewed();

  void conductInterview();
  void displaySuspect();

};


#endif