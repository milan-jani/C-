//The Hurdle Race
#include<iostream>
using namespace std;
int main(){
    int arr[]={1,6,3,5,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int h=4;
    int max=arr[0];
    for(int i=0;i<n;i++){
        max=(max<arr[i])? arr[i]:max;
    }
    if(max>h)  cout<<max-h;
    else cout<<0;
}