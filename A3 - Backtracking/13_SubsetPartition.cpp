#include <bits/stdc++.h>

using namespace std;

// Chia n số thành 2 tập sao cho hiệu giữa tổng 2 tập là nhỏ nhất (dùng bitmask)

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    int sum = 0;
    for (int &ai : a)
    {
        cin >> ai;
        sum += ai;
    }

    int minDiff = INT_MAX;
    int maxMask = (1 << n);
    for (int mask = 0; mask < maxMask; mask++)
    {
        int sum1 = 0;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i))
                sum1 += a[i];
        minDiff = min(minDiff, abs(sum - 2 * sum1));
    }

    cout << minDiff;
}