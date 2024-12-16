#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* ĐỀ BÀI: Cho n phần tử x[1..n]
 | - "Khoảng cách" của 1 tập con từ n phần tử là khoảng cách nhỏ nhất giữa 2 phần tử bất kỳ thuộc tập con đó.
 | - Tìm khoảng cách lớn nhất có thể trong các tập con có đúng c phần tử từ n phần tử.
 */

/* ĐẦU VÀO:
 | - Dòng thứ nhất là số lượng test, 1 ≤ T ≤ 20.
 | - Mỗi test gồm 2 dòng:
 |   + Dòng thứ nhất chứa 2 số nguyên n, c (1 ≤ c ≤ n ≤ 100000).
 |   + Dòng thứ hai chứa n số nguyên x[1], x[2], ..., x[n] (1 ≤ x[i] ≤ 10^9).
 */

/* Ý TƯỞNG: TÌM KIẾM NHỊ PHÂN
 | - Gọi f(d) là một hàm kiểm tra xem có thể tìm được tập con có đúng c phần tử mà khoảng cách giữa 2 phần tử bất kỳ >= d.
 | > f(d) đúng thì f(d') cũng đúng với mọi d' < d.
 | > Cần tìm d lớn nhất sao cho f(d) đúng. Và điều này phù hợp với tìm kiếm nhị phân.
 | - Thao tác kiểm tra f(d) có độ phức tạp O(n).
 | - Độ phức tạp: O(n log 10^9 + n log n).
 | - Thuật toán kiểm tra f(d):
 |   + Sắp xếp dãy x.
 |   + Nhận xét: Nếu có tập con thỏa mãn thì có thể thay phần tử nhỏ nhất bởi x[0] vẫn là tập con thỏa mãn.
 |   > Xét các tập có chứa x[0].
 |   + Duyệt qua dãy x, nếu x[i] - (phần tử trước đó) >= d thì tăng biến đếm.
 */

bool f(vector<int> &x, int n, int c, int d)
{
    int count = 1;
    int prev = x[0];
    for (int i = 1; i < n; ++i)
        if (x[i] - prev >= d)
        {
            ++count;
            prev = x[i];
        }

    return count >= c;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, c;
        cin >> n >> c;
        vector<int> x(n);
        for (int &xi : x)
            cin >> xi;

        sort(x.begin(), x.end());

        int l = 0, r = 1e9;
        while (l < r)
        {
            int m = (l + r + 1) / 2;
            if (f(x, n, c, m))
                l = m;
            else
                r = m - 1;
        }

        cout << l << '\n';
    }
}
