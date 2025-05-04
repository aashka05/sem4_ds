//insertrear - if r+1 % size == f then overflow, r = r+1 % size
//delfront - if f== -1 then underflow, if f==r then f=-1, f = f+1 % size
//delrear - if f==-1 then underflow, if f==r then f=-1, r = r-1+size % size
#include <iostream>
#define SIZE 10
using namespace std;

int deque[SIZE];
int front = -1, rear = -1;

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

void deleteRear() {
    if (front == -1) {
        cout << "Deque is empty.\n";
        return;
    }
    cout << "Deleted from rear: " << deque[rear] << endl;
    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + SIZE) % SIZE;
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
        cout << "\n--- Input Restricted Deque ---\n";
        cout << "1. Insert at Rear\n2. Delete from Front\n3. Delete from Rear\n4. Display\n5. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter value: "; cin >> x; insertRear(x); break;
            case 2: deleteFront(); break;
            case 3: deleteRear(); break;
            case 4: display(); break;
            case 5: return 0;
            default: cout << "Invalid choice.\n";
        }
    }
}
