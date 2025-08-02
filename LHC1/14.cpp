//sock merchant
#include<iostream>
using namespace std;
int main(){
    int a[]={10 ,20, 20, 10, 10, 30, 50, 10, 20};
    int n = sizeof(a)/sizeof(a[0]);
    int arr[100]={0};
    for (int i = 0; i < n; i++)
    {
        arr[a[i]]++;
    }
    int c = 0;
    for (int i = 0; i < 100; i++){
        if(arr[i] >1  ){
          c+=arr[i]/2;
        }
    }
    cout<<c;
    
}