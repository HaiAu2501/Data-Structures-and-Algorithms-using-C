#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000007

// Cho dãy a[1..n], đếm cặp số 1 ≤ i < j ≤ n mà a[i] = a[j]

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &ai : a) cin >> ai;

    long long ans = 0;
    sort(a.begin(), a.end());

    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && a[j] == a[i]) ++j;
        ans += (long long)(j - i) * (j - i - 1) / 2;
        i = j;
    }

    cout << ans % MOD;
}