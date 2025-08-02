#include<iostream>
using namespace std;

class Queue {
    int front, rear, size;
    int* arr;

public:
    Queue(int s) {
        arr = new int[s];
        front = -1;
        rear = -1;
        size = s;
    }

    void enqueue(int val) {
        if ((rear + 1) % size == front) {
            cout << "Queue is full" << endl;
            return;
        }
        rear = (rear + 1) % size;
        arr[rear] = val;
        cout << "Enqueued element: " << val << endl;
        if (front == -1) {
            front = 0;
        }
    }

    bool isempty() {
        return (rear == -1 && front == -1);
    }

    void dequeue() {
        if (isempty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Dequeued the element: " << arr[front] << endl;
        if (front == rear) {
            front = -1; // Queue becomes empty
            rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void peek() {
        if (isempty()) {
            cout << "The queue is empty" << endl;
            return;
        }
        cout << "The front element is: " << arr[front] << endl;
    }

    void display() {
        if (isempty()) {
            cout << "Queue is empty" << endl;
        } else {
            int i = front;
            while (true) {
                cout << arr[i] << " ";
                if (i == rear) break; // Stop when we reach rear
                i = (i + 1) % size; // Move to the next index in circular manner
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q(5);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(7);
    q.enqueue(10);
    q.peek();
    q.dequeue();
    q.peek();
    q.dequeue();
    q.peek();
    q.enqueue(100);
    q.enqueue(200);
    q.display();
    return 0;
}