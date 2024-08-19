#include<iostream>
using namespace std;

void display(int a[],int size ){
    cout<<"ELEMENTS ARE:";
    for (int i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

   
    
}

int search(int a[],int size,int element){
for(int i=0;i<size;i++){
    if(a[i]==element){
        return i;
        break;
    }
}
return -1;
}

int insert(int a[],int &n,int capacity,int p,int key){
    if(n>=capacity){
        cout<<"array is full"<<endl;
        return -1;
    }
    else{
        if(p<0 || p>n){
            cout<<"Invalid position "<<endl;
            return -1;
        }
        else{
            for(int i=n;i>=p;i--){
                a[i+1]=a[i];
            }
            a[p]=key;
            n++;
           // return 0;
        }
    }
    cout<<"Insertion Done of "<<key<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
return 0;
}

int deletion(int a[],int &size,int p){
    if(p<0 || p>=size){
        cout<<"Invalid Position";
        return -1;

    }
    else{
        for(int i=p;i<size-1;i++){
            a[i]=a[i+1];
        }
        size--;

    }
  cout<<"Deletion Done at index:"<<p<<endl;
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
return 0;

}
main(){
    int c=10;//capacity
    int n=5;//size of array
    int a[c]={1,2,3,4,5};

    display(a,n);

//////////////////searching a element  by value/////////////////////////////////////////


   int element=3;
   if(search(a,n,element)==-1){
      cout<<"element not found.";
   }
   else
   cout<<"element found on "<< search(a,n,element)<<" position."<<endl;


////////////////////////inseret a elemnt/key in array////////////////////////////////

   int p=2;
   int key=8;
  insert(a,n,c,p,key);
    
///////////////////////////////////////////Deletion///////////////////

int index=3;

deletion(a,n,index);

  
}
