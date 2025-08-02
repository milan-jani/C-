#include<iostream>
using namespace std;

void fun(int arr[],int size){
    for(int i=0;i<size;i++){
        if(arr[i]+1!=arr[i+1]){
            cout<<arr[i]+1;
            return;
        }
        else{
            cout<<"-1";
            return;
        }
    }
}

int main(){
    int arr[]={1,2,4,5,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    fun(arr,size);

}