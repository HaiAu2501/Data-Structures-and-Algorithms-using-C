#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/* ĐỀ BÀI: Cho một dãy ngoặc chỉ có '(' và ')'.
 | - Tìm độ dài dãy con ngoặc hợp lệ dài nhất.
 | - Ví dụ: "(()" có dãy con hợp lệ dài nhất là "()" với độ dài là 2.
 */

/* ĐẦU VÀO: Chỉ 1 dòng chứa xâu s có độ dài không quá 10^6.
 */

/* ĐẦU RA: Độ dài dãy con ngoặc hợp lệ dài nhất.
 */

/* Ý TƯỞNG: Quy hoạch động
 | - Gọi f[i] là độ dài dãy con ngoặc hợp lệ dài nhất kết thúc tại vị trí i.
 | - Nếu s[i] = '(', f[i] = 0.
 | - Nếu s[i] = ')', nếu s[i - 1] = '(', f[i] = f[i - 2] + 2.
 | - Nếu s[i] = ')', nếu s[i - 1] = ')' và s[i - f[i - 1] - 1] = '(', f[i] = f[i - 1] + f[i - f[i - 1] - 2] + 2.
 */

string s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;

    int n = s.length();
    s = " " + s;
    int res = 0;
    vector<int> f(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (s[i] == ')')
        {
            if (s[i - 1] == '(')
                f[i] = f[i - 2] + 2;
            else if (s[i - 1] == ')' && s[i - f[i - 1] - 1] == '(')
                f[i] = f[i - 1] + f[i - f[i - 1] - 2] + 2;
            res = max(res, f[i]);
        }
    }

    cout << res;
}