#include <bits/stdc++.h>
using namespace std;

int t = 1;
const int M = 2e5 + 10;
#define pb push_back
#define ff first
#define ss second

vector<vector<int>> adj;
vector<pair<int, int>> bridges;
int vis[M], d[M], low[M];

#define debug(x) cerr << (#x) << ' ' << x << endl;

void dfs(int v, int p) {
    int children = 0;
    vis[v] = 1;
    d[v] = low[v] = t++; // Increment t here

    debug(v);

    for (auto c : adj[v]) {
        if (!vis[c]) {
            children++;
            dfs(c, v);

            low[v] = min(low[c], low[v]);

            if (low[c] > d[v]) // Correct condition to find bridges
                bridges.pb({v, c});
        } else if (c != p) {
            // debug(c);
            low[v] = min(low[v], d[c]);
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    adj.resize(V + 1);

    for (size_t i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (size_t i = 1; i <= V; i++) {
        if (!vis[i]) {
            int p = -1;
            dfs(i, p);
        }
    }

    for (auto v : bridges)
        cout << v.ff << " " << v.ss << endl;

    cout << endl;
}
