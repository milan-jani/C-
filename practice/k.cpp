 
#include <iostream>
using namespace std;
class Node
{
public:
    int power,coef;
    Node *next;
    Node(int coef,int power)
    {
        this->coef = coef;
        this->power = power;
        next = nullptr;
    }
};
class Linkedlist
{
private:
    Node *head;    
public:
    Linkedlist()
    {
        head = nullptr;
    }
    void insertAtEnd(int coef,int power)
    {
        Node *new_node = new Node(coef,power);
        if (head == nullptr)
        {
            head = new_node;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }
    void display()
    {
        if (head == nullptr)
        {
            cout << "the linkedlist does not exist";
        }
        Node *temp = head;

        while (temp != nullptr)
        {
            cout << temp->coef<<"x^"<<temp->power<<" + ";
            temp = temp->next;
        }
          cout<<endl;
    }
    void addPolynomial(Node *list1, Node *list2)
    {
        Linkedlist result;
        while (list1 != nullptr and list2 != nullptr)
        {
            if (list1->power==list2->power)
            {
            result.insertAtEnd((list1->coef+list2->coef),list1->power);
            list1=list1->next;
            list2=list2->next;
            }
            else if(list1->power>list2->power)
            {
                result.insertAtEnd(list1->coef,list1->power);
                list1= list1->next;
            }
            else if(list1->power<list2->power)
            {
                
                result.insertAtEnd(list2->coef,list2->power);
                list2 = list2->next;
            }    
        }
        while (list1 != nullptr)
        {
            result.insertAtEnd(list1->coef,list1->power);
            list1 = list1->next;
        }
        while (list2 != nullptr)
        {
            result.insertAtEnd(list2->coef,list2->power);
            list2 = list2->next;
        }
        result.display();
    }
void multiplyPolynomial(Node *list1, Node *list2)
    {
        Linkedlist result;
        while (list1 != nullptr and list2 != nullptr)
        {
            if (list1->power==list2->power)
            {
            result.insertAtEnd((list1->coef*list2->coef),list1->power);
            list1=list1->next;
            list2=list2->next;
            }
            else if(list1->power>list2->power)
            {
                result.insertAtEnd(list1->coef,list1->power);
                list1= list1->next;
            }
            else if(list1->power<list2->power)
            {      
                result.insertAtEnd(list2->coef,list2->power);
                list2 = list2->next;
            }     
        }
        while (list1 != nullptr)
        {
            result.insertAtEnd(list1->coef,list1->power);
            list1 = list1->next;
        }
        while (list2 != nullptr)
        {
            result.insertAtEnd(list2->coef,list2->power);
            list2 = list2->next;
        }
        result.display();
    }
void substractionPolynomial(Node *list1, Node *list2)
    {
        Linkedlist result;
        while (list1 != nullptr and list2 != nullptr)
        {
            if (list1->power==list2->power)
            {
            result.insertAtEnd((list1->coef-list2->coef),list1->power);
            list1=list1->next;
            list2=list2->next;
            }
            else if(list1->power>list2->power)
            {
                result.insertAtEnd(list1->coef,list1->power);
                list1= list1->next;
            }
            else if(list1->power<list2->power)
            {    
                result.insertAtEnd(list2->coef,list2->power);
                list2 = list2->next;
            }    
        }
        while (list1 != nullptr)
        {
            result.insertAtEnd(list1->coef,list1->power);
            list1 = list1->next;
        }
        while (list2 != nullptr)
        {
            result.insertAtEnd(list2->coef,list2->power);
            list2 = list2->next;
        }
        result.display();
    }

    Node* getHead(){
        return head;
    }
};
int main()
{
    Linkedlist list1, list2 ,result;
    list1.insertAtEnd(3,3);
    list1.insertAtEnd(2,2);
    list1.insertAtEnd(3,1);
    list1.insertAtEnd(2,0);
    
    list2.insertAtEnd(2,4);
    list2.insertAtEnd(1,3);
    list2.insertAtEnd(3,2);
    list2.insertAtEnd(1,1);
    list2.insertAtEnd(1,0);
    list1.display();
    list2.display();
    cout<<"Polynomial Addition"<<endl;
    result.addPolynomial(list1.getHead(),list2.getHead());
    cout<<"Polynomial subtraction"<<endl;
    result.substractionPolynomial(list1.getHead(),list2.getHead());
    cout<<"Polynomial numliplication"<<endl;
    result.multiplyPolynomial(list1.getHead(),list2.getHead());  
}