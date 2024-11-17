#include <iostream>
#include <vector>

using namespace std;

// Tìm dãy con chung dài nhất

/* INPUT:
 | - Dòng đầu tiên chứa 2 số nguyên dương n, m (1 ≤ n, m ≤ 1000) - độ dài 2 dãy số.
 | - Dòng thứ hai chứa n số nguyên a1, a2, ..., an (1 ≤ ai ≤ 1000) - dãy số thứ nhất.
 | - Dòng thứ ba chứa m số nguyên b1, b2, ..., bm (1 ≤ bi ≤ 1000) - dãy số thứ hai.
 */

/* OUPUT:
 | - Độ dài dãy con chung dài nhất của 2 dãy số.
 */

/* Ý TƯỞNG: 
 | - Xây dựng bảng c[i][j] là độ dài dãy con chung dài nhất của 2 dãy a[1..i] và b[1..j].
 | - Nếu a[i] = b[j], c[i][j] = c[i-1][j-1] + 1.
 | - Nếu a[i] != b[j], c[i][j] = max(c[i-1][j], c[i][j-1]).
 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int &ai : a)
        cin >> ai;
    for (int &bi : b)
        cin >> bi;

    vector<vector<int>> c(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
        }
    }

    cout << c[n][m];
}