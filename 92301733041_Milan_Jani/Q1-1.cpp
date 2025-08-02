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

class singlyLL{
    private:
    node* head;

    public:
    singlyLL(){
        head=nullptr;
    }
  node* gethead(){
    return head;
  }
    void insertend(int data){
        node* newnode=new node(data);
        if(head==nullptr){
            head=newnode;
        }
        else{
            node* temp=head;
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }
    void removeduplicate(){
         node* temp = head;
        while(temp!=nullptr){
            node* nextNode = temp->next;
            while(nextNode!=nullptr && temp->data == nextNode->data){
                nextNode = nextNode->next;
                
            }
            temp->next = nextNode;
            temp = nextNode;
        }
    }

        void merge(node* list1,node*list2){
     singlyLL result;
     while (list1!=nullptr and list2!=nullptr)  
     {
        if(list1->data < list2->data){
            result.insertend(list1->data);
            list1=list1->next;
        }
        else{
            result.insertend(list2->data);
            list2=list2->next;
        }
     }
      while (list1!=nullptr)
    {
        result.insertend(list1->data);
        list1=list1->next;
        
    }
    while (list2!=nullptr)
    {
        result.insertend(list2->data);
        list2=list2->next;
    }
     result.display();
     result.removeduplicate();
     result.display();
   

    }
    void display(){
        if(head==nullptr){
            cout<<"The LinkedList does not Exist."<<endl;
            return;
        }
        node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    };



int main(){
    singlyLL l1;
    singlyLL l2;
    l1.insertend(1);
    l1.insertend(3);
    l1.insertend(5);
    l1.insertend(7);

    l2.insertend(2);
    l2.insertend(3);
    l2.insertend(6);
    l2.insertend(8);
    l1.display();
    l2.display();
    l1.merge(l1.gethead(),l2.gethead());
}

