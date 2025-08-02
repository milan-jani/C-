#include<iostream>
using namespace std;

class stack{
    private:
     int*arr;
     int top;
     int capacity;
    public:
      stack(int size){
        top=-1;
        capacity=size;
        arr=new int[size];

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

    int peak(){
         if(isempty()){
            cout<<"Stack is empty"<<endl;
            return 0;
            }
        return arr[top];
    }

    void push(int val){
        if(isFull()){
            cout<<"Stack is full"<<endl;
            return ;
            }
            arr[++top]=val;

    }
    
    int pop(){
        if(isempty()){
            cout<<"Stack is empty"<<endl;
            return 0;
            }
           return arr[top--];

    }

    void display(){
        for(int i=top;i>=0;i--){
            cout<<arr[i]<<" ";

    }
    
    } 



};


main(){
    
     int arr[5]={1,2,3,4,5};
     int n=sizeof(arr)/sizeof(arr[0]);
     stack s(n);
     for (int i = 0; i < n; i++)    
     {
       s.push(arr[i]);
     }
     
    cout<<s.size()<<endl;
    cout<<s.isempty()<<endl;
    cout<<s.isFull()<<endl;
    cout<<s.peak()<<endl;
    s.pop();
    cout<<s.peak()<<endl;
    s.push(5);
    //array reverse
    s.display(); 
    cout<<endl;   
  

}



