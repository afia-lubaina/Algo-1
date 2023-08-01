#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ff first
#define ss second 

void dfs(int u, vector<vector<int>>&adj, vector<int>&vis, vector<int>&new_cmp){
	new_cmp.push_back(u);
	vis[u]=1;

	for(auto v: adj[u]){

		if(vis[v])continue;
		dfs(v,adj,vis,new_cmp);
	}
}

int main(){

	int N,M; cin>>N>>M;
	std::vector<vector<int>> adj(N+1);
	std::vector<int> vis(N+1);

	for (int i = 0; i < M; ++i)
	{
		int x,y; cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	std::vector<vector<int>> cmps;

	for (int i = 1; i<=N; ++i)
	{
		if(vis[i])continue;
		std::vector<int>new_cmp;
		dfs(i,adj,vis,new_cmp);
        cmps.push_back(new_cmp);

	}

	cout << cmps.size()-1<< "\n";
    
    for (int i = 0; i < cmps.size()-1; ++i)
    {
         cout<<cmps[i][0]<<" "<<cmps[i+1][0];
         cout<<"\n";
    }

}
