//angry professor

#include<iostream>
using namespace std;

int main(){
   // int arr[]={-1,-3,4,2};
    int arr[]={0,-1,2,1};
    //int req=3;
    int req=2;
    int c=0;
    int n=sizeof(arr)/sizeof(arr[0]);
    for (int  i = 0; i < n; i++)
    {
        if(arr[i]<=0) c++; 
    }
    if(c>=req) cout<<"no";
    else cout<<"yes";
    
}