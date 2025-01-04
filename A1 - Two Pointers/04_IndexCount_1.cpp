#include <bits/stdc++.h>

using namespace std;

// Đếm số bộ (i, j, k) mà 1 <= i < j < k <= n mà a[i] + a[j] + a[k] = Q

int main()
{
    const int N = 1e9 + 7;
    int n, Q;
    cin >> n >> Q;
    vector<int> a(n);

    for (int &x : a)
        cin >> x;

    sort(a.begin(), a.end());

    int cnt = 0;
    for (int i = 0; i < n - 2; i++)
    {
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            if (a[i] + a[l] + a[r] == Q)
            {
                cnt++;
                l++;
                r--;
            }
            else if (a[i] + a[l] + a[r] < Q)
                l++;
            else
                r--;
        }
    }

    cout << cnt;
}