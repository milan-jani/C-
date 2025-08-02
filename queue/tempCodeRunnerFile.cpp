#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularQueue {
    Node* front;
    Node* rear;

public:
    CircularQueue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (front == nullptr) {
            // Queue is empty
            front = newNode;
            rear = newNode;
            rear->next = front; // Point rear to front to make it circular
        } else {
            rear->next = newNode; // Link new node to rear
            rear = newNode;       // Update rear to new node
            rear->next = front;   // Make it circular
        }
        cout << "Enqueued element: " << val << endl;
    }

    bool isempty() {
        return front == nullptr;
    }

    void dequeue() {
        if (isempty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Dequeued the element: " << front->data << endl;
        if (front == rear) {
            // Only one element in the queue
            delete front;
            front = nullptr;
            rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next; // Move front to next node
            rear->next = front;  // Maintain the circular link
            delete temp;         // Free the old front node
        }
    }

    void peek() {
        if (isempty()) {
            cout << "The queue is empty" << endl;
            return;
        }
        cout << "The front element is: " << front->data << endl;
    }

    void display() {
        if (isempty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }

    
};

int main() {
    CircularQueue q;
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