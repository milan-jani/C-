#include<iostream>
using namespace std;

main(){
    int a[]={3,1,-2,-5,2,-4};

    int n=sizeof(a)/sizeof(a[0]);
    
    int flag;
    
    for (int i = 0; i < n; i++)
    {
        if(a[i]>0) flag=true;
        else flag=false;
        if(flag) {
            
        }
    }


    for(int i:arr) {
        cout<<i<<" ";
    } 
    
}