#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
// Homework lecture 11
// Shortest Path 
const int INF = 1000000000;

struct Edge {
    int u, v, w;
};

int main() {
    ifstream fin("dirty.txt");
    ofstream fout("dirty.out");

    if (!fin) {
        cout << "Cannot open dirty.txt";
        return 0;
    }

    int n, m, s, e;
    fin >> n >> m >> s >> e;

    vector<Edge> edges;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; i++)
        dist[i][i] = 0;

    for (int i = 0; i < m; i++) {
        Edge x;
        fin >> x.u >> x.v >> x.w;
        edges.push_back(x);

        if (x.w < dist[x.u][x.v])
            dist[x.u][x.v] = x.w;
    }

    //=========================
    // Bellman-Ford
    //=========================
    vector<int> d(n + 1, INF);
    vector<int> parent(n + 1, -1);

    d[s] = 0;

    for (int i = 1; i <= n - 1; i++) {
        bool updated = false;

        for (Edge edge : edges) {
            if (d[edge.u] != INF &&
                d[edge.u] + edge.w < d[edge.v]) {

                d[edge.v] = d[edge.u] + edge.w;
                parent[edge.v] = edge.u;
                updated = true;
            }
        }

        if (!updated) break;
    }

    if (d[e] == INF) {
        fout << "INF\n";
        fout << "No Path\n";
    }
    else {
        fout << d[e] << endl;

        vector<int> path;
        int cur = e;

        while (cur != -1) {
            path.push_back(cur);
            cur = parent[cur];
        }

        reverse(path.begin(), path.end());

        for (int x : path)
            fout << x << " ";
        fout << endl;
    }

    //=========================
    // Floyd-Warshall
    //=========================
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dist[i][k] != INF &&
                    dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF)
                fout << "INF ";
            else
                fout << dist[i][j] << " ";
        }
        fout << endl;
    }

    fin.close();
    fout.close();

    return 0;
}