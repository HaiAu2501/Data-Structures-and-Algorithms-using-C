#include <bits/stdc++.h>

using namespace std;

#define MAX 30

/*
ĐỀ BÀI: BÀI TOÁN XE BUS CÓ TRỌNG TẢI
- Có n hành khách 1..n
- Hành khách i muốn đi từ điểm i đến i + n (i = 1..n)
- Có 1 chiếc xe bus đang ở điểm 0 và cùng lúc chỉ chở được tối đa k hành khách
- Có 1 ma trận khoảng cách c, với c(i, j) là khoảng cách giữa i và j (i, j = 0..2n)
- Tìm lộ trình tối ưu cho xe bus, phục vụ n khách hàng và trở về điểm 0
 */

int n, maxLoad, c[MAX][MAX], cmin = INT_MAX;

// x[1..2n] là lời giải
int cost = 0, best = INT_MAX;
int load = 0, x[MAX] = {0}, visited[MAX] = {1};

void TRY(int k)
{
    if (k > 2 * n)
    {
        if (cost + c[x[k - 1]][0] < best)
            best = cost + c[x[k - 1]][0];
        return;
    }

    for (int v = 1; v < 2 * n + 1; v++)
    {
        if (!visited[v])
        {
            if (v <= n)
            {
                if (load < maxLoad)
                {
                    visited[v] = 1;
                    x[k] = v;
                    load++;
                    cost += c[x[k - 1]][v];

                    if (cost + cmin * (2 * n + 1 - k) < best)
                        TRY(k + 1);

                    visited[v] = 0;
                    load--;
                    cost -= c[x[k - 1]][v];
                }
            }
            else
            {
                if (visited[v - n])
                {
                    visited[v] = 1;
                    x[k] = v;
                    load--;
                    cost += c[x[k - 1]][v];

                    if (cost + cmin * (2 * n + 1 - k) < best)
                        TRY(k + 1);

                    visited[v] = 0;
                    load++;
                    cost -= c[x[k - 1]][v];
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> maxLoad;
    for (int i = 0; i < 2 * n + 1; i++)
    {
        for (int j = 0; j < 2 * n + 1; j++)
        {
            cin >> c[i][j];
            if (i != j && c[i][j] < cmin)
                cmin = c[i][j];
        }
    }

    TRY(1);
    cout << best;
}
