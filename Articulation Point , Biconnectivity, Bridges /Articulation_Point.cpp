#include <bits/stdc++.h>
using namespace std;

int t = 1;
const int M = 2e5 + 10;
#define pb push_back
#define ff first
#define ss second

vector<vector<int> > adj;
int AP[M],vis[M],d[M],low[M];

#define debug(x) cerr << (#x) << ' ' << x << endl;


void dfs(int v,int p){

int children=0;
vis[v]=1;
low[v]=d[v]=t++;

debug(v);

    for(auto c: adj[v]){

        if(!vis[c]){
            children++;
            dfs(c,v);

            low[v]=min(low[c],low[v]);
            
            if(p!=-1 && low[c]>=d[v])
              AP[v]=1;

        }
        else if(c!=p){
            debug(c);
            low[v]=min(low[v],d[c]);
        }

    }
    if(p==-1 && children>1){
        AP[v]=1;
    }


}

int main(){
    
    int V,E;
    cin>>V>>E;
    adj.resize(V+1);

    for (size_t i = 0; i < E; i++)
    {
        int u,v; cin>>u>>v; 
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (size_t i = 1; i <=V; i++)
    {   
       if(!vis[i]){
            int p=-1;
            dfs(i,p);
       }
    }

    for (size_t i = 1; i <=V; i++)
    {
       if(AP[i])
        cout<<i<<" ";
    }

    cout<<endl;
    
}
