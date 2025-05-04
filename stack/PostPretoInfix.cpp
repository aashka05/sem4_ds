#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Helper to check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Convert postfix to infix
string postfixToInfix(string postfix) {
    stack<string> s;
    for (char c : postfix) {
        if (isOperator(c)) {
            string op2 = s.top(); s.pop();
            string op1 = s.top(); s.pop();
            string temp = "(" + op1 + c + op2 + ")";
            s.push(temp);
        } else {
            s.push(string(1, c));
        }
    }
    return s.top();
}

// Convert prefix to infix
string prefixToInfix(string prefix) {
    stack<string> s;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isOperator(c)) {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            string res = "(" + op1 + c + op2 + ")";
            s.push(res);
        } else {
            s.push(string(1, c));
        }
    }
    return s.top();
}

int main() {
    string prefix, postfix;

    cout << "Enter prefix expression: ";
    cin >> prefix;
    cout << "Infix from prefix: " << prefixToInfix(prefix) << endl;

    cout << "Enter postfix expression: ";
    cin >> postfix;
    cout << "Infix from postfix: " << postfixToInfix(postfix) << endl;

    return 0;
}
