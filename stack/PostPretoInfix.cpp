#include <iostream>
using namespace std;

const int MAX = 100;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Postfix to Infix
string postfixToInfix(string postfix) {
    string stack[MAX];
    int top = -1;

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        if (isOperator(c)) {
            string op2 = stack[top--];  // pop
            string op1 = stack[top--];  // pop
            stack[++top] = "(" + op1 + c + op2 + ")";  // push
        } else {
            stack[++top] = string(1, c);  // push
        }
    }
    return stack[top];  // peek
}

// Prefix to Infix
string prefixToInfix(string prefix) {
    string stack[MAX];
    int top = -1;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isOperator(c)) {
            string op1 = stack[top--];  // pop
            string op2 = stack[top--];  // pop
            stack[++top] = "(" + op1 + c + op2 + ")";  // push
        } else {
            stack[++top] = string(1, c);  // push
        }
    }
    return stack[top];  // peek
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
