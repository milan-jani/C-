#include<iostream>
using namespace std;

void display(int arr[],int size){
    
    for(int i=0;i<size;i++){
        cout<<" "<< arr[i]<<" ";
    }
    cout<<endl;

}
int door(int arr[],int size,int a){
   
  // arr[0]=a;
   for(int i=a;i<size;i=i+a){
    if(arr[i]==0)  arr[i]=1;
    else arr[i]=0;
   }
   a++;
   //display(arr,size);
   if(a<size) door(arr,size,a);
   
}

int opendoor(int arr[],int size){
    int c=0;
    cout<<"open doors are: ";
    for(int i=1;i<size;i++){
       if(arr[i]==1){
        cout<<i<<" ";
        c++;
       } 
    }
    return c;
}



int main(){
    int n=100;
    int arr[n+1]={0};
    int size=sizeof(arr)/sizeof(arr[0]);
    //cout<<"    1  2  3  4  5  6  7  8  9  10"<<endl;
    door(arr,size,1);
    cout<<"result of doors: "<<endl;
    display(arr,size);
    cout<<endl<<"number of open doors: "<<opendoor(arr,size)<<endl;
    
}
