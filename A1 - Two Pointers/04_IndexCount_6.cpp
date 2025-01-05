#include <bits/stdc++.h>

using namespace std;

// Đếm số bộ (i, j, k) mà i < j < k và a[i] < a[j] < a[k]

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &ai : a) cin >> ai;

    int res = 0;
    for (int i = 0; i < n; i++) {
        int cnt1 = 0, cnt2 = 0;
        for (int j = 0; j < i; j++)
            if (a[j] < a[i]) cnt1++;
        for (int j = i + 1; j < n; j++)
            if (a[j] > a[i]) cnt2++;
        res += cnt1 * cnt2;
    }

    cout << res;
    return 0;
}