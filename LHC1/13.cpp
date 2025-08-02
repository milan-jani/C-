//save the prisoner
#include<iostream>
using namespace std;

int main(){
    int p=7;
    int sweet=19;
    int start=2;

    sweet=sweet%p;
    for (int  i = start; i <=p; i++)
    {
        sweet--;
        if(sweet==0)
        cout<<i;
    }
    
}