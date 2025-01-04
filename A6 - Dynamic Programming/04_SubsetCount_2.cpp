#include <iostream>
#include <vector>

using namespace std;

// Đếm số tập con của 1 tập n phần tử và tổng lớn hơn k cho trước

int n, k;

int main()
{
    cin >> n;
    vector<int> a(n);
    for (int &ai : a)
        cin >> ai;

    cin >> k;

    // Sử dụng vét cạn bằng bit mask
    int ans = 0;

    for (int mask = 0; mask < (1 << n); ++mask)
    {
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            if (mask & (1 << i))
                sum += a[i];
        }
        if (sum >= k)
            ++ans;
    }

    cout << ans;
}