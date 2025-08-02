//apples and oranges
#include<iostream>
using namespace std;

int main(){
    
    int apples[]={-2,2,1};
    int m = sizeof(apples)/sizeof(apples[0]);
    int oranges[]={5,-6};
    int n = sizeof(oranges)/sizeof(oranges[0]);
    int s=7,t=11;//tree location range
    int a=5,b=15;//location of tress
    
     int x=0,y=0;
    for (int i=0; i<m; i++) {
        if(a+(apples[i])>=s && a+(apples[i])<=t){
            x++;
        }
    
    }
      for (int i=0; i<n; i++) {
        if(b+(oranges[i])>=s && b+(oranges[i])<=t){
            y++;
        }
    
    }
    cout<<x << "\n"<< y;
}