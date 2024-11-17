#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Tìm dãy con tăng dài nhất của mảng a[1..n] (dãy con là dãy các phần tử không nhất thiết liên tiếp có chỉ số tăng dần).

/* ĐẦU VÀO:
 | - Dòng đầu tiên chứa số nguyên n (1 ≤ n ≤ 10^5) - số phần tử của mảng a.
 | - Dòng thứ hai chứa n số nguyên a1, a2, ..., an (1 ≤ ai ≤ 10^9) - mảng a.
 */

/* ĐẦU RA:
 | - In ra độ dài dãy con tăng dài nhất của mảng a.
 */

/* Ý TƯỞNG:
 | - Sử dụng thuật toán Quy hoạch động.
 | - Gọi s[i] là độ dài dãy con tăng dài nhất của mảng a[1..i] kết thúc bởi a[i].
 | - Nếu a[i] > a[j] (1 ≤ j < i) thì s[i] = max(s[i], s[j] + 1).
 | - Kết quả là max(s[1], s[2], ..., s[n]).
 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &ai : a)
        cin >> ai;

    vector<int> s(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
                s[i] = max(s[i], s[j] + 1);
        }
    }

    cout << *max_element(s.begin(), s.end());
}