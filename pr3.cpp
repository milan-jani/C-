#include <iostream>
#include <string>

using namespace std;

// Course structure for linked list
struct Course {
    int courseID;
    string courseName;
    int credits;
    Course* next; // Pointer to the next course
};

// Student structure
struct Student {
    int studentID;
    string studentName;
    int yearOfStudy;
    string department;
    Course* courseList; // Pointer to the linked list of courses
};

// Class to manage the student management system
class StudentManagementSystem {
private:
    static const int MAX_STUDENTS = 100; // Maximum number of students
    Student students[MAX_STUDENTS]; // Array to store students
    int studentCount; // Current number of students

public:
    StudentManagementSystem() : studentCount(0) {}

    // Function to add a new student
    void addStudent(int id, const string& name, int year, const string& dept) {
        // Check if the student ID already exists
        for (int i = 0; i < studentCount; i++) {
            if (students[i].studentID == id) {
                cout << "Student ID already exists!" << endl;
                return;
            }
        }

        // If the student ID is available, add the new student
        if (studentCount < MAX_STUDENTS) {
            students[studentCount] = {id, name, year, dept, nullptr};
            studentCount++;
            cout << "Student added successfully!" << endl;
        } else {
            cout << "Student limit reached!" << endl;
        }
    }

    // Function to search for a student by ID
    void searchStudent(int id) {
        for (int i = 0; i < studentCount; i++) {
            if (students[i].studentID == id) {
                cout << "Student Found: ID: " << students[i].studentID
                     << ", Name: " << students[i].studentName
                     << ", Year: " << students[i].yearOfStudy
                     << ", Department: " << students[i].department << endl;
                return;
            }
        }
        cout << "Student with ID " << id << " not found." << endl;
    }

    // Function to enroll a student in a course
    void enrollCourse(int studentID, int courseID, const string& courseName, int credits) {
        for (int i = 0; i < studentCount; i++) {
            if (students[i].studentID == studentID) {
                // Create a new course node
                Course* newCourse = new Course{courseID, courseName, credits, nullptr};

                // Add the course to the student's course list
                if (students[i].courseList == nullptr) {
                    students[i].courseList = newCourse; // First course
                } else {
                    Course* temp = students[i].courseList;
                    while (temp->next != nullptr) {
                        temp = temp->next; // Traverse to the end
                    }
                    temp->next = newCourse; // Add new course at the end
                }
                cout << "Course enrolled successfully!" << endl;
                return;
            }
        }
        cout << "Student with ID " << studentID << " not found." << endl;
    }

    // Function to delete a student from the system
    void deleteStudent(int id) {
        for (int i = 0; i < studentCount; i++) {
            if (students[i].studentID == id) {
                // Clear the course list
                Course* current = students[i].courseList;
                while (current != nullptr) {
                    Course* temp = current;
                    current = current->next;
                    delete temp; // Free memory
                }

                // Shift students in the array
                for (int j = i; j < studentCount - 1; j++) {
                    students[j] = students[j + 1];
                }
                studentCount--;
                cout << "Student deleted successfully!" << endl;
                return;
            }
        }
        cout << "Student with ID " << id << " not found." << endl;
    }

    // Function to generate course enrollment report
    void generateReport(int studentID) {
        for (int i = 0; i < studentCount; i++) {
            if (students[i].studentID == studentID) {
                cout << "Courses enrolled by Student ID " << studentID << ":" << endl;
                Course* current = students[i].courseList;
                if (current == nullptr) {
                    cout << "No courses enrolled." << endl;
                } else {
                    while (current != nullptr) {
                        cout << "Course ID: " << current->courseID 
                             << ", Course Name: " << current->courseName 
                             << ", Credits: " << current->credits << endl;
                        current = current->next;
                    }
                }
                return;
            }
        }
        cout << "Student with ID " << studentID << " not found." << endl;
    }
};

int main() {
    StudentManagementSystem sms;
    int choice, id, year, courseID, credits;
    string name, department, courseName;

    do {
        cout << "\nStudent Management System Menu:" << endl;
        cout << "1. Add New Student" << endl;
        cout << "2. Search for Student by ID" << endl;
        cout << "3. Enroll Student in a Course" << endl;
        cout << "4. Delete Student" << endl;
        cout << "5. Generate Course Enrollment Report" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Student ID: ";
                cin >> id;
                cout << "Enter Student Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Year of Study: ";
                cin >> year;
                cout << "Enter Department: ";
                cin.ignore();
                getline(cin, department);
                sms.addStudent(id, name, year, department);
                break;
            case 2:
                cout << "Enter Student ID to search: ";
                cin >> id;
                sms.searchStudent(id);
                break;
            case 3:
                cout << "Enter Student ID to enroll in a course: ";
                cin >> id;
                cout << "Enter Course ID: ";
                cin >> courseID;
                cout << "Enter Course Name: ";
                cin.ignore();
                getline(cin, courseName);
                cout << "Enter Credits: ";
                cin >> credits;
                sms.enrollCourse(id, courseID, courseName, credits);
                break;
            case 4:
                cout << "Enter Student ID to delete: ";
                cin >> id;
                sms.deleteStudent(id);
                break;
            case 5:
                cout << "Enter Student ID to generate report: ";
                cin >> id;
                sms.generateReport(id);
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}