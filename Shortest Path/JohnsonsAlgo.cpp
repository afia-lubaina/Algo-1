#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
typedef pair<int, int> pii;
#define ss second
#define ff first

struct Edge {
    int u, v, w;
};

vector<Edge> edges;
vector<vector<pair<int, int>>> graph;
vector<int> dist;

void dijkstra(int src, int n){

    dist.assign(n,INF);
    dist[src]=0; 

    priority_queue<pii,vector<pii>, greater<pii>> min_heap;

    min_heap.push({0,src}); 

    while(!min_heap.empty()){
        int u=min_heap.top().ss;
        min_heap.pop();

        for(auto it: graph[u]){

            int v=it.ss;
            int w=it.ff; 
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w; 
                min_heap.push({dist[v],v});
            }
        }
    }

}


vector<int> bellmanFord(int n, int src) {
    vector<int>h(n,INF);
    h[src] =0;
    int V = h.size();
    h[src] = 0;

    for (int i = 0; i < V - 1; ++i) {
        for (const Edge& e : edges) {
            if (h[e.u] != INF && h[e.u] + e.w < h[e.v]) {
                h[e.v] = h[e.u] + e.w;
            }
        }
    }
    return h;
}

int main() {
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);
    edges.resize(m + 1);
    dist.assign(n + 1, INF);

    for (size_t i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        graph[u].push_back({w, v});
    }

    for (size_t i = 1; i < n; i++) {
        Edge e;
        e.u=n;
        e.v=i; e.w=0;
        edges.push_back(e);
        graph[n].push_back({0, i});
    }

    vector<int>h=bellmanFord(n+1,n);

    for(auto &edge: edges){
        edge.w+=h[edge.u]-h[edge.v];
    }

    for(int u=0;u<n; u++){
        dijkstra(u,n);
        for(int v=0;v<n; v++){
            if(v==u)continue;
            if(dist[v]==INF){
                cout<<u<<" to "<<v<<": infinity"<<endl;
            }
            else cout<<u<<" to "<<v<<": "<<dist[v]<<endl;
        }
    }

    return 0;
}
