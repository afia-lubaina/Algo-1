#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;  
#define ff first
#define ss second

vector<vector<pii>> graph;
int start;
vector<int> distances;

void dijkstra() {
    int n = graph.size();
    distances.assign(n, INT_MAX);
    distances[start] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> min_heap;  // Min-heap

    min_heap.push(make_pair(0, start));

    while (!min_heap.empty()) {
        int current_dis = min_heap.top().ff;
        int current_node = min_heap.top().ss;
        min_heap.pop();

        if (current_dis > distances[current_node]) {
            continue;
        }

        for (const auto& v : graph[current_node]) {
            int neighbor_node = v.ss;
            int weight = v.ff;
            int distance = current_dis + weight;
            if (distance < distances[neighbor_node]) {
                distances[neighbor_node] = distance;
                min_heap.push(make_pair(distance, neighbor_node));
            }
        }
    }
}

int main() {

    int n, m; // n is number of nodes, m is number of edges
    cin >> n >> m;
    graph.resize(n);

    for (size_t i = 0; i < m; i++) {
        int u, v, w; 
        cin >> u >> v >> w; 
        graph[u].push_back({w, v});
    }
    
    int start_node = 0;
    distances.resize(n); 
    dijkstra();

    cout << "Shortest distances from node " << start_node << ":" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "To node " << i << ": " << distances[i] << endl;
    }

    return 0;
}
