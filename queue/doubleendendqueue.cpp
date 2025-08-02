#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class deque
{

    node *front;
    node *rear;

public:
    deque()
    {
        front = rear = nullptr;
    }

    bool isempty()
    {
        return front == nullptr;
    }

    void insertbegin(int val)
    {
        node *newnode = new node(val);
        if (isempty())
        {
            front = rear = newnode;
        }
        else
        {
            newnode->next = front;
            front = newnode;
        }
        cout << val << " is added to front" << endl;
    }
    void insertback(int val)
    {
        node *newnode = new node(val);
        if (isempty())
        {
            front = rear = newnode;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
        cout << val << " is added to last" << endl;
    }

    void deletebegin()
    {

        if (isempty())
        {
            cout << "deque is empty" << endl;
        }
        else
        {
            int val = front->data;
            node *temp = front;
            front = front->next;
            delete temp;
            if (front == nullptr)
                rear = nullptr;
            cout << val << " is deleted from front" << endl;
        }
    }

    void deletelast()
    {

        if (isempty())
        {
            cout << "deque is empty" << endl;
        }
        else
        {
            int val = rear->data;
            if (front == rear)
            {
                delete front;
                front = rear = nullptr;
            }
            else
            {
                node *temp = front;
                while (temp->next != rear)
                {
                    temp = temp->next;
                }
                delete rear;

                rear = temp;
                temp->next = nullptr;
            }
            cout << val << " is deleted from last" << endl;
        }
    }
    void getfront()
    {
        if (isempty())
        {
            cout << "deque is empty." << endl;
            return;
        }
        else
        {
            cout << "front elemnt is " << front->data << endl;
        }
    }
    void getrear()
    {
        if (isempty())
        {
            cout << "deque is empty." << endl;
            return;
        }
        else
        {
            cout << "rear elemnt is " << rear->data << endl;
        }
    }

    void display()
    {
        node *temp = front;
        cout << "Deque:";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    deque d;
    d.insertbegin(4);
    d.insertbegin(5);
    d.insertback(10);
    d.insertback(20);
    d.insertbegin(3);
    d.insertbegin(2);
    d.insertbegin(1);

    d.display();
    d.getfront();
    d.getrear();
}