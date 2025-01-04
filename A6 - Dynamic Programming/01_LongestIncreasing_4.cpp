#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Tìm độ dài dãy con tăng dài nhất các phần tử chẵn lẻ đan xen

// Segment Tree hỗ trợ truy vấn max trên đoạn và cập nhật giá trị tại 1 điểm
// - st[]: mảng các node của cây
// - build(): xây cây ban đầu
// - update(pos, val): đặt st[pos] = max(st[pos], val)
// - query(l, r): truy vấn max trên đoạn [l, r]
struct SegmentTree
{
    int n;
    vector<int> st;

    // Hàm khởi tạo cây
    SegmentTree(int n) : n(n) { st.resize(4 * n + 5, 0); }

    void updateNode(int idx, int start, int end, int pos, int val)
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

    void update(int pos, int val) { updateNode(1, 1, n, pos, val); }

    int queryRange(int idx, int start, int end, int l, int r)
    {
        if (r < start || end < l)
            return 0;
        if (l <= start && end <= r)
            return st[idx];

        int mid = (start + end) / 2;
        int left = queryRange(2 * idx, start, mid, l, r);
        int right = queryRange(2 * idx + 1, mid + 1, end, l, r);
        return max(left, right);
    }

    int getMax(int l, int r) { return queryRange(1, 1, n, l, r); }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);

        for (ll &ai : a)
            cin >> ai;

        // 1. Nén dữ liệu
        vector<ll> vals = a;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        auto getID = [&](ll x)
        { return lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1; };

        // 2. Xây cây Segment Tree
        int M = vals.size();
        SegmentTree segEven(M), segOdd(M);

        int ans = 1;
        for (ll &x : a)
        {
            int id = getID(x);
            if (x % 2 == 0)
            {
                // dpEven[i] = 1 + max(dpOdd[j]) với j < i và a[j] < a[i]
                int bestPrev = segOdd.getMax(1, id - 1); // max dpOdd[j]
                int cur = 1 + bestPrev;                  // dpEven[i]
                segEven.update(id, cur);
                ans = max(ans, cur);
            }
            else
            {
                // dpOdd[i] = 1 + max(dpEven[j]) với j < i và a[j] < a[i]
                int bestPrev = segEven.getMax(1, id - 1); // max dpEven[j]
                int cur = 1 + bestPrev;                   // dpOdd[i]
                segOdd.update(id, cur);
                ans = max(ans, cur);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}