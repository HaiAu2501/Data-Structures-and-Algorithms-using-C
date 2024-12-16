#include <bits/stdc++.h>

using namespace std;

// Tìm độ dài dãy con tăng dài nhất (dãy con là dãy các phần tử có chỉ số tăng).
// Công thức: dp[i] = max(dp[j] + 1) với j < i và a[j] < a[i]
// Độ phức tạp O(n^2)

const int MAX = 1e3;

int n, a[MAX], dp[MAX];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        dp[i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    cout << *max_element(dp, dp + n);
}