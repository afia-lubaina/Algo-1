#include <bits/stdc++.h>
using namespace std;

int t;
const int M = 2e5 + 10;
#define pb push_back
#define ff first
#define ss second

vector<vector<int>> adj;
int AP[M], vis[M], d[M], low[M];
vector<string> places;
unordered_map<string, int> placeID;
unordered_map<int, string> placeName;

#define debug(x) cerr << __LINE__<<(#x) << ' ' << x << endl;

void dfs(int v, int p)
{
    int children = 0;
    vis[v] = 1;
    low[v] = d[v] = t++;

    //debug(v);

    for (auto c : adj[v])
    {
        if (!vis[c])
        {
            children++;
            dfs(c, v);

            low[v] = min(low[c], low[v]);

            if (p != -1 && low[c] >= d[v])
                AP[v] = 1;
        }
        else if (c != p)
        {
        //    debug(c);
            low[v] = min(low[v], d[c]);
        }
    }
    if (p == -1 && children > 1)
    {
        AP[v] = 1;
    }
}

int main()
{
    int map_number=1;
    bool f=0;
    while (true)
    {
        t = 1;
        int V;
        cin >> V;
        // if(map_number!=1 && V)
        //     cout<<"\n";
        if (V == 0)
            break;

        if(f)cout<<"\n";
        f=1; 
        

        memset(vis, 0, sizeof(vis));
        memset(d, 0, sizeof(d));
        memset(low, 0, sizeof(low));
        memset(AP, 0, sizeof(AP));

        places.clear();
        placeID.clear();
        adj.clear();
        adj.resize(V + 1);

        for (int i = 1; i <= V; i++)
        {
            string s;
            cin >> s;
            places.pb(s);
            placeID[s] = i;
            placeName[i] = s;
        }

        int E;
        cin >> E;

        for (size_t i = 0; i < E; i++)
        {
            string a, b;
            int u, v;
            cin >> a >> b;
            u = placeID[a];
            v = placeID[b];

            adj[u].pb(v);
            adj[v].pb(u);
        }

        for (size_t i = 1; i <= V; i++)
        {
            if (!vis[i])
            {
                int p = -1;
                dfs(i, p);
            }
        }

        vector<string> cameras;
        for (size_t i = 0; i <= V; i++)
        {
            if (AP[i])
                cameras.pb(placeName[i]);
        }

        sort(cameras.begin(),cameras.end());

        cout << "City map #" << map_number << ": " << cameras.size() << " camera(s) found" << endl;
        for (string it: cameras)
        {
            cout << it <<"\n";
        }
       

        map_number++;
    }

    return 0;
}
