//changes by sudharshan

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    int marks;

    void display() const {
        cout << "Roll No: " << rollNo << ", Name: " << name << ", Marks: " << marks << endl;
    }
};

vector<Student> students;

// Add new student
void addStudent() {
    Student s;
    cout << "Enter roll number: ";
    cin >> s.rollNo;
    cin.ignore();

    cout << "Enter name: ";
    getline(cin, s.name);

    cout << "Enter marks: ";
    cin >> s.marks;
    cin.ignore();

    students.push_back(s);
    cout << "Student added successfully.\n";
}

// Display all students
void displayStudents() {
    cout << "\nAll Students:\n";
    for (const auto& s : students) {
        s.display();
    }
}

// Search student by roll number
void searchStudent() {
    int roll;
    cout << "Enter roll number to search: ";
    cin >> roll;
    cin.ignore();

    for (const auto& s : students) {
        if (s.rollNo == roll) {
            s.display();
            return;
        }
    }
    cout << "Student not found.\n";
}

// Update student marks
void updateMarks() {
    int roll;
    cout << "Enter roll number to update marks: ";
    cin >> roll;
    cin.ignore();

    for (auto& s : students) {
        if (s.rollNo == roll) {
            cout << "Enter new marks: ";
            cin >> s.marks;
            cin.ignore();
            cout << "Marks updated successfully.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

// Delete student by roll number
void deleteStudent() {
    int roll;
    cout << "Enter roll number to delete: ";
    cin >> roll;
    cin.ignore();

    auto it = remove_if(students.begin(), students.end(),
                        [roll](const Student& s) { return s.rollNo == roll; });
    if (it != students.end()) {
        students.erase(it, students.end());
        cout << "Student deleted successfully.\n";
    } else {
        cout << "Student not found.\n";
    }
}

// Shreyas's contribution: Display top 3 students by marks
void displayTop3StudentsByMarks() {
    if (students.empty()) {
        cout << "No students available.\n";
        return;
    }

    vector<Student> sortedStudents = students;
    sort(sortedStudents.begin(), sortedStudents.end(),
         [](const Student& a, const Student& b) { return a.marks > b.marks; });

    cout << "\nTop 3 Students by Marks:\n";
    for (size_t i = 0; i < min(sortedStudents.size(), size_t(3)); ++i) {
        sortedStudents[i].display();
    }
}

// Chinami's contribution: Search student by name
void searchStudentByName() {
    string searchName;
    cout << "Enter name to search: ";
    getline(cin, searchName);

    bool found = false;
    for (const auto& s : students) {
        if (s.name == searchName) {
            s.display();
            found = true;
        }
    }
    if (!found) {
        cout << "Student not found with the name \"" << searchName << "\".\n";
    }
}

// Suhas's contribution: Display summary - total students and average marks
void displayStudentSummary() {
    if (students.empty()) {
        cout << "No students available.\n";
        return;
    }

    int totalStudents = students.size();
    int sumMarks = 0;
    for (const auto& s : students) {
        sumMarks += s.marks;
    }
    double averageMarks = static_cast<double>(sumMarks) / totalStudents;

    cout << "\nStudent Summary:\n";
    cout << "Total Students: " << totalStudents << endl;
    cout << "Average Marks: " << averageMarks << endl;
}

// Sudharshan's contribution: Password authentication
bool authenticate() {
    string password;
    cout << "Enter password to access Student Management System: ";
    getline(cin, password);

    if (password == "admin123") {
        cout << "Access granted.\n";
        return true;
    } else {
        cout << "Access denied. Wrong password.\n";
        return false;
    }
}

void mainMenu() {
    int choice;
    while (true) {
        cout << "\nStudent Management System Menu:\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by Roll Number\n";
        cout << "4. Update Student Marks\n";
        cout << "5. Delete Student\n";
        cout << "6. Display Top 3 Students by Marks (Shreyas)\n";
        cout << "7. Search Student by Name (Chinami)\n";
        cout << "8. Display Student Summary (Suhas)\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateMarks(); break;
            case 5: deleteStudent(); break;
            case 6: displayTop3StudentsByMarks(); break;
            case 7: searchStudentByName(); break;
            case 8: displayStudentSummary(); break;
            case 9: cout << "Exiting...\n"; return;
            default: cout << "Invalid choice! Try again.\n"; break;
        }
    }
}

int main() {
    cout << "Welcome to Student Management System\n";
    if (authenticate()) {
        mainMenu();
    }
    return 0;
}
