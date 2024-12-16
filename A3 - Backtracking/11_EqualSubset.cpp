#include <bits/stdc++.h>

using namespace std;

// Cho tập n số và số K. Xem có thể chia tập thành k tập con bằng nhau không?

#define MAX 30

int n, K, a[MAX], sum = 0;

// Lưu tổng của từng tập
int bucket[MAX];

// Thử thêm số thứ k vào các tập
bool TRY(int k)
{
    if (k > n)
    {
        for (int i = 1; i <= K; i++)
        {
            if (bucket[i] != sum)
                return false;
        }
        return true;
    }

    for (int i = 1; i <= K; i++)
    {
        if (bucket[i] + a[k] > sum)
            continue;

        bucket[i] += a[k];
        if (TRY(k + 1))
            return true;

        bucket[i] -= a[k];
        if (bucket[i] == 0)
            break;
    }
    return false;
}

int main()
{
    cin >> n >> K;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % K != 0)
    {
        cout << -1;
        return 0;
    }

    sum /= K;
    sort(a + 1, a + n + 1, greater<int>());
    if (a[1] > sum)
    {
        cout << -1;
        return 0;
    }

    if (TRY(1))
        cout << 1;
    else
        cout << -1;
}