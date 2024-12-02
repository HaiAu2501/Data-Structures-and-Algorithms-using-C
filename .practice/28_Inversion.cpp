#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

// ĐỀ BÀI: Đếm số lượng cặp số (i, j) mà a[i] > a[j] và i < j.

/* ĐẦU VÀO:
 | - Dòng đầu tiên chứa số nguyên n (1 ≤ n ≤ 10^6).
 | - Chứa n số nguyên a[1], a[2], ..., a[n] (0 ≤ a[i] ≤ 10^6).
 */

/* Ý TƯỞNG:
 | - Sử dụng thuật toán Merge Sort để đếm số nghịch thế.
 | - Chia mảng thành 2 nửa, đệ quy đếm số nghịch thế của 2 nửa.
 | - Đếm số nghịch thế khi trộn 2 nửa lại với nhau.
 | - Độ phức tạp: O(n log n).
 */

const int MOD = 1e9 + 7;

ll mergeCount(vector<int> &a, int l, int r)
{
    if (l >= r)
        return 0;
    int m = (l + r) / 2; // l + (r - l) / 2
    ll count = mergeCount(a, l, m) + mergeCount(a, m + 1, r);

    // Hợp nhất và đếm số nghịch thế
    int i = l;
    int j = m + 1;

    vector<int> temp; // Để lưu dãy a sắp xếp từ việc hợp nhất 2 nửa

    while (i <= m && j <= r)
    {
        if (a[i] <= a[j])
        {
            // Đúng thứ tự, nên thêm a[i] vào temp và tăng i
            temp.push_back(a[i++]);
        }
        else
        {
            // Chưa đúng thứ tự, nên thêm a[j] vào temp, tăng j và từ i đến mid ghép với j là các cặp nghịch thế
            temp.push_back(a[j++]);
            count += (m - i + 1);
        }
    }
    while (i <= m)
        temp.push_back(a[i++]);
    while (j <= r)
        temp.push_back(a[j++]);

    for (int k = l; k <= r; k++)
        a[k] = temp[k - l];

    return count;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    ll ans = mergeCount(a, 0, n - 1);

    cout << ans % MOD;

    return 0;
}
