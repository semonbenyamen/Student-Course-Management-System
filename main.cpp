#include <iostream>
#include <vector>
#include <algorithm>
// file library
#include <fstream> 
#include <sstream>
// Letter check
#include <cctype>
#include "Student.h"

using namespace std;

// function sort students by GPA (highest to lowest)
bool compareByGPA(const Student& a, const Student& b) {
    return a.getGpa() > b.getGpa();
}

// Function to load data when the program starts
void loadFromFile(vector<Student>& StudentList) {
    ifstream inFile("students.txt");
    if(!inFile) return;
    
    string line;
    while (getline(inFile, line)) {
        if (line.empty()) continue;
        
        stringstream ss(line);
        string idStr, name, gpaStr, courseName;
        
        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, gpaStr, ',');
        
        if (!idStr.empty() && !name.empty() &&  !gpaStr.empty()) {
        // change texts to numbers and return student
            Student s(stoi(idStr), name, stod(gpaStr));
        // Read any courses on the line    
            while (getline(ss, courseName, ',')) {
                if (!courseName.empty()) s.enrollCourse(courseName);
            }
            StudentList.push_back(s);
        }
    }
    inFile.close();
}


// Function to save data in a text file
void saveToFile(const vector<Student>& StudentList) {
    ofstream outFile("students.txt");
    for (const auto& s : StudentList) {
// Use function i added in Student.h
        outFile << s.toFileString() << endl;
    }
    outFile.close();
}

int main() {
 // container STL    
    vector<Student> studentList;
 // Load saved data before   
    loadFromFile(studentList);
    
    int choice;

    do {
        cout << "\n--- Student Management System ---" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Remove Student" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Display All Students" << endl;
        cout << "5. Enroll Student in Course" << endl;
        cout << "6. Show Student Courses" << endl;
        cout << "7. Sort Students by GPA" << endl;
        cout << "8. Exit" << endl;
        cout << "----------------------------------" << endl;
        cout << "Enter your choice: ";
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number (1-8) " << endl;
            continue;
        }
        
    // Add Student    
        if (choice == 1) {
            int id;
            string name;
            double gpa;

            cout << "Enter Student ID: ";
            while (!(cin >> id)) {
                cout << "Invalid ID! Please enter a numeric ID";
                cin.clear();
                cin.ignore(1000, '\n');
            }
        // Constraint: Unique ID check    
            bool idExists = false;
            for (const auto& s : studentList) {
                if (s.getId() == id) {
                    idExists = true;
                    break;
                }
            }
            if (idExists) {
                cout << "Error : ID already exists" << endl;
            // back to the beginning of menu and doesn't add the student
                continue;
            }
        // Name must be letters only
            cin.ignore(1000, '\n');
            while (true) {
                cout << "Enter Name: ";
                getline(cin, name);

                bool isAllAlpha = true;
                for (char c : name) {
                    if (!isalpha(c) && !isspace(c)) {
                        isAllAlpha = false;
                        break;
                    }
                }
                if (!name.empty() && isAllAlpha) break;
                cout << "Invalid Name! Please use letters only" << endl;
            }
            
            
        // condition for GPA must be numeric between 0-4
            while (true) {
                cout << "Enter GPA (0.0 - 4.0): "; 
                if (cin >> gpa && gpa >= 0 && gpa <= 4) {
                    break;
                } else {
                    cout << "Invalid GPA must be 0.0-4.0" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                }    
            }
            studentList.push_back(Student(id, name, gpa));
            cout << "Student added successfully " << endl;
            
    // Remove Student        
        } else if(choice == 2) {
            int deleteId;
            cout << "Enter Student ID to remove: ";
            cin >> deleteId;
            
            auto it = find_if(studentList.begin(), studentList.end(), [&](const Student& s) {
                return s.getId() == deleteId;
            });
            if (it != studentList.end()) {
                studentList.erase(it);
                cout << "Student removed successfully" << endl;
            } else cout << "Student not found" << endl;
            
    // Search Student        
        } else if (choice == 3) {
            int SearchId;
            cout << "Enter ID to search: ";
            cin >> SearchId;
            
            bool found = false;
            for (auto& s : studentList) {
                if (s.getId() == SearchId) {
                    s.displayInfo();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Student not found " << endl;
            
    // Display All            
        } else if (choice == 4) {
            cout << "\n--- List of All Student ---" << endl;
            if (studentList.empty()) cout << "No Student found " << endl;
            for (auto& s : studentList) s.displayInfo();
            
    // Enroll Student in Course    
        } else if (choice == 5) {
            int id;
            cout << "Enter Stutend ID: ";
            cin >> id;
        
            bool found = false;
            // We pass by the students
            for (auto& s : studentList) {
                if (s.getId() == id) {
                    string courseName;
                    cout << "Enter Course Name: ";
                    cin.ignore(1000, '\n');
                    
                    getline(cin, courseName);
                // Check if student already enrolled    
                    if (s.enrollCourse(courseName)) {
                        cout << "Course enrolled successfully" << endl;
                    } else {
                        cout << "Error: Student is already enrolled in this course" << endl;
                    }   
                    found = true;
                    break;
            } 
        } 
        if (!found) cout << "Stutend not found" << endl;

    // Show Student Courses    
        } else if (choice == 6) {
            int id;
            cout << "Enter Student ID: ";
            cin >> id;
            
            bool found = false;
            
            for (auto& s : studentList) {
                if (s.getId() == id ) {
                    cout << "\n--- Student Course Record ---" << endl;
                    cout << "ID: " << s.getId() << endl;
                    cout << "Name: " << s.getName() << endl;
           // Courses are displayed        
                    s.displayCoursesOnly();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Student not found" << endl;
            
    // Sort by GPA        
        } else if (choice == 7) {
            sort(studentList.begin(), studentList.end(), compareByGPA);
            cout << "Students sorted by GPA. Use option 4 to view" << endl;
        }
    } while (choice != 8);
   // Save data before close program    
    saveToFile(studentList);
    cout << "Data saved. Exiting program..." << endl;
    

    return 0;
}