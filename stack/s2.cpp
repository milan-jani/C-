#include<iostream>
using namespace std;

class stack{
    private:
     char*arr;
     int top;
     int capacity;
    public:
      stack(int size){
        top=-1;
        capacity=size;
        arr=new char[size];

      }
      //size function
     int size(){
       return top+1;
    }

    //isfull func
    bool isFull(){
        return top==capacity-1;
    }

    bool isempty(){
        return top==-1;
    }

    char peak(){
        return arr[top];
    }

    void push(char val){
        if(isFull()){
            cout<<"Stack is full"<<endl;
            return ;
            }
            arr[++top]=val;

    }
    
    char pop(){
        if(isempty()){
            cout<<"Stack is empty"<<endl;
            return '\0';
            }
           return arr[top--];

    }

    void display(){
        for(int i=top;i>=0;i--){
            cout<<arr[i]<<" ";

    }
    
    } 
};

int main(){
     
    string str="I like cofee";
    stack s(str.length());
   //  cout<<str.length();
    for(auto c:str){
        if(c!=' ')  s.push(c); 
        else{
            while(!s.isempty()){
                cout<<s.pop();
            }
            cout << " "; 
        }
    }
        //this loop bcz after adding coffee to stack temp it dosent find any space so manuallly we have to print the remaining or last word
        while(!s.isempty()){
            cout<<s.pop();
        }
   
    return 0;
}


