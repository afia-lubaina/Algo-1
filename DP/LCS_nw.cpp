#include <bits/stdc++.h>
using namespace std;
#define ff first 
#define ss second
#define debug(x) cerr << (#x) << ' ' << x << endl;
typedef long long ll;
string s,t;
string match="";

int f(int i1,int i2, vector<vector<int> > & dp){
    if(i1<0 || i2<0)
        return 0; 
    if(dp[i1][i2]!=-1)
        return dp[i1][i2];
    
    int ans=0;
    if(s[i1]==t[i2]){
        ans=1+f(i1-1,i2-1,dp);
    }
    else {
        ans=max(f(i1-1, i2, dp),f(i1,i2-1,dp));
    }

    dp[i1][i2]=ans;
    return ans;
}

int main(){

    cin>>s>>t; 
   int n=s.size();
   int m=t.size();
    
   vector<vector<int>> dp(n, vector<int>(m, -1));

   cout<<f(n-1,m-1,dp);
   cout<<match<<"\n";

}