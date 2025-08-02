#include<iostream>
using namespace std;

class node{
 public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=nullptr;
    }

    

};

class linkedlist{
  
   private:
      node* head;

  public:
    linkedlist(){
        head=nullptr;
    }

  
    


    void insert_end(int data){
        node* newnode=new node(data);
        node* temp =head;
        if(head==nullptr){
            head=newnode;
            return;
        }
        while (temp->next!=nullptr)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }



    void display(){
        if(head==nullptr){
            cout<<"The LinkedList does not Exist."<<endl;
            return;
        }
        node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }



  


void reorderList(linkedlist& newList) {
    node* curr = head;
    node* maxNode = head;
    node* temp = head;

    // Traverse the list to find the maximum elements and add them to the new list
    while (curr) {
        // Find the maximum element in the remaining list
        maxNode = curr;
        temp = curr;
        while (temp->next) {
            if (temp->next->data > maxNode->data) {
                maxNode = temp->next;
            }
            temp = temp->next;
        }

        // Add the maximum element to the new list
        newList.insert_end(maxNode->data);

        // Find the next maximum element that is smaller than the previous one
        node* nextMaxNode = curr;
        while (nextMaxNode && nextMaxNode->data >= maxNode->data) {
            nextMaxNode = nextMaxNode->next;
        }

        // If we found a smaller maximum element, add it to the new list
        if (nextMaxNode) {
            temp = nextMaxNode;
            node* nextMax = nextMaxNode;
            while (temp->next) {
                if (temp->next->data > nextMax->data && temp->next->data < maxNode->data) {
                    nextMax = temp->next;
                }
                temp = temp->next;
            }

            newList.insert_end(nextMax->data);
        }

        curr = curr->next;
    }
}
};

  
  int main(){
    linkedlist list;
    list.insert_end(1);
    list.insert_end(2);
    list.insert_end(3);
    list.insert_end(4);
    list.insert_end(5);
    list.display();

    linkedlist newList;
    list.reorderList(newList);

    cout << "Reordered LinkedList: " << endl;
    newList.display();

    return 0;
  }