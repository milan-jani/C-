#include <iostream>
using namespace std;

class Node {
public:
    int coef;
    int exp;
    Node* next;
    Node(int co, int ex) {
        coef = co;
        exp = ex;
        next = nullptr;
    }
};

class PolyLL {
private:
    Node* head;
public:
    PolyLL() {
        head = nullptr;
    }

    void insert_end(int co, int ex) {
        Node* newnode = new Node(co, ex);
        if (head == nullptr) {
            head = newnode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    void display() {
        if (head == nullptr) {
            cout << "Empty list";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->coef << "x^" << temp->exp;
            if (temp->next != nullptr) cout << " + ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* getHead() {
        return head;
    }

    void addition(Node* temp1, Node* temp2) {
        PolyLL result;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->exp > temp2->exp) {
                result.insert_end(temp1->coef, temp1->exp);
                temp1 = temp1->next;
            }
            else if (temp1->exp < temp2->exp) {
                result.insert_end(temp2->coef, temp2->exp);
                temp2 = temp2->next;
            }
            else {
                result.insert_end(temp1->coef + temp2->coef, temp1->exp);
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        while (temp1 != nullptr) {
            result.insert_end(temp1->coef, temp1->exp);
            temp1 = temp1->next;
        }
        while (temp2 != nullptr) {
            result.insert_end(temp2->coef, temp2->exp);
            temp2 = temp2->next;
        }
        cout << "Addition Result: ";
        result.display();
    }

    void subtraction(Node* temp1, Node* temp2) {
        PolyLL result;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->exp > temp2->exp) {
                result.insert_end(temp1->coef, temp1->exp);
                temp1 = temp1->next;
            }
            else if (temp1->exp < temp2->exp) {
                result.insert_end(-temp2->coef, temp2->exp);
                temp2 = temp2->next;
            }
            else {
                result.insert_end(temp1->coef - temp2->coef, temp1->exp);
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        while (temp1 != nullptr) {
            result.insert_end(temp1->coef, temp1->exp);
            temp1 = temp1->next;
        }
        while (temp2 != nullptr) {
            result.insert_end(-temp2->coef, temp2->exp);
            temp2 = temp2->next;
        }
        cout << "Subtraction Result: ";
        result.display();
    }

   

    void add(Node* temp) {
        Node* current = head;
        while (current != nullptr) {
            insert_end(current->coef, current->exp);
            current = current->next;
        }
        current = temp;
        while (current != nullptr) {
            insert_end(current->coef, current->exp);
            current = current->next;
        }
    }
};


int main() {
    PolyLL list1, list2;
    list1.insert_end(8, 3);
    list1.insert_end(4, 1);
    list1.insert_end(5, 0);

    list2.insert_end(7, 2);
    list2.insert_end(3, 1);

    list1.display();
    list2.display();
    list1.addition(list1.getHead(), list2.getHead());
    list1.subtraction(list1.getHead(), list2.getHead());
    return 0;
}