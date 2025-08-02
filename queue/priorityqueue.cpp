#include <iostream>
using namespace std;

class Node {
public:
    int data;
    int priority;
    Node* next;

    Node(int val, int p) {
        data = val;
        priority = p;
        next = nullptr;
    }
};

class PriorityQueue {
    Node* front;

public:
    PriorityQueue() {
        front = nullptr;
    }

    bool isempty() {
        return front == nullptr;
    }

    void enqueue(int val, int p) {
        Node* newNode = new Node(val, p);
        if (isempty() || p < front->priority) {
            newNode->next = front;
            front = newNode;
        } else {
            Node* temp = front;
            while (temp->next != nullptr && temp->next->priority <= p) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        cout << val << " is added with priority: " << newNode->priority << endl;
    }

    void dequeue() {
        if (isempty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        int val = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        cout << val << " is dequeued from front" << endl;
    }

    void peek() {
        if (isempty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Front element is: " << front->data << " with priority: " << front->priority << endl;
    }

    void display() {
        Node* temp = front;
        cout << "Priority Queue: ";
        while (temp != nullptr) {
            cout << "(" << temp->data << ", " << temp->priority << ") ";
            temp = temp->next;
        }
        cout << endl;
    }

   
};

int main() {
    PriorityQueue pq;
    pq.enqueue(4, 2);
    pq.enqueue(5, 1);
    pq.enqueue(10, 3);
    pq.enqueue(20, 0);
    
    pq.display();
    pq.peek();
    pq.dequeue();
    pq.display();

    return 0;
}