#include <iostream>
using namespace std;
int main()
{
    int a[]={17,28,30};
    int b[]={99,16,8};
    int n1=sizeof(a)/sizeof(a[0]);
    int n2=sizeof(b)/sizeof(b[0]);
   int alice=0,bob=0;
    for(int i=0; i<n1; i++)
    {
     if(a[i]>b[i]) alice++;
     if(a[i]<b[i]) bob++;
    }
    cout<<"Alice:"<<alice<<endl;
    cout<<"Bob:"<<bob<<endl;

}