#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//=====================================================
// Exercise 1: Connected Components (Undirected Graph)
//=====================================================
void Exercise1() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    int components = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components++;
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }

    cout << "Connected Components = " << components << endl;
}

//=====================================================
// Exercise 2: Shortest Path (Directed Graph)
//=====================================================
void Exercise2() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> dist(n + 1, -1);
    queue<int> q;

    dist[X] = 0;
    q.push(X);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    cout << "Shortest Path Length = " << dist[Y] << endl;
}

//=====================================================
// Main
//=====================================================
int main() {
    int choice;

    cout << "1. Connected Components\n";
    cout << "2. Shortest Path\n";
    cout << "Choose exercise: ";
    cin >> choice;

    if (choice == 1)
        Exercise1();
    else if (choice == 2)
        Exercise2();
    else
        cout << "Invalid choice.";

    return 0;
}