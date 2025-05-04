//preorder - NLR
//for (int i = 0; i < n; ++i) {
//        if (adj[current][i] && !visited[i]) 
//            dfs(adj, visited, n, start/current)

#include <iostream>
#define MAX 100

using namespace std;

void dfs(int current, int n, int adj[MAX][MAX], bool visited[MAX]) {
    visited[current] = true;
    cout << current << " ";

    for (int i = 0; i < n; ++i) {
        if (adj[current][i] && !visited[i]) {
            dfs(i, n, adj, visited);
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

    cout << "DFS starting from node 0: ";
    dfs(0, n, adj, visited);

    return 0;
}
