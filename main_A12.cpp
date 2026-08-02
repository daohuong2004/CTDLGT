#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//=====================================================
// Exercise 1: Job Ordering (Topological Sort)
//=====================================================
void Exercise1() {
    ifstream fin("jobs.txt");
    ofstream fout("jobs.out");

    if (!fin) {
        cout << "Cannot open jobs.txt\n";
        return;
    }

    int n, m;
    fin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++)
        if (indegree[i] == 0)
            q.push(i);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        fout << u << " ";

        for (int v : adj[u]) {
            indegree[v]--;

            if (indegree[v] == 0)
                q.push(v);
        }
    }

    fin.close();
    fout.close();

    cout << "Done! Output written to jobs.out\n";
}

//=====================================================
// Exercise 2: Minimum Spanning Tree (Kruskal)
//=====================================================

struct Edge {
    int u, v, w;
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

vector<int> parent;

int Find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if (a != b)
        parent[a] = b;
}

void Exercise2() {
    ifstream fin("connection.txt");
    ofstream fout("connection.out");

    if (!fin) {
        cout << "Cannot open connection.txt\n";
        return;
    }

    int n, m;
    fin >> n >> m;

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++)
        fin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges.begin(), edges.end(), cmp);

    parent.resize(n + 1);

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int totalCost = 0;
    vector<Edge> mst;

    for (Edge e : edges) {
        if (Find(e.u) != Find(e.v)) {
            Union(e.u, e.v);
            totalCost += e.w;
            mst.push_back(e);
        }
    }

    fout << totalCost << endl;

    for (Edge e : mst)
        fout << e.u << " " << e.v << " " << e.w << endl;

    fin.close();
    fout.close();

    cout << "Done! Output written to connection.out\n";
}

//=====================================================
// Main
//=====================================================

int main() {

    int choice;

    cout << "=============================\n";
    cout << " Lecture 12 Assignments\n";
    cout << "=============================\n";
    cout << "1. Job Ordering (Topological Sort)\n";
    cout << "2. Minimum Cost Connection (Kruskal)\n";
    cout << "Choose exercise: ";

    cin >> choice;

    switch (choice) {
    case 1:
        Exercise1();
        break;

    case 2:
        Exercise2();
        break;

    default:
        cout << "Invalid choice!\n";
    }

    return 0;
}