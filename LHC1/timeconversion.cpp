#include<iostream>
using namespace std;
int main(){
    string time="07:25:45PM";
    int h,m,s;
     h=stoi(time.substr(0,2));
     m=stoi(time.substr(3,2));
     s=stoi(time.substr(6,2));

    int pm=0;
    if(time[8]=='P'&& time[9]=='M'){
        pm=1;
    }
    if(pm==1){
       
        if(h!=12){
            h=h+12;
        }
    }
   
    cout<<h<<":"<<m<<":"<<s;



}