#include <bits/stdc++.h>
using namespace std;
int N,W;
#define ff first 
#define ss second
#define debug(x) cerr << (#x) << ' ' << x << endl;
typedef long long ll;
typedef pair<ll, ll> pii ;
vector<pii> v;

int main()
{
  
  cin >> N>>W;;
  v.resize(N);
  vector<vector<ll> > dp(N,vector<ll> (W+1,0));
  for (size_t i = 0; i < N; i++)
  {
    cin>>v[i].ff;
    cin>>v[i].ss;
  }

  
  for (int i=v[0].ff; i<=W; i++) dp[0][i]=v[0].ss;

  for (size_t i = 1; i < N; i++)
  {
     for (size_t cap = 0; cap <= W; cap++)
     {
        ll nt=dp[i-1][cap];
        ll t=LLONG_MIN;
        if(v[i].ff<=cap)
            t=v[i].ss+dp[i-1][cap-v[i].ff];
        dp[i][cap]=max(t,nt);
     }
     
  }

  cout<<dp[N-1][W]<<"\n";
  

  
  // cout << dp[n - 1]<<"\n";
}
