#include <iostream>

using namespace std;

#define MAX 100

/* Cách 2: Sử dụng thuật toán nhánh cận để giải bài toán TSP
 | - Tìm số c_min trong ma trận chi phí.
 | - Nếu đã thăm k thành phố thì cận dưới của cost là f = cost hiện tại + c_min * (n - k)
 */

int n, c[MAX][MAX], x[MAX], visited[MAX] = {1}, cost, minCost = 1e9, c_min = 1e9;

void TRY(int k)
{
    for (int v = 1; v < n; v++)
    {
        if (!visited[v] && cost + c_min * (n - k - 1) < minCost)
        {
            x[k] = v;
            visited[v] = 1;
            cost += c[x[k - 1]][v];

            if (k == n - 1)
            {
                cost += c[v][0];
                if (cost < minCost)
                    minCost = cost;
                cost -= c[v][0];
            }
            else
                TRY(k + 1);

            visited[v] = 0;
            cost -= c[x[k - 1]][v];
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> c[i][j];
            if (c[i][j] < c_min)
                c_min = c[i][j];
        }
    }

    TRY(1);

    cout << minCost;

    return 0;
}