#include <bits/stdc++.h>

using namespace std;

// Đếm số nghiệm nguyên dương của phương trình a[1]*x[1] + a[2]*x[2] + ... + a[n]*x[n] = s
// Tương đương đếm số nghiệm nguyên không âm của a[1]*x[1] + a[2]*x[2] + ... + a[n]*x[n] = s - a[1] - ... - a[n]

int main()
{
    int n, s, sum = 0;
    cin >> n >> s;
    vector<int> a(n);
    vector<vector<int>> dp(n + 1, vector<int>(s + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
        dp[i][0] = 1;
    }

    if (sum > s)
    {
        cout << 0;
        return 0;
    }

    s -= sum;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= s; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i])
                dp[i][j] += dp[i][j - a[i]];
        }

    cout << dp[n][s];
}