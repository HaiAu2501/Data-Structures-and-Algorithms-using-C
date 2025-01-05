#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Đếm số chỉ số i < j < k mà a[i], a[j], a[k] tạo thành 1 cấp số cộng
// a[j] - a[i] = a[k] - a[j] -> a[i] + a[k] = 2 * a[j]

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &ai : a) cin >> ai;

    unordered_map<ll, ll> freqRight;
    for (ll &ai : a) freqRight[ai]++;

    ll ans = 0;
    for (int j = 0; j < n; j++) {
        freqRight[a[j]]--;
        for (int i = 0; i < j; i++) {
            ll need = 2 * a[j] - a[i];
            if (freqRight.find(need) != freqRight.end()) ans += freqRight[need];
        }
    }
    cout << ans;
    return 0;
}