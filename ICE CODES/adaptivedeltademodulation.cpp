
#include <iostream>

int main() {
    int y[] = {1,0,1,1,1,1,0,0,0,0,1,0,1,1,0,0,0};
    int n = sizeof(y) / sizeof(y[0]);
    int a[n] = {0}; 
    int step = 1; 
    int prev = 0; 

    for (int i = 0; i < n; i++) {
        if (y[i] == 1) {
            prev += step;
            step++;
        } else {
            prev -= step;
            step--;
        }
        
        a[i] = (prev > 0) ? 1 : 0; 
    }

    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }

    return 0;
}