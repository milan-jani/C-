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

    void insert_beg(int data){
        node* temp=new node(data);
        temp->next=head;
        head=temp;

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

    int search(int data){
         if(head==nullptr){
            cout<<"The LinkedList does not Exist."<<endl;
            return;
        }
        node* temp=head;
        while(temp!=nullptr){
            if(data==temp->data){
                return 1;
                break;
            }
            temp=temp->next;
        }
        return -1;
    }

    
};

  
  int main(){
    linkedlist list;
    list.insert_end(10);
    list.insert_beg(15);
    list.insert_end(200);
    list.insert_end(500);
    list.display();
    cout<<"adding 90 at first"<<endl;
    list.insert_beg(90);
    list.display();
    
////////////////////searching//////////////////////////
    cout<<"enter element to be search:"<<endl;
    int element;
    cin>>element;
//     int r=list.search(element);
//    if(r==1)
//    cout<<"element found";
//    else   cout<<"element not found";
  if(list.search(element)==-1)   cout<<"Element not found";
  else  cout<<"Element found";
    return 0;

  }