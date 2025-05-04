#include <iostream>
using namespace std;

const int PRIORITY_LEVELS = 10;
const int MAX = 100;

int pq[PRIORITY_LEVELS][MAX];     // Queues per priority
int front[PRIORITY_LEVELS];       // Fronts per priority
int rear[PRIORITY_LEVELS];        // Rears per priority

// Initialize front and rear for all priority levels
void init() {
    for (int i = 0; i < PRIORITY_LEVELS; i++) {
        front[i] = rear[i] = -1;
    }
}

// Insert into correct priority queue
void insert(int value, int priority) {
    if (priority < 0 || priority >= PRIORITY_LEVELS) {
        cout << "Invalid priority level!\n";
        return;
    }
    if (rear[priority] == MAX - 1) {
        cout << "Queue for priority " << priority << " is full!\n";
        return;
    }

    if (front[priority] == -1) front[priority] = 0;
    rear[priority]++;
    pq[priority][rear[priority]] = value;

    cout << "Inserted " << value << " at priority " << priority << endl;
}

// Delete from the highest-priority non-empty queue
void deleteHighestPriority() {
    for (int i = 0; i < PRIORITY_LEVELS; i++) {
        if (front[i] != -1 && front[i] <= rear[i]) {
            int value = pq[i][front[i]];
            front[i]++;
            if (front[i] > rear[i]) front[i] = rear[i] = -1;  // reset if empty
            cout << "Deleted " << value << " from priority " << i << endl;
            return;
        }
    }
    cout << "All queues are empty!\n";
}

// Display all queues
void display() {
    for (int i = 0; i < PRIORITY_LEVELS; i++) {
        if (front[i] != -1 && front[i] <= rear[i]) {
            cout << "Priority " << i << ": ";
            for (int j = front[i]; j <= rear[i]; j++) {
                cout << pq[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    init();
    insert(10, 2);
    insert(20, 0);
    insert(30, 1);
    insert(40, 2);
    insert(50, 1);
    cout << "\n--- Display ---\n";
    display();
    cout << "\n--- Deletions ---\n";
    deleteHighestPriority();
    deleteHighestPriority();
    cout << "\n--- Display After Deletions ---\n";
    display();
    return 0;
}
