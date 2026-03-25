#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
  protected:
    string name;

  public:
// Constructor {set the name when creating the person}
    Person(string n) : name(n) {}
    virtual void displayInfo() {
      cout << "Name: " << name << endl;
    } 
    virtual ~Person() {}
};

#endif