#include<iostream>
using namespace std;

int main(){
    int arr[]={7,1,3,4,1,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int a=0;
    int a1[n+1];
    for (int i = 0; i < n; i++)
    {
        for(int j=i+1;j<n;j++){
            if (arr[i]==arr[j])
            {
              a1[a++]=abs(i-j); 
            }
            
        }
    }
    int min=a1[0];
    for(int i=0;i<n;i++){
        min=(min>a1[i])? a1[i]:min;
    }
    cout<<min;
    
    
}