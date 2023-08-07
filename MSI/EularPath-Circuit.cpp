#include <bits/stdc++.h>
using namespace std;
const int M= 2e5+10;
int indegree[M];
int outdegree[M];
bool vis[M];
#define debug(x) cerr << __LINE__ << " " << (#x) << ' ' << x << endl;
vector<vector<int> >adj;

void dfs(int v){

    vis[v]=1; 

    for(auto c: adj[v]){
        if(!vis[c])
            dfs(c);
    }
}

void printTrail( int start)
{

	vector<int> curr_path;
	curr_path.push_back(start);
    debug(curr_path.back());


	vector<int> circuit;

	while (curr_path.size() > 0) {
		int curr_v = curr_path[curr_path.size() - 1];
        debug(curr_v);

		if (adj[curr_v].size() > 0) {

			int next_v = adj[curr_v].back();
            debug(next_v);
			adj[curr_v].pop_back();

			curr_path.push_back(next_v);
		}

		else {
			circuit.push_back(curr_path.back());
            debug(circuit.back());
			curr_path.pop_back();
		}
	}

	for (int i = circuit.size() - 1; i >= 0; i--) {
		cout << circuit[i];
		if (i)
			cout << " -> ";
	}
}

int main()
{
	int V,E; cin>>V>>E;
    
    adj.resize(V);

    for (size_t i = 0; i < E; i++)
    {
        int u,v; cin>>u>>v; 
        adj[u].push_back(v); 
        outdegree[u]++; 
        indegree[v]++;

    }
    
    if(V==0)
        cout<<"vertex is zero"<<endl;
    
    int odd=0;
    int start;
    for (size_t i = 0; i < V; i++)
    {
        if(indegree[i]!=outdegree[i])
           {
            odd++;
            if(outdegree[i]>indegree[i])
            start=i;
           }
    }

    debug(start);

    dfs(0);

    for (int i = 0; i <V; i++) {
        if (!vis[i] && !adj[i].empty()) {
            cout << "None exist"<< endl;
            exit(0);
        }
    }


    if(odd==0){
        cout<<"Eular ckt exists"<<endl;
        printTrail( 0);
    }

    else if(odd==2){

        cout<<"Eular path exists"<<endl;
        printTrail( start);

    }

    else 
        cout<<"None exists"<<endl;



    return 0;
}

// 7 10
// 0 1
// 0 6
// 1 2 
// 2 0 
// 2 3
// 3 4
// 4 2
// 4 5
// 5 0
// 6 4

// 5 7
// 0 3
// 3 2
// 2 0
// 0 1 
// 1 2 
// 1 4
// 4 0
