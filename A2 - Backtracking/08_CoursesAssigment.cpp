#include <bits/stdc++.h>

using namespace std;

/*
- Có m giảng viên và n môn học.
- Mỗi giảng viên có 1 danh sách các môn học có thể dạy.
- Có 1 danh sách các cặp môn học mâu thuẫn không thể cùng được dạy bởi 1 giảng viên.
- Load của 1 giảng viên là số môn học họ giảng dạy.
- Tìm min load.
 */

#define MAX 30

int m, n, teach[MAX], conflict[MAX];

int load[MAX], best = INT_MAX, current = 0;

// Check xem môn học k có thể được phân công cho giảng viên v hay không
bool CHECK(int v, int k)
{
    if (!(teach[v] & (1 << k)))
        return false;
    if (load[v] & conflict[k])
        return false;
    return true;
}

// Phân công môn học k
void TRY(int k)
{
    if (k > n)
    {
        best = min(current, best);
        return;
    }

    for (int v = 1; v <= m; v++)
        if (CHECK(v, k))
        {
            load[v] |= (1 << k);
            int prev = current;
            current = max(current, __builtin_popcount(load[v]));

            if (current < best)
                TRY(k + 1);

            load[v] ^= (1 << k);
            current = prev;
        }
}

int main()
{
    cin >> m >> n;
    int k, x, a, b;
    for (int i = 1; i <= m; i++)
    {
        cin >> k;
        while (k--)
        {
            cin >> x;
            teach[i] |= (1 << x);
        }
    }
    cin >> k;
    while (k--)
    {
        cin >> a >> b;
        conflict[a] |= (1 << b);
        conflict[b] |= (1 << a);
    }

    TRY(1);

    if (best == INT_MAX)
        cout << -1;
    else
        cout << best;
}