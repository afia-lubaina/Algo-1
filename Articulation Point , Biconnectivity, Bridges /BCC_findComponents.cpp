#include <bits/stdc++.h>
using namespace std;

int t = 1;
const int M = 2e5 + 10;
#define pb push_back
#define ff first
#define ss second

vector<vector<int> > adj;
int AP[M],vis[M],d[M],low[M];

 stack<pair<int, int>> st;
 int bccCount = 0;

 vector<vector<pair<int,int>> >BiconnectedComponents;

#define debug(x) cerr << (#x) << ' ' << x << endl;


void dfs(int v,int p){

int children=0;
vis[v]=1;
low[v]=d[v]=t++;


    for(auto c: adj[v]){

     
        if(!vis[c]){
            children++;
            st.push({v,c});
            dfs(c,v);

            low[v]=min(low[c],low[v]);
            
            if ((d[v]>1 && low[c] >= d[v]) || (d[v]==1 && children > 1))
                {   
                    AP[v]=1;
                    vector<pair<int,int>>cmp;
                    while (st.top().ff != v || st.top().ss != c)
                    {
                        cmp.pb({st.top().ff,st.top().ss});
                        st.pop();
                    }
                    cmp.pb({st.top().ff,st.top().ss});
                    st.pop();
                    bccCount++;
                    BiconnectedComponents.pb(cmp);
                }
        }
        else if(c!=p){
           
            low[v]=min(low[v],d[c]);
            if (d[c] < d[v])
                {
                    st.push({v, c});
                }
        }

    }
  
}

int main(){
    
    int V,E;
    cin>>V>>E;
    adj.resize(V);

    for (size_t i = 0; i < E; i++)
    {
        int u,v; cin>>u>>v; 
        adj[u].pb(v);
       // adj[v].pb(u);
    }

    for (size_t i = 0; i <V; i++)
    {   
       if(!vis[i]){
            int p=-1;
            dfs(i,p);
       }
    }

    int i = 0;
    vector<pair<int,int>>cmp;
    while (st.size() > 0)
    {
        i = 1;
        cmp.pb({st.top().ff, st.top().ss});
        st.pop();
    }
    BiconnectedComponents.pb(cmp);

    if (i == 1)
    {
        cout << endl;
        bccCount++;
    }

    // for (size_t i = 1; i <=V; i++)
    // {
    //    if(AP[i])
    //     cout<<i<<" ";
    // }

    for (size_t i = 0; i < BiconnectedComponents.size(); i++)
    {
        for(auto it: BiconnectedComponents[i])
            cout<<it.ff<<"-"<<it.ss<<" ";
        cout<<"\n";
    }
    

    cout<<bccCount<<"\n";



    cout<<endl;
    
}
