#include <bits/stdc++.h>

using namespace std;

// Đếm số bộ (i, j, k) khác nhau mà tổng 2 trong 3 số bằng số còn lại

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int &x : a) cin >> x;

    sort(a.begin(), a.end(), greater<int>());

    int cnt = 0;
    for (int i = 0; i < n - 2; i++) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            if (a[l] + a[r] == a[i]) {
                cnt++;
                l++;
                r--;
            } else if (a[l] + a[r] < a[i])
                r--;
            else
                l++;
        }
    }

    cout << cnt;
}