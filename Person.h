#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
  protected:
    string name;
// to make it available for inheritance
    int id;

   public:
// Constructor {set the name when creating the person}
    Person(int i, string n) : id(i), name(n) {}
    virtual void displayInfo() {
      cout << "ID: " << id << " | Name: " << name << endl;
    } 
    virtual ~Person() {}
};

#endif
