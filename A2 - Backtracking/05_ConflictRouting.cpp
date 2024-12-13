#include <bits/stdc++.h>

using namespace std;

// CVRP bổ sung điều kiện: có m cặp khách hàng mâu thuẫn: mỗi cặp không thể được giao bởi cùng 1 xe

#define MAX 30

int n, m, K, Q, d[MAX], c[MAX][MAX], conflict[MAX], cmin = INT_MAX;

int x[MAX], y[MAX];
int load[MAX], custom[MAX];
bool visited[MAX];
int cost = 0, best = INT_MAX, path = 0, truck = 0;

void TRY_X(int);
void TRY_Y(int, int);

// Thử các giá trị cho x[k]
void TRY_X(int k)
{

    int s = 0;
    if (x[k - 1] > 0)
        s = x[k - 1] + 1;

    for (int v = s; v <= n; v++)
    {
        if (v == 0 || (!visited[v] && (custom[k] & conflict[v]) == 0))
        {
            x[k] = v;

            load[k] += d[v];
            visited[v] = true;
            cost += c[0][v];

            if (v > 0)
            {
                path++;
                custom[k] |= (1 << v);
            }

            if (k < K)
                TRY_X(k + 1);
            else
            {
                truck = path;
                TRY_Y(x[1], 1);
            }

            load[k] -= d[v];
            visited[v] = false;
            cost -= c[0][v];

            if (v > 0)
            {
                path--;
                custom[k] ^= (1 << v);
            }
        }
    }
}

void TRY_Y(int s, int k)
{
    if (s == 0)
    {
        if (k < K)
            TRY_Y(x[k + 1], k + 1);
        return;
    }

    for (int v = 0; v <= n; v++)
    {
        if (v == 0 || (!visited[v] && load[k] + d[v] <= Q && (custom[k] & conflict[v]) == 0))
        {
            y[s] = v;

            load[k] += d[v];
            visited[v] = true;
            cost += c[s][v];
            path++;

            if (v > 0)
            {
                custom[k] |= (1 << v);
                if (cost + cmin * (n + truck - path) < best)
                    TRY_Y(v, k);
                custom[k] ^= (1 << v);
            }
            else
            {
                if (k == K)
                {
                    if (path == n + truck)
                        best = min(cost, best);
                }
                else if (cost + cmin * (n + truck - path) < best)
                    TRY_Y(x[k + 1], k + 1);
            }

            load[k] -= d[v];
            visited[v] = false;
            cost -= c[s][v];
            path--;
        }
    }
}

int main()
{
    cin >> n >> K >> Q;
    for (int i = 1; i <= n; i++)
        cin >> d[i];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> c[i][j];
            if (i != j)
                cmin = min(cmin, c[i][j]);
        }
    }

    cin >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        conflict[a] |= (1 << b);
        conflict[b] |= (1 << a);
    }

    TRY_X(1);
    cout << best;
}