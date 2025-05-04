#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* start = NULL;
Node* avail = NULL;

void initAvail(int n) {
    for(int i = 0; i < n; i++) {
        Node* newnode = new Node();
        newnode->next = avail;
        avail = newnode;
    }
}

void push() {
    if(avail == NULL) {
        cout << "Overflow" << endl;
        return;
    }
	int val;
    cout << "Enter val: ";
    cin >> val;
    Node* newnode = avail;
	avail = avail->next;
	newnode->data = val;
    newnode->next = start;
    start = newnode;
    top++;
}

void pop() {
    if(start == NULL) {
        cout << "Underflow" << endl;
        return;
    }
    Node* ptr = start;
    start = start->next;
    cout << "Deleted node: " << ptr->data << endl;
    ptr->next = avail;
    avail = ptr;
}

void display() {
    Node* ptr = start;
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
            push();
        } else if(ch == 2) {
            pop();
        } else if (ch == 3) {
            display();
        }
    } while (ch != 4);
}
