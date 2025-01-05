#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<ll> a(N);
    for (auto &x : a)
    {
        int i;
        cin >> i >> x;
    }

    // Tính tổng tiền tố
    vector<ll> prefix(N + 1, 0);
    for (int i = 1; i <= N; i++)
        prefix[i] = prefix[i - 1] + a[i - 1];

    // Khởi tạo DP
    // DP[k][i] là vector các cặp (min_sum, max_sum)
    // Sử dụng vector of vectors of vectors
    vector<vector<vector<pii>>> DP(K + 1, vector<vector<pii>>(N + 1));

    // Khi k=1, chỉ có một đoạn từ 1 đến i
    for (int i = 1; i <= N; i++)
    {
        DP[1][i].emplace_back(prefix[i], prefix[i]);
    }

    // Hàm loại bỏ các cặp bị thua
    auto prune = [&](vector<pii> &v)
    {
        // Sắp xếp các cặp theo min_sum tăng dần, nếu min_sum bằng thì max_sum tăng dần
        sort(v.begin(), v.end(), [&](const pii &a, const pii &b) -> bool
             {
            if(a.first != b.first) return a.first < b.first;
            return a.second < b.second; });
        vector<pii> pruned;
        ll current_min_max = LLONG_MAX;
        for (auto &[mn, mx] : v)
        {
            if (mx < current_min_max)
            {
                pruned.emplace_back(mn, mx);
                current_min_max = mx;
            }
        }
        v = pruned;
    };

    // Lặp qua các số đoạn từ 2 đến K
    for (int k = 2; k <= K; k++)
    {
        for (int i = k; i <= N; i++)
        {
            // Tìm j từ k-1 đến i-1
            for (int j = k - 1; j <= i - 1; j++)
            {
                ll sum_new = prefix[i] - prefix[j];
                // Duyệt qua tất cả các cặp trong DP[k-1][j]
                for (auto &[prev_min, prev_max] : DP[k - 1][j])
                {
                    ll new_min = min(prev_min, sum_new);
                    ll new_max = max(prev_max, sum_new);
                    DP[k][i].emplace_back(new_min, new_max);
                }
            }
            // Loại bỏ các cặp bị thua để giảm kích thước
            prune(DP[k][i]);
        }
    }

    // Tìm chênh lệch nhỏ nhất từ DP[K][N]
    ll result = LLONG_MAX;
    for (auto &[mn, mx] : DP[K][N])
    {
        result = min(result, mx - mn);
    }
    cout << result;

    return 0;
}
