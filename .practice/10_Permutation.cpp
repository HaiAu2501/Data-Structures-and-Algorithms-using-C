#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* ĐỀ BÀI: Sinh dãy hoán vị của n số nguyên dương đầu tiên theo thứ tự từ điển.
 | Ví dụ: n = 3
 | In ra:
 | 1 2 3
 | 1 3 2
 | 2 1 3
 | 2 3 1
 | 3 1 2
 | 3 2 1
 */

/* Trong thư viện STL của C++ đã có sẵn hàm next_permutation() để sinh hoán vị tiếp theo.
 | - next_permutation(a.begin(), a.end()) sẽ sinh ra hoán vị tiếp theo của dãy a.
 | - Nếu dãy a đã là hoán vị cuối cùng thì hàm trả về false.
 */

int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    do
    {
        for (int i = 0; i < n; ++i)
            cout << a[i] << ' ';
        cout << '\n';
    } while (next_permutation(a.begin(), a.end()));
}