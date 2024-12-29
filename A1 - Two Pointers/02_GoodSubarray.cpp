#include <bits/stdc++.h>

using namespace std;

// https://codeforces.com/problemset/problem/1840/C
// Cho mảng a có n phần tử, k, q.
// Đếm số dãy các phần tử liên tiếp của a có độ dài >= k mà tất cả phần tử <= q.
// Kĩ thuật: Two pointers -> Độ phức tạp O(n)

int main()
{
    long long t, n, k, q, x;
    cin >> t; // Số lượng test
    while (t--)
    {
        cin >> n >> k >> q;
        long long cnt = 0;
        for (long long i = 1, l = 0; i <= n; i++)
        {
            cin >> x;
            if (x <= q)
                l++;
            else
                l = 0;
            if (l >= k)
                cnt += l - k + 1;
        }
        cout << cnt << endl;
    }
}