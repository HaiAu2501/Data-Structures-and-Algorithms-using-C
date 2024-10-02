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
vector<vector<int>> A;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int BFS()
{
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> r >> c;
    A.resize(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> A[i][j];
    }
}