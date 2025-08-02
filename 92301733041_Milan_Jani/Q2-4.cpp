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
    void midnode(){
        node* temp1=head;
        node* temp2=head;
        while(temp2!=nullptr && temp2->next!=nullptr){
          
            temp1=temp1->next;
            temp2=temp2->next->next;
           
            }
            cout<<temp1->data;
            
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
   // l1.insertend(9);
    l1.display();
    l1.midnode();

    
   
}

