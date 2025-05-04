//enqueue - if(r+1%max == f) then overflow, r = r+1 % max
//dequeue - if(f == r) then underflow, f = f+1 % r+1
//display - i = f while i != r, i = i+1 % max

#include <iostream>
using namespace std;

void enqueue(int arr[], int &f, int &r, int max_) {
    if ((r + 1) % max_ == f) {  // Check if the queue is full
        cout << "OVERFLOW" << endl;
        return;
    }
    
    if (f == -1) {  // First element to insert
        f = 0;
    }
    
    r = (r + 1) % max_;  // Circularly move the rear index
    int val;
    cout << "Enter value: ";
    cin >> val;
    arr[r] = val;
}

void dequeue(int arr[], int &f, int &r) {
    if (f == -1) {  // Check if the queue is empty
        cout << "UNDERFLOW" << endl;
        return;
    }
    
    cout << arr[f] << " dequeued" << endl;
    if (f == r) {  // Last element
        f = r = -1;  // Reset queue to empty
    } else {
        f = (f + 1) % (r + 1);  // Circularly move the front index
    }
}

void display(int arr[], int f, int r, int max_) {
    if (f == -1) {
        cout << "No elements." << endl;
    } else {
        cout << "Queue: ";
        int i = f;
        while (i != r) {
            cout << arr[i] << " ";
            i = (i + 1) % max_;  // Circularly move through the queue
        }
        cout << arr[r] << endl;  // Print the last element
    }
}

void peek(int arr[], int f, int r) {
    if (f == -1) {
        cout << "No elements." << endl;
    } else {
        cout << "Front element: " << arr[f] << endl;
    }
}

int main() {
    int queue[7];
    int max_ = sizeof(queue) / sizeof(int);  // Circular queue max size
    int f = -1, r = -1;

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
            display(queue, f, r, max_);
        } else if (ch == 4) {
            peek(queue, f, r);
        }
    } while (ch != 5);
    
    return 0;
}
