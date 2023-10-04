#include <bits/stdc++.h>
using namespace std;
int N,W;
#define ff first 
#define ss second
#define debug(x) cerr << (#x) << ' ' << x << endl;
typedef long long ll;
typedef pair<ll, ll> pii ;

vector<int> v;

ll f(ll n, ll len , vector<vector<ll>>&dp){

    if( n == 0 ) 
     {  
        return (len*v[0]);
     }

    if(dp[n][len]!=-1)
        return dp[n][len]; 

    ll nt=f(n-1,len,dp);
    ll t=LLONG_MIN; 
    
    if(n+1<=len)
        t=v[n]+f(n,len-(n+1),dp);

    dp[n][len]=max(nt,t);
    return max(nt,t);

}

int main()
{
  
  cin >> N;
  v.resize(N);
  vector<vector<ll> > dp(N,vector<ll> (N+1,-1));
  
  for (size_t i = 0; i < N; i++)
  {
    cin>>v[i];
  }


  cout<<f(N-1,N,dp);

  
  // cout << dp[n - 1]<<"\n";
}