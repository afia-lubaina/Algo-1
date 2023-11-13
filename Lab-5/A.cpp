#include <bits/stdc++.h>
using namespace std;


const int INF = 1e9; 

void floydWarshall(vector<vector<int>>& graph, int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (graph[i][k] != INF && graph[k][j] != INF)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

// ----------------------------N^3 , and N=100

int main() {
    int n, m; // n = number of nodes, m = number of edges
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, INF));

    for (int i = 0; i < n; ++i) {
        graph[i][i] = 0; // Distance from a node to itself is 0
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w; // Edge from u to v with weight w
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u]=w;
    }

    floydWarshall(graph, n);

    // Printing the shortest distances
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i==j || j<i) continue;
            if (graph[i][j] == INF)
                cout<<i<<" to "<<j<<":"<< " infinity"<<"\n";
            else
                {
                    cout<<i<<" to "<<j<<": "<<graph[i][j]<<"\n";
                }
        }

    }

    return 0;
}
