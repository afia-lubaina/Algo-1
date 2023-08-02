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

#define debug(x) cerr << (#x) << ' ' << x << endl;


void dfs(int v,int p){

int children=0;
vis[v]=1;
low[v]=d[v]=t++;

debug(v);

    for(auto c: adj[v]){

        if(!vis[c]){
            children++;
            st.push({v,c});
            dfs(c,v);

            low[v]=min(low[c],low[v]);
            
            if ((d[v]>1 && low[c] >= d[v]) || (d[v]==1 && children > 1))
                {
                    while (st.top().first != v || st.top().second != c)
                    {
                        cout << st.top().first << "--" << st.top().second << " ";
                        st.pop();
                    }
                    cout << st.top().first << "--" << st.top().second << " ";
                    st.pop();
                    cout << endl;
                    bccCount++;
                }
        }
        else if(c!=p){
            debug(c);
            low[v]=min(low[v],d[c]);
            if (d[c] < d[v])
                {
                    st.push({v, c});
                }
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

    int i = 0;
    while (st.size() > 0)
    {
        i = 1;
        cout << st.top().first << "--" << st.top().second << " ";
        st.pop();
    }

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

    cout<<bccCount<<"\n";



    cout<<endl;
    
}
