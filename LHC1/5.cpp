//Mini-Max Sum
#include<iostream>
using namespace std;

int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);

    int  sum = 0, max =INT32_MIN, min=INT32_MAX;
  
  for(int i = 0; i <n; i++){
    sum += arr[i];
    if(arr[i] > max) max = arr[i];
    if(arr[i] < min) min = arr[i];
  }

  int minSum = sum - max;
  int maxSum = sum - min;
  
  cout << minSum << " " << maxSum << endl;
}
  


    
    

