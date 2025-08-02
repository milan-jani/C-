#include <iostream>
#include <stack>

void sortStack(std::stack<int>& input) {
    std::stack<int> tempStack;

    while (!input.empty()) {
        // Pop the top element from the input stack
        int current = input.top();
        input.pop();

        // While temporary stack is not empty and the top of the temp stack
        // is greater than the current element, pop from temp stack and
        // push it to the input stack
        while (!tempStack.empty() && tempStack.top() > current) {
            input.push(tempStack.top());
            tempStack.pop();
        }

        // Push the current element onto the temporary stack
        tempStack.push(current);
    }

    // Transfer the sorted elements back to the input stack
    while (!tempStack.empty()) {
        input.push(tempStack.top());
        tempStack.pop();
    }
}

int main() {
    std::stack<int> myStack;

    // Pushing elements onto the stack
    myStack.push(4);
    myStack.push(3);
    myStack.push(1);
    
    myStack.push(2);
   

    std::cout << "Original stack (top to bottom): ";
    std::stack<int> tempStack = myStack; // Create a copy for display
    while (!tempStack.empty()) {
        std::cout << tempStack.top() << " ";
        tempStack.pop();
    }
    std::cout << std::endl;

    // Sort the stack
    sortStack(myStack);

    std::cout << "Sorted stack (top to bottom): ";
    while (!myStack.empty()) {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }
    std::cout << std::endl;

    return 0;
}