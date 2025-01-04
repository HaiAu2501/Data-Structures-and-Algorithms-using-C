#include <bits/stdc++.h>

using namespace std;

// Tìm mảng con (dãy liên tiếp các phần tử) có tổng lớn nhất.
// Thuật toán Kadane - Độ phức tạp: O(n)

// Nếu tìm dãy không liên tiếp thì bài toán tầm thường
// Vì chỉ cần chọn các phần tử dương

int main()
{
    int n;
    cin >> n;
    int maxSum = INT_MIN, sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum = max(x, sum + x);
        maxSum = max(maxSum, sum);
    }

    cout << maxSum;
}
