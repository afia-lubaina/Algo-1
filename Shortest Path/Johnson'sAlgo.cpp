#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct Edge {
    int u, v, w;
};

void bellmanFord(vector<Edge>& edges, vector<int>& dist, int src) {
    int V = dist.size();
    dist[src] = 0;

    for (int i = 0; i < V - 1; ++i) {
        for (const Edge& e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }
}

void dijkstra(vector<vector<int>>& graph, vector<int>& dist, int src) {
    int V = graph.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                pq.push({dist[v], v});
            }
        }
    }
}

void johnsonsAlgorithm(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<Edge> edges;

    for (int i = 0; i < V; ++i) {
        edges.push_back({V, i, 0});
    }

    for (int i = 0; i < V; ++i) {
        vector<int> dist(V + 1, INF);
        bellmanFord(edges, dist, V);

        for (int j = 0; j < V; ++j) {
            if (graph[i][j] != INF) {
                graph[i][j] = graph[i][j] + dist[i] - dist[j];
            }
        }
    }

    for (int i = 0; i < V; ++i) {
        vector<int> dist(V, INF);
        dijkstra(graph, dist, i);

        for (int j = 0; j < V; ++j) {
            if (dist[j] != INF) {
                graph[i][j] = dist[j] + dist[j] - dist[i];
            }
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph(V, vector<int>(V, INF));

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    johnsonsAlgorithm(graph);

    cout << "Shortest distances between all pairs of nodes:" << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (graph[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << graph[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
