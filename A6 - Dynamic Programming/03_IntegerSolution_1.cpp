#include <bits/stdc++.h>

using namespace std;

// Đếm số nghiệm nguyên không âm của phương trình a[1]*x[1] + a[2]*x[2] + ... + a[n]*x[n] = s
// Tương đương bài toàn tìm số cách đổi mệnh giá s từ tập đồng xu a[1..n]
// Quy hoạch động -> Độ phức tạp O(n*s)

int main()
{
    int n, s;
    cin >> n >> s;
    vector<int> a(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(s + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i][0] = 1;
    }

    // d[i][j] là số cách đổi mệnh giá j từ tập đồng xu a[1..i]
    // dp[i][j] = dp[i - 1][j] + dp[i][j - a[i]] => Cần tính dp[n][s]
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= s; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i])
                dp[i][j] += dp[i][j - a[i]];
        }

    cout << dp[n][s];
}