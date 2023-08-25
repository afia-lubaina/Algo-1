#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9; // Infinity value for unreachable nodes

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
    }

    floydWarshall(graph, n);

    // Printing the shortest distances
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] == INF)
                cout << "INF ";
            else
                cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
