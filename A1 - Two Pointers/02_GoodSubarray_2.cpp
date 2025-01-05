#include <bits/stdc++.h>

using namespace std;

// https://codeforces.com/problemset/problem/1736/C1
// Dãy b[1..m] là tốt nếu b[i] >= i, với i = 1..m
// Đếm tất cả cặp (l, r) mà 1 <= l <= r <= n và dãy con a[l..r] là tốt, tức là
// a[l] >= 1, a[l + 1] >= 2, ..., a[r] >= r - l + 1

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 0;

        // Gọi l[i] là số nhỏ nhất để a[l[i]..i] là tốt -> l[1..n] là dãy tăng
        // Gọi dp[i] là số cặp (l, r) mà a[l..r] là tốt và r = i | dp[0] = 0
        // dp[i] = min(dp[i - 1] + 1, a[i])
        vector<long long> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            long long x;
            cin >> x;
            dp[i] = min(dp[i - 1] + 1, x);
            ans += dp[i];
        }
        cout << ans << endl;
    }
}