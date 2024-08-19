#include<iostream>
using namespace std;
#include<conio.h>
#include<fstream>
 main(){
    int a[10],i,n,choice,flag=0;
    cout<<"enter the number of elements in the array"<<endl;
    cin>>n;
    cout<<"enter the elements of the array"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        }
        cout<<"enter the number to be searched"<<endl;
        cin>>choice;
        for(i=0;i<n;i++)
        {
            if(a[i]==choice)
            {
                flag=1;
                break;
                }
                }
                if(flag==1)
                cout<<"the number is present in the array"<<endl;
                else
                cout<<"the number is not present in the array"<<endl;
 


 }