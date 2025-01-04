#include <bits/stdc++.h>

using namespace std;

#define ll long long

// https://codeforces.com/problemset/problem/251/A
// Có n điểm trên Ox. Đếm số cách chọn 3 điểm mà khoảng cách 2 điểm xa nhất <= D

int main()
{
    int n;
    ll D;
    cin >> n >> D;

    vector<ll> a(n);
    for (ll &ai : a)
        cin >> ai;

    sort(a.begin(), a.end());

    // binary search: a[j] - a[i] <= D -> a[j] <= a[i] + D
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int j = upper_bound(a.begin(), a.end(), a[i] + D) - a.begin() - 1;
        if (j - i >= 2)
            cnt += (j - i) * (j - i - 1) / 2;
    }

    cout << cnt;
}