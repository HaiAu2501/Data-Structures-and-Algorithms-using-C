#include <bits/stdc++.h>

using namespace std;

#define ll long long

/* ĐỀ BÀI:
- Một số ô chứa phần thưởng.
- Xuất phát từ điểm (0, 0), đi qua các điểm (x, y) sao cho không giảm theo cả 2 chiều.
- Tìm tổng phần thưởng lớn nhất có thể nhận được.
 */

struct Point
{
    int x, y;
    ll c;
};

int main()
{
    int n;
    cin >> n;
    vector<Point> a(n);

    for (Point &ai : a)
        cin >> ai.x >> ai.y >> ai.c;

    // Sort dãy điểm trên theo thứ tự tăng dần của x; nếu x bằng nhau thì sắp xếp theo y
    // Gọi dp[i] là tổng phần thưởng lớn nhất có thể nhận được khi đi đến điểm i
    // -> dp[i] = max(dp[j] + c[i]) với j < i và x[j] <= x[i] và y[j] <= y[i]
    vector<ll> dp(n);

    sort(a.begin(), a.end(), [](Point A, Point B)
         { return A.x < B.x || (A.x == B.x && A.y < B.y); });

    for (int i = 0; i < n; i++)
    {
        dp[i] = a[i].c;
        for (int j = 0; j < i; j++)
            if (a[j].x <= a[i].x && a[j].y <= a[i].y)
                dp[i] = max(dp[i], dp[j] + a[i].c);
    }

    cout << *max_element(dp.begin(), dp.end());
}