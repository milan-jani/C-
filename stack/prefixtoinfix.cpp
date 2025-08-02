#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

bool isoperand(char c) {
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'));
}

string prefixtoinfix(string expression) {
    stack<string> operands;
    
    // Read the prefix expression from right to left
    for (int i = expression.length() - 1; i >= 0; i--) {
        char c = expression[i];
        
        // If the character is an operand, push it onto the stack
        if (isoperand(c)) {
            operands.push(string(1, c)); // Convert char to string and push
        }
        // If the character is an operator
        else {
            // Pop two operands from the stack
            string op1 = operands.top(); operands.pop();
            string op2 = operands.top(); operands.pop();
            
            // Create a new string in the form of (operand1 operator operand2)
            string new_expr = "(" + op1 + " " + c + " " + op2 + ")";
            operands.push(new_expr); // Push the new expression back onto the stack
        }
    }
    
    // The final result will be the only element left in the stack
    return operands.top();
}

int main() {
    string expression = "-+A/BcD"; // Example prefix expression
    string result = prefixtoinfix(expression);
    cout << result << endl; // Output the infix expression
    return 0;
}