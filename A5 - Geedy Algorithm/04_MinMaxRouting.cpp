#include <bits/stdc++.h>

using namespace std;

/* ĐỀ BÀI:
- Có N điểm 1..N cần thu gom bưu kiện và K bưu tá xuất phát từ điểm 0.
- d(i, j) là khoảng cách từ điểm i đến điểm j.
- Xây dựng phương án cho k bưu tá sao cho quãng đường dài nhất mà 1 bưu tá đi được là nhỏ nhất.
> ĐẦU RA: Số K và 2*K dòng: dòng trên là số điểm mà bưu tá i đi qua, dòng dưới là các điểm đó.
 */

// Lộ trình của 1 bưu tá
struct Route
{
    vector<int> path;
    int dist;
};

int main()
{
    int N, K;
    cin >> N >> K;
    vector<vector<int>> d(N + 1, vector<int>(N + 1));

    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= N; j++)
            cin >> d[i][j];

    vector<Route> r(K, {{0}, 0}); // K bưu tá, mỗi bưu tá đi từ 0
    vector<int> pts(N);
    for (int i = 0; i < N; i++)
        pts[i] = i + 1;

    sort(pts.begin(), pts.end(), [&](int i, int j)
         { return d[0][i] < d[0][j]; }); // Sắp xếp các điểm theo tứ gần nhất với 0

    for (int p : pts)
    {
        int best = -1, minDist = INT_MAX;
        for (int i = 0; i < K; i++)
        {
            int newDist = r[i].dist + d[r[i].path.back()][p];
            if (newDist < minDist)
            {
                minDist = newDist;
                best = i;
            }
        }
        r[best].path.push_back(p);
        r[best].dist = minDist;
    }

    cout << K << '\n';
    for (int i = 0; i < K; i++)
    {
        cout << r[i].path.size() << '\n';
        for (int p : r[i].path)
            cout << p << ' ';
        cout << '\n';
    }
}