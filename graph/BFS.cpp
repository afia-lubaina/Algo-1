#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ff first
#define ss second

int main(){


	int N,M; cin>>N>>M;

	vector<int>adj[N+1];

	for (int i = 0; i < M; ++i)
	{
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);

	}

	queue<int>q;
	std::vector<int> dis(N+1),vis(N+1);

	dis[1]=0;
	vis[1]=1;
	q.push(1);

	while(!q.empty()){

		int p=q.front(); 
		q.pop();
		for(auto v: adj[p])
		{
			if(vis[v])
				continue;
		    vis[v]=1;
		    dis[v]=dis[p]+1;
		    q.push(v);
		}
	}


	for (int i = 1; i<=N; ++i)
	{
		cout<<i<<" "<<":"<<dis[i]<<"\n";
	}



	
}
