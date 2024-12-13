#include <bits/stdc++.h>

using namespace std;

// Đếm số tập con có tổng bằng s

int n, s, cnt = 0, sum = 0;
vector<int> a;

void TRY(int k)
{
    for (int v = 0; v < 2; v++)
    {
        sum += v * a[k];
        if (k == n - 1)
        {
            if (sum == s)
                cnt++;
        }
        else
            TRY(k + 1);
        sum -= v * a[k];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    a.resize(n);
    for (int &ai : a)
        cin >> ai;

    TRY(0);
    cout << cnt << '\n';
}
