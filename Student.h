#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
// To stop duplicate of materials
#include <set>

class Student : public Person {
private:
    double gpa;
    set<string> courses;

public: 
    Student(int i, string n, double g): Person(i, n), gpa(g) {}

 // Encapsulation { Get accessing private data }
    int getId() const { return id; }
    double getGpa() const { return gpa; }
    string getName() const { return name; }

 // Enrollment { Function to add a course }
    bool enrollCourse(string courseName) {
        auto result = courses.insert(courseName);
// returns true if added for first time, and false if it already exists.        
        return result.second;
    }
    
// Display all information
    void displayInfo() override {
        cout << "ID: " << id << " | Name: " << name << " | GPA: " << gpa << endl;
        displayCoursesOnly();
    }
    
// Display Courses Only    
    void displayCoursesOnly() const {
        cout << "Enrolled Courses: ";
        if (courses.empty()) {
            cout << "None";
        } else {
            for (const string& c : courses) {
                cout << "[" << c << "] ";
            }
        }
        cout << endl << "_ _ _ _ _ _ _ _ _ _" << endl;
    }
    
 // feature: converted data to a single line for saving to the file
    string toFileString() const {
        string s = to_string(id) + "," + name + "," + to_string(gpa);
        
        for (const string& c : courses) {
            s += "," + c;
        }
        return s;
    }
};

#endif