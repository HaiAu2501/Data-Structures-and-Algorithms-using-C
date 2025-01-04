#include <bits/stdc++.h>

using namespace std;

// Sử dụng bitmask để tạo tất cả tập con của một tập hợp và đếm số tập con có tổng bằng s

int main()
{
    int n, s;
    cin >> n >> s;

    vector<int> a(n);
    for (int &ai : a)
        cin >> ai;

    int cnt = 0;
    int maxMask = (1 << n);
    for (int mask = 0; mask < maxMask; mask++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i))
                sum += a[i];
        if (sum == s)
            cnt++;
    }

    cout << cnt;
    return 0;
}