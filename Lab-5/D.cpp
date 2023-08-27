#include <iostream>
#include <vector>

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

    int q; cin>>q; 
    vector<int>seq;
    for (size_t i = 0; i < q; i++)
    {
        int v;cin>>v;
        seq.push_back(v);
    }
    
    bool infi=0;
    int s=0;
    // Printing the shortest distances
    for (size_t i = 0; i < q-1; i++)
    {
        {
            int u=seq[i];
            int v=seq[i+1];
            if (graph[u][v] == INF)
                infi=true;
            else
                s+=graph[u][v];
        }

    }
    if(!infi)
    cout<<s<<"\n"; 
    return 0;
}
