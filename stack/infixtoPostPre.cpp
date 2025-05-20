#include <iostream>
using namespace std;

int precedence(char op) {
    if (op == '^') return 4;
    if (op == '%') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%');
}

string infixToPostfix(string infix) {
    char s[100];
    int top = -1;
    string postfix;
    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            s[++top] = c;
        } else if (c == ')') {
            while (top != -1 && s[top] != '(') {
                postfix += s[top--];
            }
            top--;
        } else if (isOperator(c)) {
            while (top != -1 && precedence(s[top]) >= precedence(c)) {
                postfix += s[top--];
            }
            s[++top] = c;
        }
    }
    while (top != -1) {
        postfix += s[top--];
    }
    return postfix;
}

string reverseString(string str) {
    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
    return str;
}

string infixToPrefix(string infix) {
    string reverse = reverseString(infix);
    char s[100];
    int top = -1;
    string prefix;
    for (char c : reverse) {
        if (isalnum(c)) {
            prefix += c;
        } else if (c == ')') {
            s[++top] = c;
        } else if (c == '(') {
            while (top != -1 && s[top] != ')') {
                prefix += s[top--];
            }
            top--;
        } else if (isOperator(c)) {
            while (top != -1 && precedence(s[top]) >= precedence(c)) {
                prefix += s[top--];
            }
            s[++top] = c;
        }
    }
    while (top != -1) {
        prefix += s[top--];
    }
    return reverseString(prefix);
}

int main() {
    string infix;
    cout << "Enter an infix expression (without space) : ";
    cin >> infix;
    string prefix = infixToPrefix(infix);
    string postfix = infixToPostfix(infix);
    cout << "Prefix expression: " << prefix << endl;
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
