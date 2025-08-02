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

void bubblesort(int a[],int size){
    for(int i=0;i<size;i++){
        bool flag=false;
        for(int j=0;j<size-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                flag=true;
            }
        }
        if(flag==false){
            break;
        }
    }

}





int main(){
    int a[10]={29, 72, 98, 13, 87, 66, 52, 51, 36};
    int size=sizeof(a)/sizeof(a[0]);
    printarray(a,size);
    bubblesort(a,size);
    cout<<"Sorted:";
    printarray(a,size);
}