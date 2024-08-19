#include<iostream>
using namespace std;

class employee{
    public:
    string name;
    char gender;
    double salary;
    int empid;
    
    void getinput(){
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your gender: ";
        cin >> gender;
        cout << "Enter your salary: ";
        cin >> salary;
        cout << "Enter your id: ";
        cin >> empid;
    }
    
    void getdata(){
       cout << "Name: " << name << endl;
        cout << "Gender: " << gender << endl;
        cout << "Salary: " << salary << endl;
        cout << "Empid: " << empid << endl;
    }

};

main(){
    employee e1;
    e1.getinput();
    e1.getdata();
  
}