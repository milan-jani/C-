//design a stundent management system with various functionalities
#include<iostream>
using namespace std;

//part 1 :add students detail using array ID,name,year of study,department

class course{
    public:
    int id;
    string name;
    int credits;
    course* next;
    course(int id,string name,int credits){
        this->id=id;
        this->name=name;
        this->credits=credits;
    }


};
class Student {
    public:
    int id;
    string name;
    int year;
    string department;


    Student(int id, string name, int year, string department) {
        this->id= id;
        this->name= name;
        this->year = year;
        this->department=department;
    }

     //function to add a new student 
    void addStudent(Student s[], int &n) {
        if (n < 10) {
            cout << "Enter student ID: ";
            cin >> s[n].id;
            cout << "Enter student name: ";
            cin >> s[n].name;
            cout << "Enter student year of study: ";
            cin >> s[n].year;
            cout << "Enter student department: ";
            cin >> s[n].department;
            n++;
            }
    }

    //function for searching student 
    void searchStudent(Student s[], int n) {
        int id;
        cout<<"enter the student id for searching: ";
        cin>>id;
        for (int i = 0; i < n; i++) {
            if(s[i].id==id){
                cout<<"student id: "<<s[i].id<<endl;
                cout<<"student name: "<<s[i].name<<endl;
                cout<<"Year:"<<s[i].year<<endl;
                cout<<"Department:"<<s[i].department<<endl;
                return;
            
            }
            else{
                cout<<"Student Id is INVALID";
                return;
            }
        }


    }

    
    void enrollCourse(Student s[], int n, Course c[], int &m) {
        int id;
        cout<<"Enter the student id to enroll course: ";
        cin>>id;


        for (int i = 0; i < n; i++) {
            if(s[i].id==id){
                cout<<"Enter the course name: ";
                cin>>c[m].name;
                cout<<"Enter the course code: ";
                cin>>c[m].code;
                m++;
                return;
            }

        }

    }
   //function to get report of all cousre that student has enrolled list of all.
   void report(Student s[], int n, Course c[], int m) {
    int id;
    cout<<"enter student id:"<<endl;
    cin>>id;
    for (int i = 0; i < n; i++) {
        if(s[i].id==id){
            
            for (int j = 0; j < m; j++) {
                if(s[i].id==c[j].id){
                    cout<<"Course Name: "<<c[j].name<<endl;
                    cout<<"Course Code: "<<c[j].code<<endl;



                }
            }



        }
    }
   }

    // function to delete the student from the system
    void deleteStudent(Student s[], int &n) {
        int id;
        cout << "Enter the student id to delete: ";
        cin>>id;
        for(int i=0;i<n;i++){
            if(s[i].id==id){
                for(int j=i;j<n-1;j++){
                    s[j]=s[j+1];

                }
                n--;
                cout<<"Student deleted successfully"<<endl;
            }
            else{
                cout<<"no course get enrolled!"<<endl;
                return;
            }
        }

    
    }
//display the details
   void display(){
    cout<<"ID: "<<id<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Year of Study: "<<year<<endl;
    cout<<"Department:"<<department<<endl;
   }

};

int main(){
    int n=2;
    // cout<<"Enter the number of students: ";
    // cin>>n;
    Student s(n);
    
    
    //call function for adding the students
    for(int i=0;i<n;i++){
        s[i].addStudent(s,i);
    }
    //display the all students detail
    for(int i=0;i<n;i++){
        s[i].display();
    }

   //cheak all function
   s[0].deleteStudent(s,n);
   s[0].display();

            


    



    

}
