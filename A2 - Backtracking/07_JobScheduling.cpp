#include <bits/stdc++.h>

using namespace std;

// Cho danh sách n việc và K người. Tìm thời gian nhỏ nhất để hoàn thành.

#define MAX 15

int n, K, jobs[MAX], low = INT_MIN, hight;

int t[MAX], best = INT_MAX;

// Phân công công việc thứ k
bool TRY(int k, int T)
{
    if (k > n)
        return true;

    for (int i = 1; i <= K; i++)
    {
        if (t[i] + jobs[k] <= T)
        {
            t[i] += jobs[k];
            if (TRY(k + 1, T))
                return true;
            t[i] -= jobs[k];
        }
        if (t[i] == 0)
            break;
    }
    return false;
}

// Kiểm tra xem có thể phân chia các công việc cho K người, mỗi người không quá T
bool CHECK(int T)
{
    fill(t + 1, t + K + 1, 0);
    return TRY(1, T);
}

int main()
{
    cin >> n >> K;
    for (int i = 1; i <= n; i++)
    {
        cin >> jobs[i];
        low = max(low, jobs[i]);
        hight += jobs[i];
    }

    while (low < hight)
    {
        int mid = (low + hight) / 2;
        if (CHECK(mid))
            hight = mid;
        else
            low = mid + 1;
    }

    cout << low;
}