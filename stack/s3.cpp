//reverse all the word in an alphabetc sequence  ex:hello world  o/p : world hello
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

    char peek(){
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
            cout<<arr[i]<<"";

    }
    
    } 
};

int main(){
     
    string str="i like cofee";
    cout<<str;
    stack s(str.length());
    for(int i=0;i<str.length();i++){
        s.push(str[i]);
        }
      // s.display();
        cout<<endl;
        stack temp(str.length());
        while(!s.isempty()){
            char a=s.pop();
            if(a!=' ') { temp.push(a);}
            else{
                while(!temp.isempty()){
                    cout<<temp.pop();
                    
            }
            cout<<" ";
            }
        }
        
        //this loop bcz after adding coffee to stack it dosent find any space so manuallly we have to print the remaining or last word
        while(!temp.isempty()){
            cout<<temp.pop();
        }
            
   
    return 0;
}


