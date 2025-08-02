//sequence eqn
#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 2, 1, 3, 4}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int a[n + 1]={0}; 

    
    for (int i = 0; i < n; i++) {
        a[arr[i]] = i + 1; 
    }

    for (int x=1; x<=n;x++) {
        
        cout << a[a[x]] << " "; 
    }
    cout << endl;
   
}