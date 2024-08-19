//take two list which are sorted and merde in new linkedlist

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
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

    node* gethead(){
        return head;
    }

    void merge(node* list1,node*list2){
     singlyLL result;
     while (list1!=nullptr and list2!=nullptr)  
     {
        if(list1->data < list2->data){
            result.insert_end(list1->data);
            list1=list1->next;
        }
        else{
            result.insert_end(list2->data);
            list2=list2->next;
        }
     }
      while (list1!=nullptr)
    {
        result.insert_end(list1->data);
        list1=list1->next;
        
    }
    while (list2!=nullptr)
    {
        result.insert_end(list2->data);
        list2=list2->next;
    }
    result.display();

    }
   
    
    


};

int main(){
    singlyLL list1,list2;

    list1.insert_end(1);
    list1.insert_end(2);
    list1.insert_end(3);
    list1.insert_end(5);
    list1.insert_end(7);

    list2.insert_end(1);
    list2.insert_end(3);
    list2.insert_end(5);
    list2.insert_end(8);
    list2.insert_end(10);
    list2.insert_end(11);
    cout<<"List 1:"<<endl;
    list1.display();
    cout<<endl;
    cout<<"List 2:\n";
    list2.display();
     
    cout<<"\nMerging of both Linkedlist:"<<endl;
    list1.merge(list1.gethead(),list2.gethead());





}