#include <iostream>
using namespace std;

const int MAX = 10;

class Rod {
public:
    int disks[MAX];
    int top = -1;
    char name;
    Rod(char n) : name(n) {}
};

void moveDisk(Rod& from, Rod& to) {
    to.disks[++to.top] = from.disks[from.top--];
    cout << "Move from " << from.name << " to " << to.name << "\n";
}

void printState(const Rod& A, const Rod& B, const Rod& C) {
    const Rod* first;
    const Rod* second;
    const Rod* third;
    
    if (A.name == 'A') first = &A;
    else if (A.name == 'B') second = &A;
    else third = &A;
    
    if (B.name == 'A') first = &B;
    else if (B.name == 'B') second = &B;
    else third = &B;
    
    if (C.name == 'A') first = &C;
    else if (C.name == 'B') second = &C;
    else third = &C;
    
    const Rod* rods[] = { first, second, third };
    
    for (int i = 0; i < 3; ++i) {
        cout << rods[i]->name << ": ";
        for (int j = 0; j <= rods[i]->top; ++j) {
            cout << rods[i]->disks[j] << " ";
        }
        cout << "\n";
    }
    
    cout << "------------------------\n";
}

void towerOfHanoi(int n, Rod& source, Rod& aux, Rod& target) {
    if (n == 1) {
        moveDisk(source, target);
        printState(source, aux, target);
        return;
    }
    towerOfHanoi(n - 1, source, target, aux);
    moveDisk(source, target);
    printState(source, aux, target);
    towerOfHanoi(n - 1, aux, source, target);
}

int main() {
    int n;
    cout << "Enter number of disks (max " << MAX << "): ";
    cin >> n;

    if (n <= 0 || n > MAX) {
        cout << "Invalid number of disks!\n";
        return 1;
    }

    Rod A('A'), B('B'), C('C');

    for (int i = n; i >= 1; --i)
        A.disks[++A.top] = i;

    cout << "Initial State:\n";
    printState(A, B, C);

    towerOfHanoi(n, A, B, C);

    return 0;
}
