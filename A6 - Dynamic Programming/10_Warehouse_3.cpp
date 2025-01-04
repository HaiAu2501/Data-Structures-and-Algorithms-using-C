#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Cải tiến thuật toán bài Warehouse 2 để còn độ phức tạp O(nlogn)
// dp[i] = max(dp[j]) + a[i] với i - L2 <= j < i - L1
// -> Truy vấn max(dp[j]) trong đoạn [i - L2, i - L1] -> Sử dụng Segment Tree

struct SegmentTree
{
    int n;
    vector<ll> st;

    SegmentTree(int n) : n(n) { st.assign(4 * n + 5, 0LL); }

    // updateNode(pos, val): đặt st[pos] = max(st[pos], val)
    void updateNode(int idx, int start, int end, int pos, ll val)
    {
        if (start == end)
        {
            st[idx] = max(st[idx], val);
            return;
        }

        int mid = (start + end) / 2;
        if (pos <= mid)
            updateNode(2 * idx, start, mid, pos, val);
        else
            updateNode(2 * idx + 1, mid + 1, end, pos, val);

        st[idx] = max(st[2 * idx], st[2 * idx + 1]);
    }

    void update(int pos, ll val) { updateNode(1, 1, n, pos, val); }

    // getMax(l, r): truy vấn max trên đoạn [l, r]
    ll queryRange(int idx, int start, int end, int l, int r)
    {
        if (r < start || end < l)
            return 0;
        if (l <= start && end <= r)
            return st[idx];

        int mid = (start + end) / 2;
        ll left = queryRange(2 * idx, start, mid, l, r);
        ll right = queryRange(2 * idx + 1, mid + 1, end, l, r);
        return max(left, right);
    }

    ll getMax(int l, int r) { return queryRange(1, 1, n, l, r); }
};

int main()
{
    int n, L1, L2;
    cin >> n >> L1 >> L2;

    vector<long long> a(n + 1), dp(n + 1, 0LL);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    SegmentTree st(n);

    ll ans = 0LL;
    for (int i = 1; i <= n; i++)
    {
        int l = max(1, i - L2);
        int r = i - L1;
        if (r >= 1)
            dp[i] = st.getMax(l, r) + a[i];
        else
            dp[i] = a[i];

        st.update(i, dp[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans;
}