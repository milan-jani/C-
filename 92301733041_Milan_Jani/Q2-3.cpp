#include<iostream>
#include<vector>
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
   
        void merge(node* list1,int arr){
     vector<int> r;
     int i=0;
     while (list1!=nullptr)  
     {
    
          r.push_back(list1->data);
        }
        for (int i = 0; i < 5; i++)
        {
            r.push_back(arr[i]);
        }
        
       
     }
     
    
    for(int x:r){
        cout<<x<<" ";

    }
    
    
   

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
    int arr[5]={1,2,3,4,5};
    l1.merge(l1.gethead(),arr);
    l1.display();
    
}

