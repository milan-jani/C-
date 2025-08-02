//infix to prefix
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 100
class stack{
    int top;
    char arr[MAX];
    public:
    stack(){
        top=-1;
    }
    void push(char c){
        if(top==MAX-1){
            cout<<"Stack Overflow";
            return;
        }
        else{
            arr[++top]=c;
        }
    }
    char pop(){
        if(top==-1){
            cout<<"Stack is empty";
            return 0;
        }else{
            return arr[top--];
        }
    }

    char peek(){
        if(top==-1){
            cout<<"Stack is empty";
            return 0;
        }
        else{
            return arr[top];
        }
    }
    bool isempty(){
        return(top<0);
    }
};

int precedence(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return 0;
    }
}

bool isoperand(char c){
    return((c>='A' && c<='Z')||(c>='a'&& c<='z') || (c>='0' && c<='9'));
}

string infixtopostfix(string expression){
    stack operators;
    string postfix;
    for(char& c:expression){
        if(isoperand(c)){
            postfix+=c;
        }
        else if(c=='('){
            operators.push(c);
        }
        else if(c==')'){
            while(operators.peek()!='(' && !operators.isempty()){
                postfix+=operators.pop();
            }
            operators.pop();
        }
        else{
            while(!operators.isempty() && precedence(operators.peek())>=precedence(c)){
                postfix+=operators.pop();
            }
            operators.push(c);
        }
    }
    while(!operators.isempty()){
        postfix+=operators.pop();
    }
    return postfix;
}
int main(){
    string expression="A+B-C*D/E";
    reverse(expression.begin(),expression.end());
    string result=infixtopostfix(expression);
    reverse(result.begin(),result.end());
    cout<<result;
}
