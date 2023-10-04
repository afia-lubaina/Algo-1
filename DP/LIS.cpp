#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5;
int a[MAX];
int dp[MAX];

int lis(int i) {
    if (dp[i] != -1) {
        return dp[i];
    }

    int ans = 1;
    for (int j = 0; j < i; j++) {
        if (a[j] < a[i]) {
            ans = max(ans, 1 + lis(j));
        }
    }

    dp[i] = ans;
    return ans;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));

    int maxLIS = 0;
    for (int i = 0; i < n; i++) {
        maxLIS = max(maxLIS, lis(i));
    }

    cout << maxLIS << endl;

    return 0;
}
