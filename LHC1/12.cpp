//repeated string
#include <iostream>
using namespace std;

int main() {
    string str = "aba";
    int count = 0; 
    int repeat = 10;

    
    string app = "";
    for (int i = 0; i < repeat; i++) {
        app += str;
    }

  
    for (int i = 0; i < repeat; i++) {
        if (app[i] == 'a') {
            count++; 
        }
    }

    cout << count;
}
