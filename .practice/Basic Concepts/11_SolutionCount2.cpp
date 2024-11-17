#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

// ĐỀ BÀI: Đếm số nghiệm nguyên dương x[1..n] của phương trình a[1]x[1] + a[2]x[2] + ... + a[n]x[n] = M (*)

/* ĐẦU VÀO:
 | - Dòng thứ nhất là 2 số nguyên dương n và M.
 | - Dòng thứ hai là n số nguyên dương a[1..n].
 */

// ĐẦU RA: Số lượng các bộ số (x[1], x[2],..., x[n]) thỏa mãn phương trình (*).

ll n, M;
vector<ll> a;
vector<ll> x;
ll sum;
ll solution;

void TRY(ll k)
{
    for (ll v = 1; sum + v * a[k] <= M; v++)
    {
        x[k] = v;
        sum += v * a[k];
        if (k == n)
        {
            if (sum == M)
                solution++;
        }
        else
        {
            // Nhánh cận để giảm số lượng lần duyệt
            if (sum + (n - k) * a[k + 1] <= M)
                TRY(k + 1);
        }
        sum -= v * a[k];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> M;
    a.resize(n + 1);
    x.resize(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // Sắp xếp dãy
    sort(a.begin(), a.end());

    TRY(1);
    cout << solution;
}