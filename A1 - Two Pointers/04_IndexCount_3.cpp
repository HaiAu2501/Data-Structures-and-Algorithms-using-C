#include <bits/stdc++.h>

using namespace std;

// Đếm số cặp 1 <= i < j <= n mà l <= a[j] + a[i] <= r

// Cách dùng binary search | Độ phức tạp: O(nlogn)
long long countPairs(vector<int> &a, int l, int r)
{
    sort(a.begin(), a.end());
    long long ans = 0;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        // l <= a[j] + a[i] <= r -> l - a[i] <= a[j] <= r - a[i]
        ans += upper_bound(a.begin(), a.end(), r - a[i]) - lower_bound(a.begin(), a.end(), l - a[i]);
        if (l <= 2 * a[i] && 2 * a[i] <= r)
            ans--;
    }
    return ans / 2;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> a(n);

        for (int &ai : a)
            cin >> ai;

        // Đếm số bộ (i, j) mà a[i] + a[j] <= r và a[i] + a[j] < l
        cout << countPairs(a, l, r) << endl;
    }
}