#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define pb push_back
#define ss second
#define ff first
vector<vector<pii>>graph;
int start,n,m;
vector<int>dis;
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
                dis[v]=dis[u]+w; 
                min_heap.push({dis[v],v});
            }
        }
    }
    


}

int main(){

    cin>>n>>m;
    graph.resize(n);
    dis.assign(n,INF);
     
    for (size_t i = 0; i < m; i++)
    {
       int u,w,v; 
       cin>>u>>v>>w; 
       graph[u].pb({w,v});

    }
    

    dijkstra();

    cout<<"0: 0"<<"\n";

    for (size_t i = 1; i < n; i++)
    {
       if(dis[i]!=INF)
             cout<<i<<": "<<dis[i]<<"\n";
       else 
             cout<<i<<": "<<-1<<"\n";
    }
    
    
}



// 7
// 6
// 1 3 2
// 1 2 5
// 0 1 3
// 3 2 1
// 3 4 50
// 2 5 10


// 0: 0
// 1: 3
// 2: 6
// 3: 5
// 4: 55
// 5: 16
// 6: -1
