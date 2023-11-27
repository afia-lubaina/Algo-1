#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;

int n;
vector<int> a, dp;

int calc(int i) {
    if (dp[i] != -1) {
        return dp[i];
    }

    dp[i] = 1;
    for (int j = i - 1; j >= 0; j--) {
        if (a[j] < a[i]) {
            dp[i] = max(dp[i], 1 + calc(j));
        }
    }

    return dp[i];
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie();
    cin >> n;
    a.resize(n);
    dp.resize(n, -1);
    for (auto &x : a) {
        cin >> x;
    }

    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        ans = max(ans, calc(i));
    } 

    cout << ans << '\n';
}
