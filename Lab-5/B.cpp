#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;

#define debug(x) cerr << __LINE__ << " " << (#x) << ' ' << x << endl;

const int INF = 1e9; 

void floydWarshall(vector<vector<int>>& graph, int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (graph[i][k] != INF && graph[k][j] != INF)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

int main() {
    int n, m; // n = number of nodes, m = number of edges
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, INF));
    vector<vector<int>> curr(n, vector<int>(n, INF));
    adj.resize(n);

    for (int i = 0; i < n; ++i) {
        graph[i][i] = 0; // Distance from a node to itself is 0
        curr[i][i]=0;
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w; // Edge from u to v with weight w
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        graph[u][v] = w;
        graph[v][u]=w;
    }


    for (size_t i = 0; i < adj.size(); i++)
    {
       sort(adj[i].begin(), adj[i].end());
       
    }

    cout<<"0"<<"\n";


    set<int>ans;

    for (size_t i = 0; i <adj.size(); i++)
    {
        for (size_t j = 0; j < adj[i].size(); j++)
        {
            int v=adj[i][j];   // i theke j te 
            int w=graph[i][v];
            curr[i][v]=w;
            curr[v][i]=w;
            debug(i); debug(v);
            debug(curr[i][v]);

            for (size_t k = 0; k <j; k++)
            {
               int u=adj[i][k];
               debug(u);
               int w_of_uv=graph[v][u];
               debug(j); debug(u);
               curr[v][u]=w_of_uv;
               curr[u][v]=w_of_uv;
            }

            floydWarshall(curr,n); 
            int s=0; 

            for (size_t i = 0; i < n; i++)
            {
                for (size_t j = 0;  j< n; j++)
                {
                    if(i<j && curr[i][j]!=INF){
                        s+=curr[i][j];
                   
                    }
                }
                
            }

              ans.emplace(s);
            
            
        }
        
    }

    for(auto it: ans){
        cout<<it<<"\n";
    }
    

    return 0;
}
