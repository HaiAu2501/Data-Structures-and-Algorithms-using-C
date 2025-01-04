#include <bits/stdc++.h>

using namespace std;

// Đếm số tập con có tổng bằng s

int main()
{
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    vector<vector<int>> dp(n + 1, vector<int>(s + 1, 0));
    dp[0][0] = 1; // 1 cách tạo tổng 0 từ tập rỗng, là chính tập rỗng
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // dp[i][j] là số tập con có tổng bằng j lấy từ a[1], a[2], a[3],..., a[i]
    // dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i]]

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= s; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i])
                dp[i][j] += dp[i - 1][j - a[i]];
        }

    cout << dp[n][s];
}