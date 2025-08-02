#include<iostream>
using namespace std;


int count(int arr[],int n){
    int c = 0;
    int a=arr[0];
    
    for(int i=1;i<n;i++){
        if(arr[i]>a){
            a=arr[i];
        }
    }
    cout<<a<<endl;
    for(int i = 0; i < n; i++){
        if(arr[i] == a){
            c++;
        }
    }
    return c;



}


int main(){

    int arr[] = {3,1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
   
    cout<<"ans:"<< count(arr,n);
}