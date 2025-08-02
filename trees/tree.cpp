#include<iostream>
using namespace std;

struct node{
      int data;
      node* left;
      node* right;

      node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
      }

};

void preorder(node* root){
    if(root==nullptr) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

    
}

void inorder(node* root){
    if(root==nullptr) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    
}

void postorder(node* root){
     if(root==nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}

node* insert(node* root,int key){

    if(root==nullptr)   return new node(key);
    else if(key<root->data){
        root->left=insert(root->left,key);

    }
    else{
        root->right=insert(root->right,key);
    }
    return root;
}

int main(){
    node* root =nullptr;
    root=insert(root,10);
    insert(root,5);
    insert(root,15);
    insert(root,3);
    insert(root,8);
    insert(root,12);
    insert(root,18);
    cout<<"Preorder:";
    preorder(root);
    cout<<endl;
    cout<<"Inorder:";
    inorder(root);
    cout<<endl;
    cout<<"Postorder:";
    postorder(root);


   

}


