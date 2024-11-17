#include <iostream>
#include <algorithm>

using namespace std;

/* ĐỀ BÀI: Cho n thành phố và ma trận chi phí giữa các thành phố.
 | Tìm đường đi ngắn nhất qua tất cả các thành phố mà không đi qua 1 thành phố nào 2 lần và quay về thành phố xuất phát.
 */

/* ĐẦU VÀO:
 | - Dòng đầu tiên chứa số nguyên n (2 ≤ n ≤ 10).
 | - n dòng tiếp theo, mỗi dòng chứa n số nguyên không âm, số thứ j trên dòng thứ i là chi phí đi từ thành phố i đến thành phố j (0 ≤ a[i][j] ≤ 1000).
 */

/* ĐẦU RA:
 | - In ra chi phí nhỏ nhất để đi qua tất cả các thành phố mà không đi qua 1 thành phố nào 2 lần và quay về thành phố xuất phát.
 */

/* Ý TƯỞNG:
 | - Cách 1: Sử dụng thuật toán backtracking để thử tất cả các cách đi qua các thành phố.
 | - Cách 2: Sử dụng thuật toán nhánh cận để giảm bớt số lượng trường hợp cần xét.
 | - Cách 3: Sử dụng thuật toán quy hoạch động để giải bài toán.
 */

#define MAX 10

/* - n: số lượng thành phố
 | - a: ma trận chi phí
 | - x: đường đi
 | - visited: mảng đánh dấu thành phố đã đi qua
 | - cost: chi phí hiện tại
 | - minCost: chi phí nhỏ nhất
 */
int n, a[MAX][MAX], x[MAX] = {0}, visited[MAX] = {1}, cost, minCost = 1e9;

/* - Vì vai trò bình đẳng, ta có thể coi như x[0] = 0
 | - Thực hiện thử x[1..n - 1]
 */

void TRY(int k)
{
    for (int v = 1; v < n; v++)
    {
        if (visited[v] == 0) // Đóng vai trò như hàm CHECK
        {
            x[k] = v;
            visited[v] = 1;
            cost += a[x[k - 1]][v];

            if (k == n - 1)
            {
                cost += a[v][0];
                if (cost < minCost)
                    minCost = cost;
                cost -= a[v][0];
            }
            else
                TRY(k + 1);

            visited[v] = 0;
            cost -= a[x[k - 1]][v];
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }

    TRY(1);

    cout << minCost;

    return 0;
}
