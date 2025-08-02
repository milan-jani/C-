#include<iostream>
using namespace std;

main(){
    int a[]={3,1,-2,-5,2,-4};

    int n=sizeof(a)/sizeof(a[0]);
    int arr[n];
    int p=0,r=1;
    for (int i = 0; i < n; i++)
    {
        if(a[i]>0){
            arr[p]=a[i];
            p+=2;
        }
        else{
            arr[r]=a[i];
            r+=2;
        }
    }
    for(int i:arr) {
        cout<<i<<" ";
    } 
    
}