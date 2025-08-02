#include <iostream>
using namespace std;
#define max 100
class stack
{
private:
    char arr[max];
    int top;

public:
    stack()
    {
        top = -1;
    }
    // size function
    int size()
    {
        return top + 1;
    }

    // isfull func
    bool isFull()
    {
        return top == max - 1;
    }

    bool isempty()
    {

        return top == -1;
    }

    char peek()
    {
        if (isempty())
        {
            cout << "Stack is empty" << endl;
            return '\0';
        }
        return arr[top];
    }

    void push(char val)
    {
        if (isFull())
        {
            cout << "Stack is full" << endl;
            return;
        }
        arr[++top] = val;
    }

    char pop()
    {
        if (isempty())
        {
            cout << "Stack is empty" << endl;
            return '\0';
        }
        return arr[top--];
    }

    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
    }
};

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '^')
        return 3;
    else
        return -1;
}

bool isop(char c)
{

    return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9');
}

string infixtopostfix(string exp)
{
    stack operators;
    string postfix;
    for (char &c : exp)
    {
        if (isop(c))
            postfix += c;
        else if (c == '(')
            operators.push(c);
        else if (c == ')')
        {
            while (!operators.isempty() && operators.peek() != '(')
            {
                postfix += operators.pop();
            }
            operators.pop();
        }
        else
        {
            while (!operators.isempty() && precedence(operators.peek()) >= precedence(c))
            {
                postfix += operators.pop();
            }
            operators.push(c);
        }
    }
    while (!operators.isempty())    
    {
        postfix+=operators.pop();
         
    }
    return postfix;
    
}

int main()
{

    string str = "A+B-C*D/E";
    cout <<"Expression:" <<str << endl;
    string ans=infixtopostfix(str);
    cout<<"infixtopostfix:"<<ans<<endl;

    return 0;
}
