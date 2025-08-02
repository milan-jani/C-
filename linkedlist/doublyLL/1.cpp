#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev;

    node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class doublyLL {
private:
    node* head;

public:
    doublyLL() {
        head = nullptr;
    }

    void insert_end(int data) {
        node* newnode = new node(data);
        if (head == nullptr) {
            head = newnode;
            return;
        }
        node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp; // Set the previous pointer of the new node
    }

    void insert(int val, int k) {
        node* newnode = new node(val);
        if (k == 1) {
            newnode->next = head;
            if (head != nullptr) {
                head->prev = newnode;
            }
            head = newnode;
            return;
        }

        node* temp = head;
        for (int i = 1; i < k - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position is out of bounds." << endl;
            delete newnode; 
            return;
        }

        newnode->next = temp->next;
        newnode->prev = temp;

        if (temp->next != nullptr) {
            temp->next->prev = newnode; 
        }

        temp->next = newnode; 
    }

    void display() {
        if (head == nullptr) {
            cout << "The LinkedList does not Exist." << endl;
            return;
        }
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int search(int data) {
        if (head == nullptr) {
            cout << "The LinkedList does not Exist." << endl;
            return 0;
        }
        node* temp = head;
        while (temp != nullptr) {
            if (data == temp->data) {
                return 1; 
            }
            temp = temp->next;
        }
        return -1; 
    }
};

int main() {
    doublyLL list;
    list.insert_end(10);
    list.insert_end(200);
    list.insert_end(500);
    list.display();

    // Searching
    cout << "Enter element to be searched: ";
    int element;
    cin >> element;
    if (list.search(element) == -1) {
        cout << "Element not found" << endl;
    } else {
        cout << "Element found" << endl;
    }

    // Inserting at specific positions
    cout << "Inserting 100 at position 2." << endl;
    list.insert(100, 2);
    list.display();

    cout << "Inserting 50 at position 1." << endl;
    list.insert(50, 1);
    list.display();

    return 0;
}