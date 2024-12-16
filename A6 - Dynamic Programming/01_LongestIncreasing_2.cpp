#include <bits/stdc++.h>

using namespace std;

// Tìm dãy con tăng dài nhất.
// Sử dụng mạng phụ lis để lưu dãy con tăng dài nhất, kết hợp tìm kiếm nhị phân.
// Độ phức tạp: O(nlogn)

const int MAX = 1e6;

int n, a[MAX];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> lis;
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(lis.begin(), lis.end(), a[i]);
        if (it == lis.end())
            lis.push_back(a[i]);
        else
            *it = a[i];
    }

    cout << lis.size();
}