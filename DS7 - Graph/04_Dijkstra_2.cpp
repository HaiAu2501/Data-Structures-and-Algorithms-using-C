#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Có n thành phố 1..n, giữa thành phố i, j có thể có đường (2 chiều)
// Mỗi thành phố i có tuyến xe bus i với giá vé C[i] và số thành phối tối đa mà tuyến bus đi được D[i]
// Tìm cách đi từ thành phố 1 đến n sao cho tổng giá vé là nhỏ nhất

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> buses(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> buses[i].first >> buses[i].second;

    // Đồ thị gốc
    vector<vector<int>> adj(n + 1, vector<int>());
    int u, v;
    while (m--)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Xây dựng đồ thị mới
    vector<vector<pair<int, int>>> newAdj(n + 1, vector<pair<int, int>>());

    vector<int> visited(n + 1, 0);
    int time = 1;

    for (int i = 1; i <= n; i++)
    {
        int C = buses[i].first;
        int D = buses[i].second;

        // BFS từ i với giới hạn D bước
        queue<int> q;
        q.push(i);
        visited[i] = time;

        int step = 0;
        while (!q.empty() && step < D)
        {
            int sz = q.size();
            for (int s = 0; s < sz; s++)
            {
                int u = q.front();
                q.pop();
                for (int &v : adj[u])
                {
                    if (visited[v] != time)
                    {
                        visited[v] = time;
                        q.push(v);
                        newAdj[i].push_back({v, C});
                    }
                }
            }
            step++;
        }
        time++;
    }

    // Dijkstra trên đồ thị mới
    const ll INF = 1e18;
    vector<ll> dist(n + 1, INF); // dist[i]: đường đi ngắn nhất từ 1 đến i
    dist[1] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq; // Mỗi phần tử: {dist[i], i}
    pq.push({0, 1});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (u == n)
            break;

        if (d > dist[u])
            continue;

        for (auto &[v, w] : newAdj[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << (dist[n] == INF ? -1 : dist[n]);
}