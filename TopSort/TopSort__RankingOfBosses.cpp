//Answer the boss -SPOJ RPLA

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back

vector<int> topo;
vector<vector<int>> under;
vector<vector<int>> boss;
const int M = 1001 + 5;
int vis[M];
//#define debug(x) cerr << (#x) << ' ' << x << endl;
#define debug(x) cerr << __LINE__ << " " << (#x) << ' ' << x << endl;

void dfs(int i)
{

    vis[i] = 1;
    for (auto c : under[i])
    {
        if (!vis[c])
        {
            dfs(c);
        }
    }

    topo.pb(i);
}

int main()
{

    int T;
    cin >> T;

    for (size_t t = 1; t <= T; t++)

    {
        int V, E;
        cin >> V >> E;
        boss.resize(V);
        under.resize(V);
        int maxrank[V];

        memset(maxrank, 0, sizeof(maxrank));

        for (size_t i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            under[v].pb(u);
            boss[u].pb(v);
        }

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                dfs(i);
        }

        reverse(topo.begin(), topo.end());

        for (size_t i = 0; i < topo.size(); i++)
        {
            //  debug(topo[i]);
            int m = topo[i];
            // debug(boss[m].size());
            if (boss[m].size() == 0)
                maxrank[m] = 1;
        }
        // cout<<"\n";

        // maxrank[topo[0]]=1;
        for (size_t i = 0; i < topo.size(); i++)
        {
            if (boss[topo[i]].size() != 0)
            {
                // debug(topo[i]);
                int mx = 1;
                for (auto b : boss[topo[i]])
                {
                    mx = max(mx, maxrank[b]);
                }

                maxrank[topo[i]] = mx + 1;
                //  debug(maxrank[topo[i]] );
            }
        }
        vector<pair<int,int>>v;
       
        for (size_t i = 0; i < V; i++)
        {
            v.pb({maxrank[i], i});
        }
        sort(v.begin(), v.end());

        cout << "Scenario #" << t << ":"
             << "\n";

        for (size_t i = 0; i < v.size(); i++)
        {
            cout<<v[i].ff<<" "<<v[i].ss<<"\n";
        }
        

        boss.clear();
        under.clear();
        memset(vis, 0, sizeof(vis));
        topo.clear();
    }
}
