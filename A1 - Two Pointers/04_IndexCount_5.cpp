#include <bits/stdc++.h>

using namespace std;

// https://codeforces.com/problemset/problem/1324/D
// Đếm số cặp 1 <= i < j <= n mà a[i] + a[j] > b[i] + b[j]
// Đặt c[i] = a[i] - b[i] -> Đếm số cặp 1 <= i < j <= n mà c[i] + c[j] > 0

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), c(n);
    for (int &x : a)
        cin >> x;

    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        c[i] = a[i] - x;
    }

    sort(c.begin(), c.end());
    // Vì c[i] + c[j] > 0 nên ít nhất 1 trong 2 số c[i], c[j] > 0
    // Nếu c[i] > 0 thì c[j] > - c[i] -> c[j] >= -c[i] + 1
    long long cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (c[i] > 0)
        {
            int j = lower_bound(c.begin(), c.end(), -c[i] + 1) - c.begin();
            cnt += i - j;
        }
    }

    cout << cnt;
}