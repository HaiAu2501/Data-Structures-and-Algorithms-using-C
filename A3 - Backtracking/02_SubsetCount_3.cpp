#include <bits/stdc++.h>

using namespace std;

// Cho dãy n số và số M. Chọn tập con có tổng <= M và khoảng cách đến M nhỏ nhất.

int main()
{
    int n, M;
    cin >> n;

    vector<int> a(n);
    for (int &ai : a)
        cin >> ai;

    cin >> M;

    int dist = INT_MAX;
    int maxMask = (1 << n);

    for (int mask = 0; mask < maxMask; mask++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i))
                sum += a[i];
        if (sum <= M)
            dist = min(dist, M - sum);
    }

    cout << dist;
}