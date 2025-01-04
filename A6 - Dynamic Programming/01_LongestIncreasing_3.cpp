#include <bits/stdc++.h>

using namespace std;

// Tìm độ dài dãy con tăng dài nhất các phần tử chẵn lẻ đan xen

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (long long &ai : a)
            cin >> ai;

        vector<int> dp(n, 1);
        // Công thức: dp[i] = max(dp[j] + 1) với j < i, a[j] % 2 != a[i] % 2 và a[j] < a[i] => Độ phức tạp O(n^2)
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
            {
                if (((a[i] & 1) != (a[j] & 1)) && a[j] < a[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }

        cout << *max_element(dp.begin(), dp.end()) << endl;
    }
}