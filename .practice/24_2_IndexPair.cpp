#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Cho dãy a[1..n], đếm số cặp số (i, j) mà a[i] = a[j]

/* Ý TƯỞNG:
 | - Sử dụng mảng freq để đếm số lần xuất hiện của mỗi phần tử trong dãy a.
 | - Số cặp số (i, j) mà a[i] = a[j] chính là tổ hợp chập 2 của số lần xuất hiện của phần tử đó.
 */

typedef long long ll;

#define MOD 1000000007

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, ll> freq;

    for (int &x : a)
    {
        cin >> x;
        freq[x]++;
    }

    ll ans = 0;
    for (auto &pair : freq)
    {
        ll k = pair.second;
        ans += k * (k - 1) / 2;
        ans %= MOD;
    }

    cout << ans;
}