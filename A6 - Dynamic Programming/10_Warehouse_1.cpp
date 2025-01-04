#include <bits/stdc++.h>

using namespace std;

/* ĐỀ BÀI:
- Một chiếc xe tải muốn đến N trạm 1..N, trạm i có tọa độ i và a[i] hàng hóa, t[i] thời gian lấy hàng.
- Một lộ trình là dãy x[1..k] mà 1 <= x[1] < x[2] < ... < x[k] <= N.
- Điều kiện x[i + 1] - x[i] <= D và tổng thời gian lấy hàng <= T.
- Tìm tổng hàng lớn nhất mà xe tải có thể lấy được.
 */

int main()
{
    int N, T, D;
    cin >> N >> T >> D;

    vector<int> a(N + 1), t(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    for (int i = 1; i <= N; i++)
        cin >> t[i];

    // Gọi dp[i][time] là tổng hàng lớn nhất nếu dừng ở trạm i và dùng đúng time thời gian
    // dp[i][time] = -1 nếu không thể dừng ở trạm i và dùng đúng time thời gian
    // dp[i][time] >= 0 nếu có thể dừng ở trạm i và dùng đúng time thời gian
    vector<vector<int>> dp(N + 1, vector<int>(T + 1, -1));
    for (int i = 1; i <= N; i++)
    {
        if (t[i] <= T)
            dp[i][t[i]] = max(dp[i][t[i]], a[i]);
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = max(1, i - D); j < i; j++)
        {
            for (int used = 0; used <= T; used++)
            {
                if (dp[j][used] == -1)
                    continue;

                int newTime = used + t[i];
                if (newTime <= T)
                    dp[i][newTime] = max(dp[i][newTime], dp[j][used] + a[i]);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
        for (int time = 0; time <= T; time++)
            ans = max(ans, dp[i][time]);

    cout << ans;
}