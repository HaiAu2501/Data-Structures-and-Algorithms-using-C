#include <bits/stdc++.h>

using namespace std;

// Đếm số dãy các phần tử liên tiếp có tổng >= L và <= U
// Dùng prefixSum -> Độ phức tạp O(n + m) (O(n) để tạo prefixSum, O(m) để trả
// lời m truy vấn)

int main() {
    int n, L, U;
    cin >> n >> L >> U;

    vector<int> a(n + 1), prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }

    int m;  // Số truy vấn
    cin >> m;
    while (m--) {
        int i, j;
        cin >> i >> j;
        int sum = prefix[j] - prefix[i - 1];
        cout << (sum >= L && sum <= U) << '\n';
    }
}