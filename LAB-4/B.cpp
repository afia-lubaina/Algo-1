#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define pb push_back
#define ss second
#define ff first
vector<vector<pii>>graph;
int start,n,m;
vector<int>dis;
vector<int>par;
const int INF = 1e9;

void dijkstra(){

    start = 0;
    dis[0]=0; 

    priority_queue<pii,vector<pii>, greater<pii>> min_heap;

    min_heap.push({0,0}); 

    while(!min_heap.empty()){
        int u=min_heap.top().ss;
        min_heap.pop();

        for(auto it: graph[u]){

            int v=it.ss;
            int w=it.ff; 
            if(dis[v]>dis[u]+w){
                par[v]=u;
                dis[v]=dis[u]+w; 
                min_heap.push({dis[v],v});
            }
            else if(dis[v]== (dis[u]+w) && par[v]>u){
                par[v]=u;
            }
        }
    }
    


}

int main(){

    cin>>n>>m;
    graph.resize(n);
    par.resize(n);
    dis.assign(n,INF);
     
    for (size_t i = 0; i < m; i++)
    {
       int u,w,v; 
       cin>>u>>v>>w; 
       graph[u].pb({w,v});

    }
    

    dijkstra();

    if(dis[1]==INF)
       cout<<"NOT REACHABLE"<<"\n";
    else{
        vector<int>ans; 
        int curr=1;

        while(curr!=0){
            ans.pb(curr); 
            curr=par[curr];
        }

        ans.pb(0);
        reverse(ans.begin(), ans.end());

        for(auto it: ans)
          cout<<it<<"\n";
    

    }
    
    
}


// 7
// 6
// 4 3 2
// 4 2 5
// 0 4 3
// 3 2 1
// 3 6 50
// 2 1 10


// 0
// 4
// 3
// 2
// 1
