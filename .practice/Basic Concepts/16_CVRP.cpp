#include <iostream>

using namespace std;

/* ĐỀ BÀI (BÀI TOÁN CVRP - CAPACITATED VEHICLE ROUTING PROBLEM)
 | - Một đội gồm k xe tải với sức chứa tối đa Q.
 | - Điểm xuất phát 0, và n khách hàng cần được phục vụ là 1..n.
 | - Mỗi khách hàng i có yêu cầu về số lượng hàng hóa là d[i].
 | - Các xe tải phải xuất phát từ điểm 0, phục vụ một số khách hàng và quay trở lại điểm 0.
 | - Mỗi khách hàng chỉ được phục vụ bởi 1 xe duy nhất.
 | - Tổng số hàng hóa 1 xe chở không vượt quá Q.
 | - Tìm chi phí nhỏ nhất.
 */

/* ĐẦU VÀO:
 | - Dòng đầu tiên chứa 3 số nguyên n, k, Q (1 ≤ n ≤ 100, 1 ≤ k ≤ 10, 1 ≤ Q ≤ 1000).
 | - Dòng tiếp theo chứa n số nguyên d[1], d[2], ..., d[n] (1 ≤ d[i] ≤ 100).
 | - n dòng tiếp theo, mỗi dòng chứa n + 1 số nguyên c[i][0], c[i][1], ..., c[i][n] (0 ≤ c[i][j] ≤ 1000).
 */

/* ĐẦU RA:
 | - In ra chi phí nhỏ nhất.
 */

#define MAX 200

int n, K, Q;
int d[MAX];
int c[MAX][MAX];

bool visited[MAX];
int load[MAX];
int x[MAX], y[MAX];

int cost;
int minCost = 1e9;

int truck;
int path;

/* Để xây dựng lời giải, ta sẽ sử dụng 2 dãy x và y, trong đó:
 | - x[i] là điểm đầu tiên mà xe tải i phục vụ, 0 ≤ x[i] ≤ n, 1 ≤ i ≤ K.
 |   + Nếu x[i] = 0, xe tải i không phục vụ khách hàng nào.
 |   + Không mất tính tổng quát, có thể giả sử x[1] ≤ x[2] ≤ ... ≤ x[K].
 |   + Nếu x[i] > 0 thì x[i] < x[i + 1], tức là các x[i] nếu được sử dụng thì chúng phải phân biệt nhau.
 | - y[i] là điểm tiếp theo được phục vụ sau khi khách hàng i được phục vụ, 0 ≤ y[i] ≤ n, 1 ≤ i ≤ n.
 | - Chỉ xây dựng dãy y sau khi xây dựng x.
 | - Tổng độ dài 2 dãy là (K + n).
 */

/* Các biến khác:
 | - Mảng visited[1..n] để đánh dấu các khách hàng đã được phục vụ.
 | - Mảng load[1..K] để lưu trữ số lượng hàng hóa trên xe tải i.
 | - truck để đếm số xe tải đã được sử dụng.
 | - path để đếm số cạnh của lời giải (nếu path = n + truck thì lời giải hoàn chỉnh).
 */

// Điền dãy x trước

// Kiểm tra xem x[k] = v có thỏa mãn hay không
bool CHECK_X(int v, int k)
{
    if (visited[v])
        return false;
    return true;
}

void TRY_X(int k)
{
    for (int v = 0; v <= n; v++)
    {
        if (CHECK_X(v, k))
        {
            x[k] = v;
            if (v > 0)
            {
                path++;
                load[k] += d[v];
                cost += c[0][v];
                visited[v] = true;
            }

            if (k < K)
                TRY_X(k + 1);
            else
            {
                truck = path;
                TRY_Y(1);
            }

            if (v > 0)
            {
                path--;
                load[k] -= d[v];
                cost -= c[0][v];
                visited[v] = false;
            }
        }
    }
}

bool CHECK_Y(int v, int k)
{
    if (v > 0 && visited[v])
        return false;
    if (load[k] + d[v] > Q)
        return false;
    return true;
}

void TRY_Y(int k)
{
}

int main()
{
    cin >> n >> K >> Q;

    for (int i = 1; i <= n; i++)
        cin >> d[i];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            cin >> c[i][j];

    TRY_X(1);

    cout << minCost;

    return 0;
}
