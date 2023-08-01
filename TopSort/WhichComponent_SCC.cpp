// CSES planets and kingdoms 

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int t = 0;
const int M = 2e5 + 10;
bool vis[M];
vector<vector<int>> adj;
vector<vector<int>> cmps;
vector<vector<int>> trans;
vector<int>topo;
vector<int>new_cmp;
int ans[M];

#define pb push_back
#define debug(x) cerr << (#x) << ' ' << x << endl;

void dfs(int i)
{

    vis[i] = 1;


    for (auto c : adj[i])
    {
        if (!vis[c])
        {
            dfs(c);
        }
    }

    topo.pb(i);
}

void dfs_cmp(int p, vector<int> &new_cmp)
{

    vis[p] = 1;
    new_cmp.pb(p);
    for (auto c : trans[p])
    {
        if (!vis[c])
        {
            dfs_cmp(c, new_cmp);
        }
    }
}


int main()
{

    int P, T;
    cin >> P >> T;
    adj.resize(P + 1);
    trans.resize(P + 1);

    for (size_t i = 0; i < T; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        trans[v].pb(u);
    }

    for (int i = 1; i <= P; i++)
    {

        if (!vis[i])
            dfs(i);
    }
    reverse(topo.begin(), topo.end());
  
    memset(vis, 0, sizeof(vis));
    
    int k=1;
    for (size_t i = 0; i < topo.size(); i++)
    {   
        if(!vis[topo[i]]){

            new_cmp.clear();
            dfs_cmp(topo[i],new_cmp);
            for(auto it:new_cmp )
                {
                    ans[it]=k;
                }
            k++;
        }
       
    }

    cout<<k-1<<"\n";

    for (size_t i = 1; i <= P; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    
    
}



