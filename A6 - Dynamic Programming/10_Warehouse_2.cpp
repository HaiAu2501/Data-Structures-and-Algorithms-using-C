#include <bits/stdc++.h>

using namespace std;

#define ll long long

/* ĐỀ BÀI:
- Có n kho hàng 1..n, kho hàng i có tọa độ i và a[i] hàng hóa.
- Tìm dãy các kho hàng 1 <= x[1] < x[2] < ... < x[k] <= n sao cho tổng hàng hóa lớn nhất và L1 <= x[i] - x[i - 1] <= L2.
 */

int main()
{
    int n, L1, L2;
    cin >> n >> L1 >> L2;

    vector<ll> a(n + 1), dp(n + 1, 0LL);
    // dp[i] là tổng hàng lớn nhất nếu dừng ở kho hàng i
    // dp[i] = max(dp[j] + a[i]) với j < i và L1 <= i - j <= L2 -> i - L2 <= j <= i - L1
    // Độ phức tạp: O(n * L2)

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = a[i];
        for (int j = i - L2; j <= i - L1; j++)
            if (j >= 1)
                dp[i] = max(dp[i], dp[j] + a[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans;
}
