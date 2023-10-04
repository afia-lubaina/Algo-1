#include <bits/stdc++.h>
using namespace std;
int N,W;
#define ff first 
#define ss second
#define debug(x) cerr << (#x) << ' ' << x << endl;
typedef long long ll;
typedef pair<ll, ll> pii ;


vector<pii> v;

ll f(ll n, ll wt , vector<vector<ll>>&dp){

    if( n == 0 ) 
     {  if (v[n].ff<=wt)
            return v[n].ss; 
        else return 0;
     }

    if(dp[n][wt]!=-1)
        return dp[n][wt];

    ll nt=f(n-1,wt,dp);
    ll t=LLONG_MIN; 
    if(v[n].ff<=wt)
        t=v[n].ss+f(n-1,wt-v[n].ff,dp);
    dp[n][wt]=max(nt,t);
    return max(nt,t);

}

int main()
{
  
  cin >> N>>W;;
  v.resize(N);
  vector<vector<ll> > dp(N,vector<ll> (W+1,-1));
  
  for (size_t i = 0; i < N; i++)
  {
    cin>>v[i].ff;
    cin>>v[i].ss;
  }


  cout<<f(N-1,W,dp);

  
  // cout << dp[n - 1]<<"\n";
}
