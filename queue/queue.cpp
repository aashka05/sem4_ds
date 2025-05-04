#include <iostream>
using namespace std;

void enqueue(int arr[], int &f, int &r, int max_) {
    if (r == max_) {
        cout << "OVERFLOW" << endl;
        return;
    } 
    if (f == -1 || f > r) {
        f = 0;
        r = -1;
    }
        r++;
        int val;
        cout << "Enter value: ";
        cin >> val;
        //cout << top << " " << val << endl;
        arr[r] = val;
}

void dequeue(int arr[], int &f, int &r) {
    if (f > r) {
        f = -1;
        r = -1;
        cout << "UNDERFLOW" << endl;
    } else {
        cout << arr[f] << " popped" << endl;
        f++;
    }
}

void display(int arr[], int f, int r) {
    if (f > r) {
        cout << "No elements." << endl;
    } else {
        cout << "Queue: ";
        for(int i = f; i <= r; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

void peek(int arr[], int f, int r) {
    if (f > r) {
        cout << "No elements." << endl;
    } else {
        cout << "Front: " << f << endl;
        cout << "Front element: " << arr[f] << endl;
    }
}

int main() {
    int queue[7];
    int max_ = sizeof(queue)/sizeof(int) - 1;
    int f = -1, r = -1;
    //cout << max_;
    cout << "1: Enqueue" << endl;
    cout << "2: Dequeue" << endl;
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
            enqueue(queue, f, r, max_);
        } else if (ch == 2) {
            dequeue(queue, f, r);
        } else if (ch == 3) {
            display(queue, f, r);
        } else if (ch == 4) {
            peek(queue, f, r);
        }
    } while (ch != 5);
    return 0;
}
