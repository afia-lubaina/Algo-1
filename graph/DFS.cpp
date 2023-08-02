#include <bits/stdc++.h>
using namespace std;

typedef     long long       ll;

void dfs(int u, vector<vector<int>> &adj, vector<int> &vis, vector<int> &cmp)
{
    // cout << u << " ";
    cmp.push_back(u);
    vis[u] = 1;
    for(auto v: adj[u])
    {
        if(vis[v]) continue;
        dfs(v, adj, vis, cmp);
    }
}

int main()
{
    ll N, M;
    cin >> N >> M;
    // vector<int> adj[N+1];

    
    vector<vector<int>> adj(N+1);
    vector<int> vis(N+1);
    for(int i = 0; i < M; i++)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    vector<vector<int>> cmps;
    for(int i = 1; i <= N; i++)
    {
        if(vis[i]) continue;
        vector<int> new_cmp;
        dfs(i,adj,vis,new_cmp);
        cmps.push_back(new_cmp);
    }


    cout << cmps.size() << "\n";
    for(auto &cmp : cmps)
    {
        cout << cmp.size() << ": ";
        for(auto i: cmp)
        {
            cout << i << " ";
        }
        cout << "\n";
    }

    // queue<int> q;
    // vector<int> dis(N+1,INT_MAX), vis(N+1,0);

    // //BFS - BREADTH-FIRST-SEARCH
    // q.push(1);
    // vis[1] = 1;
    // dis[1] = 0;
    // while(!q.empty())
    // {
    //     int u = q.front(); q.pop();
    //     for(auto v: adj[u])
    //     {
    //         if(vis[v]) continue;
    //         vis[v] = 1;
    //         dis[v] = dis[u] + 1;
    //         q.push(v);
    //     }
    // }

    // for(int i = 1; i <= N; i++)
    // {
    //     cout << i << " " << dis[i] << "\n";
    // }
}
