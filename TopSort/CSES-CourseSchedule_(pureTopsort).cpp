#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define ff first
#define ss second
#define lp(n) for(int i=0; i<n; i++)
typedef vector<int> vi;
vector<vi> adj;
vector<int> vis, topo;
bool cycle;

void dfs(int src) {
    vis[src] = 1;
    for (int v : adj[src]) {
        if (vis[v] == 0) {
            dfs(v);
        } else if (vis[v] == 1) {
            cycle = true;
            return;
        }
    }
    vis[src] = 2;
    topo.push_back(src);
}

void topologicalSort(int V) {
    vis.assign(V + 1, 0);
    cycle = false;
    topo.clear();
    
    for (int i = 1; i <= V; i++) {
        if (vis[i] == 0) {
            dfs(i);
            if (cycle) {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
    }
    
    reverse(topo.begin(), topo.end());
    for (int v : topo) {
        cout << v << " ";
    }
    cout << endl;
}

int main() {
    int V, E;
    cin >> V >> E;

    adj.resize(V + 1);
    
    lp(E) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }

    topologicalSort(V);

    return 0;
}
