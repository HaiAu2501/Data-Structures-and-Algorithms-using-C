#include <bits/stdc++.h>

using namespace std;

// Cho cây T = (V, E); mỗi cạnh (u, v) có trọng số w(u, v).
// Gọi f(i) là tổng các đường đi từ các đỉnh khác tới i.
// Tính max{f(i): i thuộc V}.

#define MAX 100005
#define pii pair<int, int>

vector<pii> adj[MAX];
long long f[MAX];      // Tổng các đường đi từ các đỉnh khác tới u
int subtree_size[MAX]; // Số lượng đỉnh trong cây con gốc u
int n;

// Tính f[u] và subtree_size[u] từ dưới lên
void dfs1(int u, int p)
{
    subtree_size[u] = 1;
    for (auto [v, w] : adj[u])
    {
        if (v == p)
            continue;
        dfs1(v, u);
        subtree_size[u] += subtree_size[v];
        f[u] += f[v] + 1LL * w * subtree_size[v];
    }
}

// Tính lại f[v] khi chuyển gốc từ u sang v
void dfs2(int u, int p)
{
    for (auto [v, w] : adj[u])
    {
        if (v == p)
            continue;
        f[v] = f[u] + 1LL * w * (n - 2 * subtree_size[v]);
        dfs2(v, u);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dfs1(1, 0); // Tính f tại gốc 1
    dfs2(1, 0); // Chuyển gốc để tính f cho các đỉnh còn lại

    cout << *max_element(f + 1, f + n + 1) << endl;
    return 0;
}