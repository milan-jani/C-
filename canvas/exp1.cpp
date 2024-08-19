#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    int salary;

public:
    int empId;
    string name;
    string gender;

    Employee(int id, string n, string g, int s) {
        empId = id;
        name = n;
        gender = g;
        salary = s;
    }

    void updateSalary(int newSalary) {
        salary = newSalary;
    }

    int getSalary() {
        return salary;
    }

    void displayDetails() {
        cout << "Employee ID: " << empId << endl;
        cout << "Name: " << name << endl;
        cout << "Gender: " << gender << endl;
        cout << "Salary: " << salary << endl;
        cout << endl;
    }
};

int main() {
    Employee employees[10] = {
        Employee(1, "A", "Male", 50000),
        Employee(2, "B", "Female", 60000),
        Employee(3, "C", "Male", 70000),
        Employee(4, "D", "Female", 80000),
        Employee(5, "E", "Male", 90000),
        Employee(6, "F", "Female", 100000),
        Employee(7, "G", "Male", 110000),
        Employee(8, "H", "Female", 120000),
        Employee(9, "I", "Male", 130000),
        Employee(10, "J", "Female", 140000)
    };

    cout << "Initial Employee Details:" << endl;
    for (int i = 0; i < 10; i++) {
        employees[i].displayDetails();
    }

    for (int i = 0; i < 10; i++) {
        employees[i].updateSalary(employees[i].getSalary() + 10000);
    }

    cout << "Updated Employee Details:" << endl;
    for (int i = 0; i < 10; i++) {
        employees[i].displayDetails();
    }

    return 0;
}