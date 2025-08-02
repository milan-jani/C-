#include<iostream>
using namespace std;

int main(){
    int a[]={1,0,1,1,1,1,0,0,0,0,0,1,1,0,0,0};
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++){
 if(a[i]==1)  cout<<"up ";
    else cout<<"down ";
    }
    }
    
