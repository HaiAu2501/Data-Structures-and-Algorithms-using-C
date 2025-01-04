#include <bits/stdc++.h>

using namespace std;

// Tìm dãy các phần tử liên tiếp tăng dài nhất -> Độ phức tạp O(n)

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &ai : a)
        cin >> ai;

    int l = -1;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j < n - 1 && a[j] < a[j + 1])
            j++;
        l = max(l, j - i + 1);
        i = j;
    }

    // Cài đặt ngắn hơn:
    // int l = 1;
    // for (int i = 0; i < n; i++)
    // {
    //     if (a[i] < a[i + 1])
    //         l++;
    //     else
    //         l = 1;
    // }

    cout << l;
}