#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge {
    int u, v, w;
};

vector<Edge> edges;
vector<int> dist;

bool bellmanFord(int source, int n) {
    dist.assign(n, INF);
    dist[source] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (const Edge& edge : edges) {
            if (dist[edge.u] != INF && dist[edge.v] > dist[edge.u] + edge.w) {
                dist[edge.v] = dist[edge.u] + edge.w;
            }
        }
    }

    for (const Edge& edge : edges) {
        if (dist[edge.u] != INF && dist[edge.v] > dist[edge.u] + edge.w) {
            return true; 
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;

        bool hasNegativeCycle = bellmanFord(x, n);
        if ((hasNegativeCycle || dist[y] == INF || dist[x]==INF) && dist[x]!=dist[y] ) {
            cout << "Impossible\n";
        } else if (dist[x] == -INF) {
            cout << "-Infinity\n";
        } else {
            cout << dist[y]-dist[x] << "\n";
        }
    }

    return 0;
}
