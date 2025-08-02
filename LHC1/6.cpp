//Ans_5(Plus Minus)
#include<iostream>
using namespace std;
int main()
{
    int arr[]={-4,3,-9,0,4,1};
    float p=0;
    float n=0;
    float z=0;
    float k=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<k;i++)
    {
        if(arr[i]<0)  n++;
        else if(arr[i]>0)  p++;
        else z++;
    }
    cout<<p<<" "<<n<<" "<<z<<endl;
    cout<<p/k<<" "<<n/k<<" "<<z/k;
}