//Utopian tree
#include<iostream>
using namespace std;

int tree(int n){
     int ans=1;
    if(n == 0) return 1;
    if(n==1) return 2;
   
    else{
        int c=0;
        while (n>0)
        {
            if(c%2==0) ans=2*ans;//spring
            else ans=ans+1;//summer
            n--;
            c++;
        }
        
        return ans;
        
    }
    }

int main(){
    cout<<tree(0)<<endl;
    cout<<tree(1)<<endl;
    cout<<tree(4)<<endl;
    cout<<tree(11);
    
    
}