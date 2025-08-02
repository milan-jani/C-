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

void selectionsort(int a[],int size){
    for(int i=0;i<size;i++){
        int min_index=i;
        for(int j=i+1;j<size;j++){
            if(a[min_index]>a[j]){
                min_index=j;
            }
        }
        swap(a[i],a[min_index]);
    }

}





int main(){
    int a[10]={29, 72, 98, 13, 87, 66, 52, 51, 36};
    int size=sizeof(a)/sizeof(a[0]);
    printarray(a,size);
    selectionsort(a,size);
    cout<<"Sorted:";
    printarray(a,size);
}