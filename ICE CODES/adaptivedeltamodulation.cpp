#include <iostream>

int main() {
    float a[] = {2.9, 3.3, 3.9, 4.8, 3.6, 2.4, 1.8, 0.9, 0.2, 1.4, 2.3}; 
    int n = sizeof(a) / sizeof(a[0]);
    int y[n]; 
    float step = 1; 
    float prev = 0.0; 

    for (int i = 0; i < n; i++) {
        float diff = a[i] - prev;
        if (diff > 0) {
            y[i] = 1;
            prev += step;
            step += 1; 
        } else {
            y[i] = 0;
            prev -= step;
            step -= 1; 
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << y[i] <<" ";
    }

    return 0;
}