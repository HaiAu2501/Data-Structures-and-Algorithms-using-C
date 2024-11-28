#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/* ĐỀ BÀI: Cho ma trận A[n][m] với:
 | - A[i][j] = 1 là chướng ngại vật.
 | - A[i][j] = 0 là ô trống có thể đến.
 | Tìm đường đi ngắn nhất thoát ra khỏi mê cung.
 */

/* ĐẦU VÀO:
 | - Dòng 1: 4 số nguyên dương n, m, r, c (1 <= n, m <= 999). r, c là hàng, cột bắt đầu.
 | - n dòng tiếp theo là các hàng của ma trận.
 */

int n, m, r, c;
int A[1005][1005], dist[1005][1005], visited[1005][1005];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

void BFS(int r, int c)
{
    q.push({r, c});

    while (!q.empty())
    {
        pair<int, int> pos = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int i = pos.first + dx[k];
            int j = pos.second + dy[k];
            if (i >= 1 && i <= n && j >= 1 && j <= m && A[i][j] == 0 && visited[i][j] == 0)
            {
                if (i == 1 || i == n || j == 1 || j == m)
                {
                    cout << dist[pos.first][pos.second] + 1;
                    return;
                }

                q.push({i, j});
                visited[i][j] = 1;
                dist[i][j] = dist[pos.first][pos.second] + 1;
            }
        }
    }

    cout << -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> r >> c;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> A[i][j];
    }

    if (A[r][c] == 1)
    {
        cout << -1;
        return 1;
    }

    BFS(r, c);

    return 0;
}