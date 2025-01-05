#include <bits/stdc++.h>

using namespace std;

// Đếm số tập con có tổng >= L và <= U

int main() {
    int n, L, U;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    cin >> L >> U;

    vector<vector<int>> dp(n + 1, vector<int>(U + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int s = 0; s <= U; ++s) {
            dp[i][s] = dp[i - 1][s];
            if (s >= a[i - 1]) dp[i][s] += dp[i - 1][s - a[i - 1]];
        }
    }

    int ans = 0;
    for (int s = L; s <= U; ++s) ans += dp[n][s];

    cout << ans;
    return 0;
}