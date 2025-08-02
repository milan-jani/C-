#include <iostream>
using namespace std;

class Queue
{
    int front, rear, size;
    int *arr;

    public:
    Queue(int s)
    {
        arr = new int[s];
        
        front =-1;
        rear = -1;
        size = s;
        
    }

    int size_queue(){
        if (isempty())  return 0;
        
        else   
        return (rear - front + 1);
        

        
    }

    bool isfull()
    {
        if (rear == size - 1)
            return true;
        else
            return false;
    }

    bool isempty()
    {
        if (front == -1 and front > rear)
            return true;
        else
            return false;
    }
    void enqueue(int val)
    {
        if (isfull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        else
        {
            arr[++rear] = val;
            if (front == -1)
                front++;
        }
    }
    void dequeue()
    {
        if (isempty())
        {
            cout << "queue is empty" << endl;
            return;
        }
        else
        {
            
            cout << arr[front++] << " is deleted" << endl;
        }
    }
    int peek()
    {
        if (isempty())
        {
            cout << "queue is empty" << endl;
            return -1;
        }
        else
        return arr[front];
    }

    void display(){
        if(isempty()){
            cout<<"Queue is empty"<<endl;
            }
            else{
                for(int i=front;i<=rear;i++){
                    cout<<arr[i]<<" ";
                    }
                    cout<<endl;
                    }


    }
};


int main(){
    Queue q(5);
   
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.display();
    q.dequeue();
    q.display();

}