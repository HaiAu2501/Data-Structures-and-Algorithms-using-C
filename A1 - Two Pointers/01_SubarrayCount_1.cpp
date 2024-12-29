#include <bits/stdc++.h>

using namespace std;

// Đếm số mảng con gồm các phần tử liên tiếp có tổng <= D
// Cách 1: prefixSum -> Độ phức tạp O(n^2)

int main()
{
    int n, D;
    cin >> n >> D;

    vector<int> a(n + 1);
    // prefixSum[i][j] = tổng các phần tử từ a[i] đến a[j]
    vector<vector<int>> prefixSum(n + 1, vector<int>(n + 1));

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        prefixSum[i][i] = a[i];
        if (a[i] <= D)
            cnt++;
    }

    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            prefixSum[i][j] = prefixSum[i][j - 1] + a[j];
            if (prefixSum[i][j] <= D)
                cnt++;
        }

    cout << cnt;
}
