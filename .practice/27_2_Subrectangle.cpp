#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Ý TƯỞNG: Cách 2 - QUY HOẠCH ĐỘNG
 | - Gọi dp[r][c] là số ô màu đen trong hình chữ nhật con lớn nhất bắt đầu từ (1, 1) và kết thúc tại (r, c).
 | - Công thức quy hoạch động: dp[r][c] = dp[r - 1][c] + dp[r][c - 1] - dp[r - 1][c - 1] + a[r][c].
 | - Cuối cùng, duyệt qua tất cả các hình chữ nhật con bắt đầu từ (r1, c1) đến (r2, c2).
 | - Độ phức tạp: O(n^2 * m^2).
 */

int n, m;

int main()
{
    cin >> n >> m;

    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int r = 1; r <= n; ++r)
        for (int c = 1; c <= m; ++c)
        {
            cin >> a[r][c];
            dp[r][c] = dp[r - 1][c] + dp[r][c - 1] - dp[r - 1][c - 1] + a[r][c];
        }

    int ans = 0;

    for (int r1 = 1; r1 <= n; ++r1)
        for (int c1 = 1; c1 <= m; ++c1)
            for (int r2 = r1; r2 <= n; ++r2)
                for (int c2 = c1; c2 <= m; ++c2)
                {
                    int sum = dp[r2][c2] - dp[r1 - 1][c2] - dp[r2][c1 - 1] + dp[r1 - 1][c1 - 1];
                    if (sum == (r2 - r1 + 1) * (c2 - c1 + 1))
                        ans = max(ans, sum);
                }

    cout << ans;
}