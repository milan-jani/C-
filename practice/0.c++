#include<iostream>

using namespace std;
int main(){
  int n=10;
  int *ptr=&n;
  int **ptr1=&ptr;
  cout<<*ptr1<<endl;
  cout<<&ptr<<endl;
  cout<<*ptr1<<endl;
  cout<<**ptr1;
  cout<<"Addres of n: "<<&n<<endl;
  
}
