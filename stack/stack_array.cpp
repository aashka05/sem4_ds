#include <iostream>
using namespace std;

void push(int arr[], int &top, int max_) {
    if (top == max_) {
        cout << "OVERFLOW" << endl;
    } else {
        top++;
        int val;
        cout << "Enter value: ";
        cin >> val;
        //cout << top << " " << val << endl;
        arr[top] = val;
    }
}

void pop(int arr[], int &top, int max_) {
    if (top == -1) {
        cout << "UNDERFLOW" << endl;
    } else {
        //int val = arr[top];
        cout << arr[top] << " popped" << endl;
        top--;
    }
}

void display(int arr[], int top, int max_) {
    if (top == -1) {
        cout << "No elements." << endl;
    } else {
        cout << "Stack: ";
        for(int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

void peek(int arr[], int top, int max_) {
    if (top == -1) {
        cout << "No elements." << endl;
    } else {
        cout << "Top: " << top << endl;
        cout << "Top element: " << arr[top] << endl;
    }
}

int main() {
    int stack[7];
    int top = -1;
    int max_ = sizeof(stack)/sizeof(int) - 1;
    //cout << max_;
    cout << "1: Push" << endl;
    cout << "2: Pop" << endl;
    cout << "3: Display" << endl;
    cout << "4: Peek" << endl;
    cout << "5: Exit" << endl;
    int ch;
    do {
        cout << "Enter your choice: ";
        cin >> ch;
        if (ch == 5) {
            break;
        } else if (ch == 1) {
            top = push(stack, top, max_);
        } else if (ch == 2) {
            top = pop(stack, top, max_);
        } else if (ch == 3) {
            display(stack, top, max_);
        } else if (ch == 4) {
            peek(stack, top, max_);
        }
    } while (ch != 5);
    return 0;
}
