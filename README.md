# Student Course Management System 🎓
A robust C++ Console Application designed to manage student records and course enrollments, applying advanced Object-Oriented Programming (OOP) and Standard Template Library (STL) concepts.

## Project Overview
This project was developed as an individual assignment for the Digital Egyptians (Digilians) program. It provides a menu-driven interface to perform CRUD operations on student data with a focus on data integrity and persistence

## Key Features
**Add Student:** Register new students with a Unique ID validation.
**Remove Student:** Delete records safely using Student ID and STL find_if.
**Search:** Quick lookup for students by their ID.
**Display All:** View a formatted list of all registered students.
**Course Enrollment:** Add courses to a specific student's profile.
**Show Courses:** View all courses enrolled by a student.
**GPA Sorting:** Rank students from highest to lowest GPA using STL sort().
**Data Persistence** Automatically Saves/Loads data to students.txt.

## Data Constraints & Validation
**Unique ID:** Prevents duplicate entries for the same ID.
**GPA Guard:** Ensures GPA is strictly between 0.0 and 4.0.
**Duplicate Prevention:** Uses std::set to ensure a student cannot enroll in the same course twice.
**Input Handling:** Gracefully handles invalid menu choices and non-numeric inputs.

## Technical Concepts Applied
**OOP Architecture:** Inheritance: Student class inherits from Person base class.
   **Encapsulation:** Private data members accessed via public getters.
   **Polymorphism:** Method overriding for displayInfo().   
**STL Implementation:** Containers: std::vector (Storage) and std::set (Unique Courses).
   **Algorithms:** <algorithm> library (sort, find_if).
**File I/O:** std::fstream and std::stringstream for persistent data management.

## Project Structure
**main.cpp:** Main application logic and menu interface.
**Student.h & Person.h:** Class definitions and logic.
**Student_Management_UML.pdf:** Detailed class diagram.
**students.txt:** Database file (Auto-generated).

* [View UML Diagram](./Student_Management_UML.pdf)

## How to Run
1. Clone the repository.
2. Compile using: `g++ main.cpp -o student_app`.
3. Run the executable: `./student_app`.

---
**Developed by:** Semon (Digilians Trainee - Foundation of Software Project)