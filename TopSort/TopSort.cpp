//edge_check

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int t = 0;
const int M = 1e5;
int color[M], pre[M], d[M], f[M];
vector<vector<int>> adj;
vector<pair<int, int>> tree_edge;
vector<pair<int, int>> back_edge;
vector<pair<int, int>> forward_edge;
vector<pair<int, int>> cross_edge;
bool cycle = false;
#define debug(x) cerr << __LINE__ << " " << (#x) << ' ' << x << endl;
vector<int> topo;
void dfs(int u)
{

    color[u] = 1;
    t++;
    d[u] = t;

    for (auto c : adj[u])
    {

        if (color[c] == 0)
        {
            tree_edge.push_back({u, c});
            // debug(c);
            pre[c] = u;
            dfs(c);
        }
        // else if (color[c] == 1)
        // {
        //     // //
        //     // cycle = true;
        //     // return;
        //     ;
        // }
        else if (color[c] == 2 && d[u] < d[c])
        {
            forward_edge.push_back({u, c});
        }
        else if (color[c] == 2 && d[u] > d[c])
        {
            cross_edge.push_back({u, c});
        }
        else if (color[c] == 1 and d[c] < d[u])
        {
            back_edge.push_back({u, c});
        }
    }
    color[u] = 2;

    t++;
    f[u] = t;
    topo.push_back(u);
}

int main()
{

    int V, E;
    cin >> V >> E;
    adj.resize(V + 1);

    for (size_t i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (size_t i = 1; i <= V; i++)
    {
        if (!color[i])
        {
            // debug(i);
            dfs(i);
        }
    }

    // edge check

    // check tree_edge
    //  for (auto it: tree_edge)
    //  {
    //     cout<<it.ff<<" "<<it.ss<<"\n";
    //  }

    // //back_edge
    for (auto it: back_edge)
    {
       cout<<it.ff<<" "<<it.ss<<"\n";
    }
    // for (int i = 0; i < V; i++)
    //     cout << i << ' ' << d[i] << ' ' << f[i] << endl;
    // for (auto x : forward_edge)
    //     cout << x.first << ' ' << x.second << "\n";
    // cout << endl;

    // forward edge= not tree edge but visits a descendant which is visited
    // reverse(topo.begin(), topo.end());
    // for (auto x : topo)
    //     cout << x << ' ';
    // cout << "\n";
    // for (auto it : cross_edge)
    // {
    //     cout << it.ff << " " << it.ss << "\n";
    // }

    // cross edge
}
// 0 --> 5
// 1 --> 3 7
// 2 --> 4 3 8 9
// 3 --> 3
// 4 --> 0
// 5 --> 2 0
// 6 --> 0
// 7 --> 7 4 3
// 8 --> 8 9
// 9 --> 9
