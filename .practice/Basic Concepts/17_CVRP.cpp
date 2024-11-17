#include <iostream>
#include <vector>

using namespace std;

/* ĐỀ BÀI: Một đội gồm k xe tải giống nhau cần được phân công để vận chuyển hàng từ kho (điểm 0) đến các điểm 1..N và quay về.
 | - Khoảng cách di chuyển giữa điểm i và j là c(i, j).
 | - Mỗi xe tải có tải trọng Q (mỗi chuyến chỉ được chở tối đa Q thùng hàng).
 | - Mỗi điểm i có một lượng hàng cần chuyển là q(i).
 | - Cần xây dựng phương án vận chuyển sao cho:
 |   + Mỗi xe tải chỉ được phân công một chuyến duy nhất.
 |   + Mỗi chuyến phải xuất phát từ kho và quay về kho.
 |   + Tổng lượng hàng chuyển trên mỗi xe tải không vượt quá Q.
 |   + Tổng chi phí vận chuyển là nhỏ nhất.
 */

/* INPUT:
 | - Dòng 1: n, K, Q
 | - Dòng 2: q[1..n]
 | - n + 1 dòng tiếp theo là ma trận trọng số
 */

int n, K, Q;
vector<int> q;
vector<vector<int>> c;

vector<int> x;
vector<int> y;

// Các biến của phương án địa phương
vector<bool> visited;
vector<int> load;
int cost = 0;
int best = INT_MAX;

/* Các biến:
 | - y[k]: điểm giao đầu tiên của xe thứ k (0 <= y[k] <= n, k = 1..K).
 | - x[i]: điểm tiếp theo của điểm giao i trên lộ trình (0 <= x[i] <= n, i = 1..N).
 | - Do các xe giống nhau nên KMTTQ, giả sử y[k] <= y[k + 1].
 */

bool CHECK(int v, int k)
{
    return true;
}

/*
 | - Bắt đầu bằng việc duyệt bộ giá trị cho y[1..k].
 | - Với mỗi bộ giá trị đầy đủ của y[1..k], bắt đầu duyệt giá trị cho x.
 */
void TRY(int k)
{
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> K >> Q;
    q.resize(n);
    c.resize(n + 1, vector<int>(n + 1));

    for (int &x : q)
        cin >> x;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
            cin >> c[i][j];
    }

    x.resize(n + 1);
    y.resize(K);
    load.resize(K);
}