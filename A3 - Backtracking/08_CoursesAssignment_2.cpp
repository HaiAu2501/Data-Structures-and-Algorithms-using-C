#include <bits/stdc++.h>

using namespace std;

/*
- Có m giảng viên và n môn học.
- Mỗi giảng viên có 1 danh sách các môn học có thể dạy.
- Có 1 danh sách các cặp môn học mâu thuẫn không thể cùng được dạy bởi 1 giảng viên.
- Load của 1 giảng viên là tổng số tín chỉ của các môn.
- Tìm min load.
 */

#define MAX 30

int m, n, teach[MAX], crd[MAX], conflict[MAX];

int load[MAX], best = INT_MAX, current = 0, assign[MAX];

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
        current = *max_element(assign + 1, assign + m + 1);
        best = min(current, best);
        return;
    }

    for (int v = 1; v <= m; v++)
        if (CHECK(v, k))
        {
            load[v] |= (1 << k);
            assign[v] += crd[k];

            if (assign[v] < best)
                TRY(k + 1);

            load[v] ^= (1 << k);
            assign[v] -= crd[k];
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
    // Số tín chỉ từng môn
    for (int i = 1; i <= n; i++)
        cin >> crd[i];
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