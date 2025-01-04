#include <bits/stdc++.h>

using namespace std;

// Dãy con các phần tử liên tiếp có tính chẵn lẻ đan xen -> Độ phức tạp O(n)

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
        while (j < n - 1 && a[j] % 2 != a[j + 1] % 2)
            j++;
        l = max(l, j - i + 1);
        i = j;
    }

    if (l == 1)
        cout << 0;
    else
        cout << l;
}