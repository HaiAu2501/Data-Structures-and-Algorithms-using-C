#include <iostream>
#include <vector>

using namespace std;

/* ĐỀ BÀI: Cho hình chữ nhật n x m, mỗi ô được tô màu đen hoặc trắng.
 | Tìm diện tích hình chữ nhật con lớn nhất màu đen.
 */

/* ĐẦU VÀO:
 | - Dòng đầu tiên chứa 2 số nguyên n, m (1 ≤ n, m ≤ 1000).
 | - n dòng tiếp theo, mỗi dòng chứa m số 0 hoặc 1, số 0 nếu ô tương ứng màu trắng, số 1 nếu ô tương ứng màu đen.
 */

/* ĐẦU RA: In ra diện tích hình chữ nhật con lớn nhất màu đen.
 */

/* Ý TƯỞNG - CÁCH 1: VÉT CẠN
 | - Duyệt qua tất cả các hình chữ nhật con bắt đầu từ (r1, c1) đến (r2, c2).
 | - Xem xem có ô nào màu trắng không, nếu có thì không cần xét hình chữ nhật đó.
 | - Độ phức tạp: O(n^3 * m^3).
 */

int n, m;

int main()
{
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &ai : a)
        for (int &x : ai)
            cin >> x;

    int ans = 0;
    for (int r1 = 0; r1 < n; ++r1)
        for (int c1 = 0; c1 < m; ++c1)
            for (int r2 = r1; r2 < n; ++r2)
                for (int c2 = c1; c2 < m; ++c2)
                {
                    bool ok = true;
                    for (int i = r1; i <= r2; ++i)
                        for (int j = c1; j <= c2; ++j)
                            if (a[i][j] == 0)
                            {
                                ok = false;
                                break;
                            }
                    if (ok)
                        ans = max(ans, (r2 - r1 + 1) * (c2 - c1 + 1));
                }

    cout << ans;
}