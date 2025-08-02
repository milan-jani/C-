#include<iostream>
using namespace std;
void f3(int x){
    x=x*2;
}
int f2(int x){
    x=x*2;
    f3(x);
    return x;
}
void f1(int *x){
    
    *x=*x+10;
    int c=f2(*x);
    cout<<c;
}


int main(){
    int x=5;
    f1(&x);
}