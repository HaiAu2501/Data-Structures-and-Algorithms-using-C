#include <bits/stdc++.h>

using namespace std;

/* ĐỀ BÀI:
- Một xe bus ở điểm 0 và 2*n điểm 0..n, khác hàng i muốn đi từ i đến i + n
- Một xe bus chỉ chở được tối đa k hành khách
- Khoảng cách từ điểm đón đến điểm trả của mọi hành khác >= D
 */

const int N = 30;

int n, maxLoad, D, c[N][N], c_min = INT_MAX;

// x[1..2n] là lời giải | visited[1..2n] là mảng đánh dấu đã thăm | dist[1..n] là khoảng cách từ 0 đến điểm đón hành khách i
int x[N] = {0}, dist[N] = {0};
bool visited[N] = {true};
int cost = 0, best = INT_MAX;
int load = 0;

void TRY(int k)
{
    if (k > 2 * n)
    {
        if (cost + c[x[k - 1]][0] < best)
            best = cost + c[x[k - 1]][0];
        return;
    }

    for (int v = 1; v <= 2 * n; v++)
    {
        if (!visited[v])
        {
            // Nếu v là điểm đón
            if (v <= n)
            {
                if (load < maxLoad)
                {
                    x[k] = v;
                    visited[v] = true;
                    load += 1;
                    cost += c[x[k - 1]][v];

                    // Khi đón hành khác v thì cập nhật lại dist[v]
                    dist[v] = cost;

                    if (cost + c_min * (2 * n + 1 - k) < best)
                        TRY(k + 1);

                    visited[v] = false;
                    load -= 1;
                    cost -= c[x[k - 1]][v];
                }
            }
            else
            {
                int passenger = v - n;
                if (visited[passenger])
                {
                    x[k] = v;
                    visited[v] = true;
                    load -= 1;
                    cost += c[x[k - 1]][v];

                    if (cost + c_min * (2 * n + 1 - k) < best && cost - dist[passenger] >= D)
                        TRY(k + 1);

                    visited[v] = false;
                    load += 1;
                    cost -= c[x[k - 1]][v];
                }
            }
        }
    }
}

int main()
{
    cin >> n >> maxLoad >> D;

    int len = 2 * n;
    for (int i = 0; i <= len; i++)
    {
        for (int j = 0; j <= len; j++)
        {
            cin >> c[i][j];
            if (i != j)
                c_min = min(c_min, c[i][j]);
        }
    }

    TRY(1);

    if (best == INT_MAX)
        cout << -1;
    else
        cout << best;
}