//final array state after k multiplication 
#include<iostream>
using namespace std;

//method for finding min from array and return index of that min
int findmin(long long arr[],long long n){
    long long min = arr[0];
    long long min_index = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] < min){
            min = arr[i];
            min_index = i;
            }
         }
            return min_index;

}



main(){
    //int arr[]={2,1,3,5,6};
   long long arr[]={100000,2000};
    long long k=2;
   long long mul=1000000;
   long long n=sizeof(arr)/sizeof(arr[0]);
   long long mini=0;
    while(k!=0){
         mini=findmin(arr,n);
         arr[mini]=arr[mini]*mul;
         k--;
      }
     
      for(int i=0;i<n;i++ ){
        cout<<arr[i]%1000000007<<" ";
      }
    //cout<< size(arr);
     //cout<<findmin(arr,n);
}