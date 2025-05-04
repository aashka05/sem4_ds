//enqueue - rear->next = nn, rear = nn
//dequeue - f = f->next 
//display - ptr=f while ptr->data != NULL

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* avail = NULL;
Node* front = NULL;
Node* rear = NULL;

void initAvail(int n) {
    for(int i=0; i < n; i++) {
        Node* newnode = new Node();
        newnode->next = avail;
        avail = newnode;
    }
}

void enqueue() {
    if(avail == NULL) {
        cout << "Overflow" << endl;
        return;
    }
    int val;
    cout << "Enter value: ";
    cin >> val;
    Node* newnode = avail;
    avail = avail->next;
    newnode->data = val;
    if(front == NULL) {
        front = newnode;
        rear = newnode;
        front->next = NULL;
        rear->next = NULL;
        return;
    }
    rear->next = newnode;
    rear = newnode;
    newnode->next = NULL;
}

void dequeue() {
    if(front == NULL) {
        cout << "Underflow" << endl;
        return;
    }
    Node* ptr = front;
    front = front->next;
    cout << "deleted node: " << ptr->data << endl;
    ptr->next = avail;
    avail = ptr;
}

void display() {
    Node* ptr = front;
    while(ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main() {
    initAvail(5);
	int ch;
    do {
        cout << "Enter ch: ";
        cin >> ch;
        if(ch == 1) {
            enqueue();
        } else if(ch == 2) {
            dequeue();
        } else if (ch == 3) {
            display();
        }
    } while (ch != 4);
}
