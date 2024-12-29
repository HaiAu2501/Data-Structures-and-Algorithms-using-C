#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

const int N = 1e5 + 5;

int n, m, s, t;
vector<pii> adj[N];

int main()
{
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, 0});
    }

    int max_flow = 0;

    while (true)
    {
        vector<int> par(n + 1, -1);
        queue<pii> q;
        q.push({s, INT_MAX});
        while (!q.empty())
        {
            int u = q.front().first;
            int flow = q.front().second;
            q.pop();
            for (auto [v, c] : adj[u])
            {
                if (par[v] == -1 && c > 0)
                {
                    par[v] = u;
                    int new_flow = min(flow, c);
                    if (v == t)
                    {
                        max_flow += new_flow;
                        while (v != s)
                        {
                            int p = par[v];
                            for (auto &e : adj[p])
                            {
                                if (e.first == v)
                                {
                                    e.second -= new_flow;
                                    break;
                                }
                            }
                            bool found = false;
                            for (auto &e : adj[v])
                            {
                                if (e.first == p)
                                {
                                    e.second += new_flow;
                                    found = true;
                                    break;
                                }
                            }
                            if (!found)
                                adj[v].push_back({p, new_flow});
                            v = p;
                        }
                        break;
                    }
                    q.push({v, new_flow});
                }
            }
        }
        if (par[t] == -1)
            break;
    }

    cout << max_flow << endl;
}