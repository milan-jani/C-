#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isop(char c) {
    return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9');
}

string postfixtoinfix(string exp) {
    stack<string> s;

    for (char &c : exp) {
        if (isop(c)) {
           
            s.push(string(1, c));
        } else {
            
            string op2 = s.top(); s.pop(); 
            string op1 = s.top(); s.pop();

           
            string new_expr = "(" + op1 + c + op2 + ")";
            s.push(new_expr); 
        }
    }

    return s.top();
}

int main() {
    string str = "ABCD*-E/+";
    cout << "Postfix Expression: " << str << endl;
    string ans = postfixtoinfix(str);
    cout << "Infix Expression: " << ans << endl;

    return 0;
}