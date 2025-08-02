#include <iostream>
#include <string>

using namespace std;

// Function that takes a string by const reference
void printName(const string& myName) {
    
    cout << "Name: " << myName << endl;
}

int main() {
    string myName = "Alice";
    printName(myName); // Pass by reference, no copy is made

    printName("Bob"); // Pass a string literal, no copy is made

    return 0;
}