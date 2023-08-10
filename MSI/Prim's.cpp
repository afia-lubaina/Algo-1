#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

int V, E;

vector<vector<pair<int, int>>> adj;

vector<int> primMST(int start)
{
    vector<int> key(V, INF);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});
    key[start] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;

        for (const auto &neighbor : adj[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!inMST[v] && weight < key[v])
            {
                parent[v] = u;
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }

    return parent;
}

int main()
{
    cin >> V >> E;
    
    adj.resize(V);

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    int start; // Starting vertex for MST
    cin >> start;

    vector<int> parent = primMST(start);

    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (int i = 0; i < V; i++)
    {
        if (parent[i] != -1)
        {
            cout << parent[i] << " - " << i << endl;
        }
    }

    return 0;
}
