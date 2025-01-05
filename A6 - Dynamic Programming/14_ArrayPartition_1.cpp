#include <bits/stdc++.h>

using namespace std;

#define M 21
#define N 100006

// Chia mảng a[1..n] thành K đoạn sao cho chênh lệch giữa tổng lớn nhất và nhỏ
// nhất là nhỏ nhất

int n, K;
int a[M];  // 1 = a[0] < a[1] < ... < a[K - 1] < a[K] = n là các điểm chia =>
           // a[k - 1] < a[k] <= n - K + k
int s[M];       // s[i] = sum(f[a[i - 1]..a[i] - 1])
int prefix[N];  // prefix[i] = sum(f[1..i])
int dist;
int best = INT_MAX;

void TRY(int k) {
    if (k > K - 1) {
        dist = INT_MAX;
        s[K] = prefix[n] - prefix[a[K - 1] - 1];
        sort(s + 1, s + K + 1);
        dist = s[K] - s[1];
        best = min(best, dist);
        return;
    }

    int minV = a[k - 1] + 1, maxV = n - K + k;
    for (int v = minV; v <= maxV; v++) {
        a[k] = v;
        s[k] = prefix[v - 1] - prefix[a[k - 1] - 1];
        TRY(k + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> K;

    vector<int> f(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
        prefix[i] = prefix[i - 1] + f[i];
    }

    a[0] = 1, a[K] = n;
    TRY(1);

    cout << best;

    return 0;
}