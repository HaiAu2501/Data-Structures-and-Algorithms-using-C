#include <bits/stdc++.h>

using namespace std;

// https://codeforces.com/contest/20/problem/C
// Đa đồ thị vô hướng có trọng số, tìm đường đi ngắn nhất từ 1 đến n

#define ll long long

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    int u, v, w;
    while (m--)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Dijkstra
    const ll INF = 1e18;
    vector<ll> dist(n + 1, INF);                                        // dist[i]: đường đi ngắn nhất từ 1 đến i
    vector<int> parent(n + 1, -1);                                      // parent[i]: đỉnh trước i trên đường đi ngắn nhất từ 1 đến i
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq; // Mỗi phần tử: {dist[i], i}

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto &[v, w] : adj[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[n] == INF)
    {
        cout << -1;
        return 0;
    }

    vector<int> path;
    for (int v = n; v != -1; v = parent[v])
        path.push_back(v);
    reverse(path.begin(), path.end());

    for (int v : path)
        cout << v << ' ';

    return 0;
}