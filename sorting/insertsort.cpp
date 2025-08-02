// 29 72 98 13 87 66 52 51 36
#include<iostream>
using namespace std;

void printarray(int a[],int size){
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    cout <<endl;
    return;
}

void insertsort(int a[],int size){
    for(int i=1;i<size;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0&& key<a[j]){
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;

    }
 
}





int main(){
    int a[10]={29, 72, 98, 13, 87, 66, 52, 51, 36};
    int size=sizeof(a)/sizeof(a[0]);
    printarray(a,size);
    insertsort(a,size);
    cout<<"Sorted:";
    printarray(a,size);
}