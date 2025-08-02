#include<iostream>
using namespace std;

int main(){
    float a[]={2.9,3.3,3.9,4.8,3.6,2.4,1.8,0.9,0.2,1.4,2.3};
   const int n=sizeof(a)/sizeof(a[0]);
      float step=0.00;
    for(int i=0;i<n;i++){
        if(step <= a[i]) {
           step++;
           cout<<"up"<<endl;
        }
        else{
            step--;
            cout<<"down"<<endl;

        }
        
    }
    
}