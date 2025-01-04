#include <iostream>
#include <vector>

using namespace std;

// Đếm số tập con của 1 tập n phần tử và tổng lớn hơn k cho trước

/* Ý TƯỞNG: Thay vì dùng vét cạn bằng bit mask, ta sử dụng quy hoạch động.
 | - Gọi dp[i][s] là số tập con của tập a[1..i] có tổng đúng bằng s.
 | - Công thức quy hoạch động: dp[i][s] = dp[i - 1][s] + dp[i - 1][s - a[i]].
 | - Đáp án cần tìm là dp[n][k] + dp[n][k + 1] + ... + dp[n][sum].
 */

int n, k;
int sum;

int main()
{
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a)
    {
        cin >> x;
        sum += x;
    }

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    for (int i = 0; i <= n; ++i)
        dp[i][0] = 1;

    for (int i = 1; i <= n; ++i)
        for (int s = 1; s <= sum; ++s)
        {
            dp[i][s] = dp[i - 1][s];
            if (s >= a[i - 1])
                dp[i][s] += dp[i - 1][s - a[i - 1]];
        }

    int ans = 0;
    for (int s = k; s <= sum; ++s)
        ans += dp[n][s];

    cout << ans;
}
