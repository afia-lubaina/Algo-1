#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;

int n;
vector<int> a, dp;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie();
    cin >> n;
    a.resize(n);
    dp.resize(n);
    for (auto &x : a) {
        cin >> x;
    }

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }

    int ans = *max_element(dp.begin(), dp.end());
    cout << ans << '\n';
}
