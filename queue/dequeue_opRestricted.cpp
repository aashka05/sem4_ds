//insertfront if r+1 % size == f then overflow, f = f-1+size % size
//insertrear if r+1 % size == f then overflow, r = r+1 % size
//delfront if f == -1 then underflow, f = f+1 % size

#include <iostream>
#define SIZE 10
using namespace std;

int deque[SIZE];
int front = -1, rear = -1;

void insertFront(int x) {
    if ((rear + 1) % SIZE == front) {
        cout << "Deque is full.\n";
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        front = (front - 1 + SIZE) % SIZE;
    }
    deque[front] = x;
}

void insertRear(int x) {
    if ((rear + 1) % SIZE == front) {
        cout << "Deque is full.\n";
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    deque[rear] = x;
}

void deleteFront() {
    if (front == -1) {
        cout << "Deque is empty.\n";
        return;
    }
    cout << "Deleted from front: " << deque[front] << endl;
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void display() {
    if (front == -1) {
        cout << "Deque is empty.\n";
        return;
    }
    cout << "Deque: ";
    int i = front;
    while (true) {
        cout << deque[i] << " ";
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    cout << endl;
}

int main() {
    int choice, x;
    while (true) {
        cout << "\n--- Output Restricted Deque ---\n";
        cout << "1. Insert at Front\n2. Insert at Rear\n3. Delete from Front\n4. Display\n5. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter value: "; cin >> x; insertFront(x); break;
            case 2: cout << "Enter value: "; cin >> x; insertRear(x); break;
            case 3: deleteFront(); break;
            case 4: display(); break;
            case 5: return 0;
            default: cout << "Invalid choice.\n";
        }
    }
}
