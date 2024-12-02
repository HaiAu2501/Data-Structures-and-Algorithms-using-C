#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

/* ĐỀ BÀI: Cho 2 dãy a[1..n] và b[1..n].
 | - Các phần tử của a đôi một khác nhau.
 | - Đếm số cách sắp xếp lại dãy a sao cho a[i] > b[i] với mọi i.
 */

/* Ý TƯỞNG:
 | - NHẬN XÉT: Nếu sắp xếp lại dãy b thì kết quả không đổi.
 | - Ta sẽ sắp xếp mảng b theo thứ tự tăng dần.
 | - Lần lượt lựa chọn giá trị cho a[n], a[n - 1], ..., a[1].
 | - Gọi S[i] là số chỉ số k sao cho a[k] > b[i].
 | - Cách chọn cho phần tử a[i] là S[i] - (n - i), vì đã chọn (n - i) phần tử trước đó cho a[n], a[n - 1], ..., a[i + 1].
 | - Phần tử a > b[n] >= b[n - 1] nên cũng thỏa mãn cho vị trí n - 1.
 */

int n;

const int MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<int> a(n), b(n);
    for (int &ai : a)
        cin >> ai;
    sort(a.begin(), a.end());
    for (int &bi : b)
        cin >> bi;
    sort(b.begin(), b.end());

    ll ans = 1;
    for (int i = n - 1; i >= 0; --i)
    {
        int c = (a.end() - upper_bound(a.begin(), a.end(), b[i])) + 1; // S[i]
        ans = ans * max(0, c - (n - i)) % MOD;
    }
    cout << ans;
    return 0;
}