#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Đề bài: Cho dãy số nguyên a[0..n-1].
 | - Gọi q(i, j) là phần tử nhỏ nhất của dãy con a[i..j]
 | - Cho m cặp (i1, j1), (i2, j2),..., (im, jm)
 | - Tính giá trị của Q = q(i1, j1) + q(i2, j2) + ... + q(im, jm)
 */

/* ĐẦU VÀO:
 | - Dòng đầu tiên là số nguyên dương n (1 <= n <= 10^6)
 | - Các số nguyên dương a[0..n - 1] (1 <= a[i] <= 10^6)
 | - Dòng tiếp theo là số nguyên dương m (1 <= m <= 10^6)
 | - m dòng tiếp theo là cặp số ik, jk với 0 <= ik < jk < n
 */

/* ĐẦU RA:
 | - Giá trị của Q
 */

int n, m;
long long Q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    cin >> m;

    vector<int> log2(n + 1);
    log2[1] = 0;
    for (int i = 2; i <= n; i++)
        log2[i] = log2[i / 2] + 1;

    vector<vector<int>> M(n, vector<int>(log2[n] + 1));

    for (int i = 0; i < n; i++)
        M[i][0] = a[i];

    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 0; i + (1 << j) <= n; i++)
            M[i][j] = min(M[i][j - 1], M[i + (1 << (j - 1))][j - 1]);
    }

    for (int k = 0; k < m; k++)
    {
        int i, j;
        cin >> i >> j;
        int l = log2[j - i + 1];
        Q += min(M[i][l], M[j - (1 << l) + 1][l]);
    }

    cout << Q;
}