#include <iostream>
#define MAX 100

using namespace std;

void bfs(int start, int n, int adj[MAX][MAX], bool visited[MAX]) {
    int q[MAX];
    int front = 0, rear = 0;

    q[rear++] = start;
    visited[start] = true;

    while (front < rear) {
        int current = q[front++];
        cout << current << " ";

        for (int i = 0; i < n; ++i) {
            if (adj[current][i] && !visited[i]) {
                q[rear++] = i;
                visited[i] = true;
            }
        }
    }
}

int main() {
    int n = 6;
    int adj[MAX][MAX] = {0};
    bool visited[MAX] = {false};

    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[1][4] = adj[4][1] = 1;
    adj[2][5] = adj[5][2] = 1;
    adj[4][5] = adj[5][4] = 1;

    cout << "BFS starting from node 0: ";
    bfs(0, n, adj, visited);

    return 0;
}
