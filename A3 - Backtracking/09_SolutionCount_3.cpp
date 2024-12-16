#include <iostream>
#include <vector>

using namespace std;

// ĐỀ BÀI: Đếm số nghiệm nguyên dương x[1..n] của phương trình a[1]x[1] + a[2]x[2] + ... + a[n]x[n] = M (*)

/* ĐẦU VÀO:
 | - Dòng thứ nhất là 2 số nguyên dương n và M.
 | - Dòng thứ hai là n số nguyên dương a[1..n].
 */

// ĐẦU RA: Số lượng các bộ số (x[1], x[2],..., x[n]) thỏa mãn phương trình (*).

/* THUẬT TOÁN: Quy hoạch động.
 | - Bài toán tương đương với tìm số nghiệm nguyên không âm y[1..n] của phương trình:
 |   a[1]y[1] + a[2]y[2] + ... + a[n]y[n] = M - (a[1] + a[2] + ... + a[n])
 | - Gọi s[m] là số nghiệm nguyên không âm của phương trình:
 |   a[1]y[1] + a[2]y[2] + ... + a[n]y[n] = m (gọi là phương trình E(m))
 | - Tồn tại song ánh từ hợp của tập hợp các nghiệm nguyên của các phương trình E(m - a[1]),..., E(m - a[n]) đến E(m)
 | - Nói cách khác, ta có: s[m] = s[m - a[1]] + s[m - a[2]] + ... + s[m - a[n]]
 */

int n, M;
vector<int> a;
vector<int> s;
int sum;

int main()
{
    cin >> n >> M;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    if (M < sum)
    {
        cout << 0;
        return 0;
    }

    s.resize(M + 1);
    s[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= M - sum; j++)
        {
            if (j >= a[i])
                s[j] += s[j - a[i]];
        }
    }
    cout << s[M - sum];
}