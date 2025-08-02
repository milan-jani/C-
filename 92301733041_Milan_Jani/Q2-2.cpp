#include<iostream>
using namespace std;

struct list{
    list* next;
}

struct std{
    int cgpa;
    string name;
    std* ptr;
}

class student{
    std arr[10];
   int c;
    student(){
    c=0;

    }
     void addStudent(int cgpa, const string& name) {
       arr[c]={cgpa,name,nullptr};
       c++;

       
}
void sort(){
    for(int i=0;i<c;i++){
        std* newnode=arr[i];
        list* temp;
        if(temp==nullptr)
        temp->next=newnode;
        else{
            if(std[i]<temp-)
        }
    }
   
}


}