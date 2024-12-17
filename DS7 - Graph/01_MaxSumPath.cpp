#include <bits/stdc++.h>

using namespace std;

// Cho cây vô hướng T = (V, E), mỗi cạnh (u, v) có trọng số w(u, v). Tìm đường đi có tổng trọng số lớn nhất.

#define MAX 100005
#define pii pair<int, int>

int n;
set<pii> adj[MAX]; // Danh sách kề của đỉnh u: adj[u] = {(v1, w1), (v2, w2), ...}

pii bfs(int start)
{
    queue<int> q;
    vector<int> dist(MAX, -1); // Mảng lưu khoảng cách từ đỉnh start
    q.push(start);
    dist[start] = 0;

    int max_dist = 0, farthest_node = start;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto [v, w] : adj[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + w;
                if (dist[v] > max_dist)
                {
                    max_dist = dist[v];
                    farthest_node = v;
                }
                q.push(v);
            }
        }
    }
    return {farthest_node, max_dist};
}

int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].insert({v, w});
        adj[v].insert({u, w});
    }

    // Lần 1: BFS để tìm đỉnh xa nhất từ 1 đỉnh bất kỳ
    int u = bfs(1).first;

    // Lần 2: BFS từ đỉnh xa nhất tìm được ở lần 1
    cout << bfs(u).second;
}