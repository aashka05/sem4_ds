//enqueue if !head && priority > head->priority then head = newnode; 
//        while ptr->next != NULL && ptr->next->priority >= priority
//dequeue if head == NULL then underflow, head = head->next

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    int priority;
    Node* next;
};

// Global head pointer
Node* head = nullptr;

// Insert a node based on priority
void enqueue(int data, int priority) {
    Node* newNode = new Node{data, priority, nullptr};

    if (!head || priority > head->priority) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next && temp->next->priority >= priority) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Remove highest priority element
void dequeue() {
    if (!head) {
        cout << "Queue is empty.\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

// Peek at the top element
int peek() {
    if (!head) {
        cout << "Queue is empty.\n";
        return -1;
    }
    return head->data;
}

// Display the queue
void display() {
    Node* temp = head;
    while (temp) {
        cout << "[" << temp->data << ", priority: " << temp->priority << "] -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    enqueue(10, 2);
    enqueue(30, 4);
    enqueue(20, 3);
    enqueue(40, 5);

    cout << "Priority Queue:\n";
    display();

    cout << "Top element: " << peek() << "\n";
    dequeue();
    display();

    return 0;
}
