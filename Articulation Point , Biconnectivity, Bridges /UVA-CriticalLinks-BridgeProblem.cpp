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

   // debug(v);

    for (auto c : adj[v]) {
        if (!vis[c]) {
            children++;
            dfs(c, v);

            low[v] = min(low[c], low[v]);

            if (low[c] > d[v]){
                if(v<c)
                bridges.pb({v, c});
                else bridges.pb({c,v});
            }
        } else if (c != p) {
            // debug(c);
            low[v] = min(low[v], d[c]);
        }
    }
}

int main() {

    
    int V;

    while(cin >> V){

        if(V!=0){
        
        adj.clear();
        memset(vis,0,V*4);
        memset(low,0,V*4);
        memset(d,0,V*4);
        bridges.clear();
        adj.resize(V);
       // debug(V);
       

        for (size_t i = 0; i < V; i++)
        {
           int u,num; char ch1,ch2; 
           cin>>u; //debug(u); 
           cin>>ch1;
           cin>>num;
           cin>>ch2;
           int v; 
           while(num--){
            cin>>v;
            adj[u].pb(v);
            adj[v].pb(u);
           }
        }
        

        for (size_t i = 0; i <V; i++) {
            if (!vis[i]) {
                int p = -1;
                dfs(i, p);
            }
        }

        cout<<bridges.size()<<" "<<"critical links"<<"\n";

        sort(bridges.begin(),bridges.end());

        for (size_t i = 0; i < bridges.size(); i++)
        {
            cout<<bridges[i].ff<<" - "<<bridges[i].ss<<"\n";
        }

        cout<<"\n";
        


        }
        else 
            cout<<'0'<<" "<<"critical links"<<"\n"<<"\n";
        
    }
}
