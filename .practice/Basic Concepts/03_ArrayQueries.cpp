#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/* ĐỀ BÀI: Nhập vào 1 dãy số nguyên a[1..n]. Trả lời các truy vấn sau:
 | - find-max: phần tử lớn nhất trong dãy
 | - find-min: phần tử nhỏ nhất trong dãy
 | - sum: tổng các phần tử của dãy
 | - find-max-segment i j: phần tử lớn nhất trong dãy con a[i..j]
 */

/* ĐẦU VÀO:
 | - Dòng 1 là số nguyên dương n (1 <= n <= 1000)
 | - Dòng 2 gồm n số nguyên a[1..n] (- 1000 <= a[i] <= 1000)
 | - Kết thúc bởi dấu *
 | - Mỗi dòng tiếp theo là 1 truy vấn
 | - Kết thúc bởi dấu ***
 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);

    int MAX = -1001;
    int MIN = 1001;
    int sum = 0;

    for (int &x : a)
    {
        cin >> x;
        if (x > MAX)
            MAX = x;
        if (x < MIN)
            MIN = x;
        sum += x;
    }

    // Tạo bảng log2 để tránh việc tính log2 mỗi lần
    vector<int> log2_table(n + 1);
    log2_table[1] = 0;
    for (int i = 2; i <= n; i++)
        log2_table[i] = log2_table[i / 2] + 1;

    string s;

    cin >> s;

    /* THUẬT TOÁN SPARSE TABLE:
     | - Gọi M[i][j] là số lớn nhất trong dãy a[i..i + 2^j - 1] (độ dài 2^j)
     | - M[i][0] là số lớn nhất trong dãy a[i..i], tức là M[i][0] = a[i]
     | - Với j > 0, chia dãy a[i..i + 2^j - 1] thành 2 dãy có độ dài 2^(j - 1) là a[i..i + 2^(j-1) - 1], và a[i + 2^(j - 1)..i+ 2^j - 1]
     | -> Công thức truy hồi M[i][j] = max(M[i][j - 1], M[i + 2^(j - 1)][j - 1])
     | - Để tìm số lớn nhất trong dãy con a[i..j], chia dãy này thành 2 dãy con có độ dài 2^k với k = [log2(j - i + 1)]
     | -> Số lớn nhất trong dãy a[i][j] là max(M[i][k], M[j - 2^k + 1][k])
     */

    vector<vector<int>> M(n, vector<int>(log2_table[n] + 1));

    for (int i = 0; i < n; i++)
        M[i][0] = a[i];

    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 0; i + (1 << j) - 1 < n; i++)
            M[i][j] = max(M[i][j - 1], M[i + (1 << (j - 1))][j - 1]);
    }

    while (true)
    {
        cin >> s;
        if (s == "***")
            break;
        if (s == "find-max")
            cout << MAX << endl;
        if (s == "find-min")
            cout << MIN << endl;
        if (s == "sum")
            cout << sum << endl;
        if (s == "find-max-segment")
        {
            int i, j;
            cin >> i >> j;
            i--;
            j--;
            int k = log2_table[j - i + 1];
            cout << max(M[i][k], M[j - (1 << k) + 1][k]) << endl;
        }
    }
}