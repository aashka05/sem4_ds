#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int precedence(char op) {
    if (op == '^') return 4;
    if (op == '*' || op == '/') return 3;
    if (op == '+' || op == '-') return 2;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixToPostfix(string infixExp) {
    char s[100];
    int top = -1;
    string postfix = "";

    for (int i = 0; i < infixExp.length(); i++) {
        char c = infixExp[i];

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
        str[i] = str[n - 1 - i];
        str[n - 1 - i] = temp;
    }
    return str;
}

string infixToPrefix(string infixExp) {
    string rev = reverseString(infixExp);
    char s[100];
    int top = -1;
    string prefix = "";

    for (int i = 0; i < rev.length(); i++) {
        char c = rev[i];

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
    string infixExp;
    cout << "Enter infix expression: ";
    cin >> infixExp;

    string postfix = infixToPostfix(infixExp);
    string prefix = infixToPrefix(infixExp);

    cout << "Postfix expression: " << postfix << endl;
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}
