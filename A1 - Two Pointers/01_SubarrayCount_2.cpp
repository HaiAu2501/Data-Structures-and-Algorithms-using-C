#include <bits/stdc++.h>

using namespace std;

// Đếm số mảng con gồm các phần tử liên tiếp có tổng <= D
// Cách 2: Two pointers -> Độ phức tạp O(n)

int main() {
    int n, D;
    cin >> n >> D;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int cnt = 0, sum = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        while (j <= n && sum + a[j] <= D) {
            sum += a[j];
            j++;
        }
        cnt += j - i;
        sum -= a[i];
    }

    cout << cnt;
    return 0;
}