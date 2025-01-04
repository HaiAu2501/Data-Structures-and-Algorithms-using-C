#include <bits/stdc++.h>

using namespace std;

/* ĐỀ BÀI:
- Cần xếp lịch cho 1 y tá trong N ngày liên tiếp.
- Không có 2 ngày nghỉ (0) liên tiếp.
- Dãy ngày làm việc (1) liên tiếp >= K1 và <= K2.
 */

const int MOD = 1e9 + 7;

int main()
{
    int N, K1, K2;
    cin >> N >> K1 >> K2;

    vector<vector<int>> dp(N + 1, vector<int>(2, 0));
    // dp[i][0]: số cách xếp lịch cho i ngày, kết thúc bằng 0
    // dp[i][1]: số cách xếp lịch cho i ngày, kết thúc bằng 1
    dp[1][0] = 1;  // dp[2..K1][0] = 0
    dp[K1][1] = 1; // dp[1..K1 - 1] = 0

    for (int i = K1 + 1; i <= N; ++i)
    {
        // TH 1: Nếu ngày i là 0
        dp[i][0] = dp[i - 1][1];

        // TH 2: Nếu ngày i là 1
        // Liền trước ngày i có thể có từ K1 đến K2 ngày 1 hoặc ngày 0
        for (int j = K1; j <= K2; j++)
        {
            if (i - j >= 1)
                dp[i][1] = (dp[i][1] + dp[i - j][0]) % MOD;
            if (i == j)
                dp[i][1] = (dp[i][1] + 1) % MOD;
        }
    }

    cout << (dp[N][0] + dp[N][1]) % MOD;
}