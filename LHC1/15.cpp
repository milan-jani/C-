//bday choclate
#include<iostream>
using namespace std;
int main(){
    int a[]={1,2,1,3,2};
    int n = sizeof(a)/sizeof(a[0]);
    int c=0;
    int d=3;//sum
    int m=2;//length
    

    for(int i=0;i<n;i++){
        int sum=0;
     for(int j=i;j<i+m;j++){
        sum+=a[j];
     } 
     if(sum==d)  c++; 
    }
    cout<<c;
   
    
}