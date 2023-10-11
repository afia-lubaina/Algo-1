
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=100;
vector<vector<ll>>dp(M,vector<ll>(M,-1));

ll MCM(vector<ll>&v, int i, int j){

    if(i==j)return 0; 
    if(dp[i][j]!=-1)return dp[i][j];
    
    dp[i][j]=INT_MAX;
    for (size_t k = i; k< j; k++)
    {
        ll cost = MCM(v, i, k) + MCM(v, k + 1, j) + v[i - 1] * v[k] * v[j];
        dp[i][j] = min(dp[i][j], cost);
    }

    return dp[i][j];

}

int main(){
    int n; cin>>n ;
    vector<ll>v(n); 
    for (size_t i = 0; i < v.size(); i++)
    {
       cin>>v[i] ;
    }
    
    cout<<"min no of Multiplication: "<<MCM(v,1,n-1)<<"\n";
}
