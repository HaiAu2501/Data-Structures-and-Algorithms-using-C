#include <bits/stdc++.h>

using namespace std;

// Tìm đường đi qua n thành phố và quay lại thành phố bắt đầu
// Thêm điều kiện về thứ tự: cặp (i, j) thì i được thăm trước j

#define MAX 200

int n, k, c[MAX][MAX], in[MAX];
set<int> depend[MAX];
int cost;
vector<int> tour;

void GREEDY()
{
    int start = -1;
    for (int i = 1; i <= n; i++)
    {
        if (!in[i])
        {
            start = i;
            break;
        }
    }

    if (start == -1)
    {
        cout << "No valid starting city found. There might be a cycle in the constraints.\n";
        return;
    }

    vector<bool> visited(n + 1, false);
    int current = start;
    visited[current] = true;
    tour.push_back(current);

    for (int step = 1; step < n; step++)
    {
        int next = -1;
        int minCost = INT_MAX;

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i] & in[i] == 0 & c[current][i] < minCost)
            {
                next = i;
                minCost = c[current][i];
            }
        }

        if (next == -1)
        {
            cout << "No valid tour found.\n";
            return;
        }

        visited[next] = true;
        cost += minCost;
        tour.push_back(next);

        for (int depend : depend[current])
            in[depend]--;

        current = next;
    }

    cost += c[current][start];
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
        }
    }
    cin >> k;
    int x, y;
    while (k--)
    {
        cin >> x >> y;
        in[y]++;
        depend[x].insert(y);
    }
    GREEDY();
    if (tour.size() == n)
    {
        cout << cost << "\n";
        for (int city : tour)
            cout << city;
    }
}