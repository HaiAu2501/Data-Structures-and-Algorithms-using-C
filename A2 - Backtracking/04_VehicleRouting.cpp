#include <bits/stdc++.h>

using namespace std;

/*
ĐỀ BÀI (BÀI TOÁN CVRP - CAPACITATED VEHICLE ROUTING PROBLEM)
- Một đội gồm k xe tải với tải trọng Q
- Điểm xuất phát 0, và n khách hàng cần được phục vụ là 1..n
- Mỗi khách hàng i có yêu cầu về số lượng hàng hóa là d[i]
- Các xe tải phải xuất phát từ điểm 0, phục vụ một số khách hàng và quay trở lại điểm 0
- Mỗi khách hàng chỉ được phục vụ bởi 1 xe duy nhất
- Tổng số hàng hóa 1 xe chở không vượt quá Q
- Tìm chi phí nhỏ nhất
 */

/*
Để xây dựng lời giải, ta sẽ sử dụng 2 dãy x và y, trong đó:
- x[i] là điểm đầu tiên mà xe tải i phục vụ, 0 ≤ x[i] ≤ n, 1 ≤ i ≤ K.
  + Nếu x[i] = 0, xe tải i không phục vụ khách hàng nào.
  + Không mất tính tổng quát, có thể giả sử x[1] ≤ x[2] ≤ ... ≤ x[K].
  + Nếu x[i] > 0 thì x[i] < x[i + 1], tức là các x[i] nếu được sử dụng thì chúng phải phân biệt nhau.
- y[i] là điểm tiếp theo được phục vụ sau khi khách hàng i được phục vụ, 0 ≤ y[i] ≤ n, 1 ≤ i ≤ n.
- Chỉ xây dựng dãy y sau khi xây dựng x | Tổng độ dài 2 dãy là n + K.
 */

/*
Các biến khác:
- Mảng visited[1..n] để đánh dấu các khách hàng đã được phục vụ.
- Mảng load[1..K] để lưu trữ số lượng hàng hóa trên xe tải i.
 */

#define MAX 30

int n, K, Q, d[MAX], c[MAX][MAX], cmin = INT_MAX;

int x[MAX], y[MAX], visited[MAX], load[MAX], truck, path, cost, best = INT_MAX;

void TRY_X(int k);
void TRY_Y(int s, int k);

// Thử các giá trị cho x[k]
void TRY_X(int k)
{
    int s = 0;
    if (x[k - 1] > 0)
        s = x[k - 1] + 1;

    for (int v = s; v <= n; v++)
    {
        if (v == 0 || !visited[v])
        {
            x[k] = v;

            if (v > 0)
                path++;

            visited[v] = 1;
            cost += c[0][v];
            load[k] += d[v];

            if (k < K)
                TRY_X(k + 1);
            else
            {
                truck = path;
                TRY_Y(x[1], 1);
            }

            if (v > 0)
                path--;

            visited[v] = 0;
            cost -= c[0][v];
            load[k] -= d[v];
        }
    }
}

// Thử tìm điểm tiếp theo sau điểm s của xe k
void TRY_Y(int s, int k)
{
    if (s == 0)
    {
        if (k < K)
            TRY_Y(x[k + 1], k + 1);
        return;
    }

    for (int v = 0; v <= n; v++)
    {
        if (v == 0 || (!visited[v] && load[k] + d[v] <= Q))
        {
            y[s] = v;

            visited[v] = 1;
            cost += c[s][v];
            load[k] += d[v];
            path++;

            if (v > 0)
            {
                if (cost + cmin * (n + truck - path) < best)
                    TRY_Y(v, k);
            }
            else
            {
                if (k == K)
                {
                    if (path == n + truck)
                        best = min(cost, best);
                }
                else if (cost + cmin * (n + truck - path) < best)
                    TRY_Y(x[k + 1], k + 1);
            }

            visited[v] = 0;
            cost -= c[s][v];
            load[k] -= d[v];
            path--;
        }
    }
}

int main()
{
    cin >> n >> K >> Q;

    for (int i = 1; i <= n; i++)
        cin >> d[i];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> c[i][j];
            if (i != j)
                cmin = min(cmin, c[i][j]);
        }
    }

    TRY_X(1);
    cout << best;
}
