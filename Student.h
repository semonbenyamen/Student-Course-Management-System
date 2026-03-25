#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <set>

class Student : public Person {
private:
    int id;
    double gpa;
    set<string> courses;

public: 
    Student(int i, string n, double g): Person(n), id(i), gpa(g) {}

 // Encapsulation { Get accessing private data }
    int getId() const { return id; }
    double getGpa() const { return gpa; }
    string getName() const { return name; }

 // Enrollment { Function to add a course }
    void enrollCourse(string courseName) {
        courses.insert(courseName);
    }

    void displayInfo() override {
        cout << "ID: " << id << " | Name: " << name << " | GPA: " << gpa << endl;
        cout << "Enrolled Courses: ";
        if (courses.empty()) cout << "None";
        for (const string& c : courses) cout << "[" << c << "] ";
        cout << endl << "_ _ _ _ _ _ _ _ _ _" << endl;
    }
};

#endif