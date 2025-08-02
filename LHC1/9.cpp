///migratory birds
#include<iostream>
using namespace std;

int main(){
    int arr[]={1,4,4,4,5,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int temp[6]={0};
    for (int i = 0; i < n; i++)
    {
        temp[arr[i]]++;
    }

     int a=temp[0];
    
    for(int i=0;i<6;i++){
        if(temp[i]>a ){
            a=i;
        }
        
    }
    cout<<a;

}