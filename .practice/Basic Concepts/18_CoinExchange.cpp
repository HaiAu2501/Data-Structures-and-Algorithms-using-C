#include <iostream>
#include <vector>

using namespace std;

// ĐỀ BÀI: Cho n mệnh giá tiền và số tiền cần đổi. Tìm số đồng tiền ít nhất để đổi số tiền đó.

/* ĐẦU VÀO:
 | - Dòng đầu tiên chứa số nguyên n (1 ≤ n ≤ 100) - số mệnh giá tiền và số tiền cần đổi x (1 ≤ x ≤ 10^6).
 | - Dòng thứ hai chứa n số nguyên a1, a2, ..., an (1 ≤ ai ≤ 10^6) - mệnh giá tiền.
 */

/* Ý TƯỞNG: Quy hoạch động
 | - Gọi f(x) là số đồng tiền ít nhất để đổi số tiền x.
 | - f(x) = min(f(x - a1), f(x - a2), ..., f(x - an)) + 1.
 */

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Đọc đầu vào
    int n;
    long long x;
    cin >> n >> x;
    vector<int> a(n);
    for (int &coin : a)
        cin >> coin;

    const int INF = 1e9;
    vector<int> dp(x + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= x; i++)
        for (int j = 0; j < n; j++)
            if (a[j] <= i && dp[i - a[j]] != INF)
                dp[i] = min(dp[i], dp[i - a[j]] + 1);

    if (dp[x] != INF)
        cout << dp[x];
    else
        cout << -1;

    return 0;
}