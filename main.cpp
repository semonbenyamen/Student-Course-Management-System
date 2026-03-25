#include <iostream>
#include <vector>
#include <algorithm>
#include "Student.h"

using namespace std;

// function sort students by GPA (from highest to lowest)
bool compareByGPA(const Student& a, const Student& b) {
    return a.getGpa() > b.getGpa();
}

int main() {
    vector<Student> studentList;
    int choice;

    do {
        cout << "--- Student Management System ---" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Sort Students by GPA" << endl;
        cout << "4. Enroll in Course (Search by ID)" << endl;
        cout << "5. Delete Student (by ID)" << endl;
        cout << "6. Exit" << endl;
        cout << "----------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name;
            double gpa;

            cout << "Enter ID: "; cin >> id;
            cout << "Enter Name: "; cin.ignore(); getline(cin, name);
            cout << "Enter GPA (0.0 - 4.0): "; cin >> gpa;

            studentList.push_back(Student(id, name, gpa));
            cout << "Student added successfully " << endl;

        } else if(choice == 2) {
            cout << "\n--- All Registered Student ---" << endl;

            if (studentList.empty()) cout << "No students found " << endl;
            for (auto& s : studentList) {
                s.displayInfo();
            }

        } else if (choice == 3) {
            sort(studentList.begin(), studentList.end(), compareByGPA);
            cout << "Student sorted by GPA (Highest to Lowest)" << endl;
            
    // search about specify element    
        } else if (choice == 4) {
            int searchId;
            cout << "Enter Stutend ID to eenroll: ";
            cin >> searchId;
        
            bool found = false;
            // We pass by the students
            for (auto& s : studentList) {
                if (s.getId() == searchId) {
                    string courseName;
                    cout << "Enter Course Name: ";
                    cin.ignore();
                    getline(cin, courseName);
                    s.enrollCourse(courseName);
                    
                    cout << "Course enrolled successfully" << endl;
                    found = true;
                    break;
            } 
        } 
        if (!found) cout << "Stutend not found" << endl;
        
        } else if (choice == 5) {
            int deleteId;
            cout << "Enter Student ID to delete: ";
            cin >> deleteId;
            
            bool found = false;
            
            for (auto it = studentList.begin(); it != studentList.end(); ++it) {
                if ( it -> getId() == deleteId ) {
                    studentList.erase(it);
                    cout << "\n Student with ID " << deleteId << " deleted successfully." << endl;
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Student not found" << endl;
        }
    } while (choice != 6);
    cout << "Exiting program..." << endl;
    

    return 0;
}