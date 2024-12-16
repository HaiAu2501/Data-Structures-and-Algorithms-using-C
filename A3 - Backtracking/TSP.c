#include <stdio.h>
#include <stdlib.h>

/* THUẬT TOÁN NHÁNH VÀ CẬN (BRANCH AND BOUND):
 | - Một trong những phương pháp giải bài toán tối ưu tổ hợp.
 | - Dùng kĩ thuật quay lui để liệt kê tất cả các giải pháp rồi chọn ra giải pháp tối ưu nhất.
 | - Dùng đánh giá cận để cắt bỏ không gian tìm kiếm không cần thiết.
 */

/* ĐỀ BÀI (TRAVELLING SALESMAN PROBLEM - TSP, BÀI TOÁN NGƯỜI DU LỊCH):
 | - Một người du lịch muốn đi tham quan n thành phố 1, 2, ..., n.
 | - Hành trình là cách đi xuất phát từ một thành phố, đi qua mỗi thành phố đúng 1 lần rồi trở về thành phố xuất phát.
 | - Mỗi cặp thành phố i, j có một chi phí c_ij để đi trực tiếp từ i đến j.
 | - Yêu cầu: Tìm hành trình với tổng chi phí nhỏ nhất.
 */

/* THAM SỐ:
 | - Đầu vào: n là số lượng thành phố và cost là ma trận kích thước n x n chứa chi phí giữa các cặp thành phố.
 | - Đầu ra: chi phí nhỏ nhất của hành trình.
 */

/* NHẬN XÉT:
 | - Không mất tính tổng quát, giả sử thành phố xuất phát là x[1] = 1.
 | -> Dãy các thành phố cần đi qua: 2, 3, ..., n; có tất cả (n - 1)! hành trình.
 | - Mỗi hành trình tương ứng với một hoán vị của (n - 1) số nguyên 2, 3, ..., n.
 | - Với hành trình x = (1, x[2], x[3], ..., x[n]), chi phí của hành trình là:
 |   cost[1][x[2]] + cost[x[2]][x[3]] + ... + cost[x[n - 1]][n] + cost[n][1].
 */

// Các biến toàn cục
int n; // minCost: chi phí nhỏ nhất của hành trình
int minCost = INT_MAX;
int *x, *path, *visited, **cost; // x: mảng chứa hoán vị, path: mảng chứa hành trình tối ưu, visited: mảng đánh dấu thành phố đã đi qua, totalCost: tổng chi phí của hành trình
int totalCost = 0;

// Hàm in ra hành trình
void printPath()
{
    for (int i = 0; i < n; i++)
        printf("%d -> ", path[i]);
    printf("1\n");
}

/* THUẬT TOÁN VÉT CẠN (BRUTE FORCE) DUYỆT TOÀN BỘ CÁC HÀNH TRÌNH: -> Độ phức tạp thời gian: O((n - 1)!)
 | - Sử dụng cấu trúc chung của Backtracking.
 | - Sử dụng mảng visited để đánh dấu thành phố đã đi qua.
 */
void try(int k, int *totalCost, int *minCost)
{
    for (int i = 2; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            x[k] = i;
            visited[i] = 1;
            *totalCost += cost[x[k - 1] - 1][x[k] - 1]; // Trừ 1 vì mảng index từ 0 (tôi đã bug chỗ này hồi lâu)

            if (k == n - 1)
            {
                *totalCost += cost[x[k] - 1][0];
                if (*totalCost < *minCost)
                {
                    *minCost = *totalCost;
                    for (int j = 0; j < n; j++)
                        path[j] = x[j];
                }
                *totalCost -= cost[x[k] - 1][0];
            }
            else
                try(k + 1, totalCost, minCost);

            // Quay lui
            *totalCost -= cost[x[k - 1] - 1][x[k] - 1];
            visited[i] = 0;
        }
    }
}

/* THUẬT TOÁN NHÁNH CẬN (BRANCH AND BOUND):
 | - Sử dụng đánh giá cận để cắt bỏ không gian tìm kiếm không cần thiết.
 | - Gọi c_min là chi phí nhỏ nhất giữa 2 thành phố bất kỳ.
 | - Giả sử đã xây dựng x[1..k] và đã đi qua các thành phố 1, x[2], x[3], ..., x[k].
 | - Còn (n - k + 1) thành phố chưa đi qua là x[k + 1], x[k + 2], ..., x[n].
 | -> Tổng chi phí của hành trình: totalCost + (n - k + 1) * c_min.
 | - Nếu totalCost + (n - k + 1) * c_min >= minCost thì không cần xây dựng tiếp.
 */
// Tìm chi phí nhỏ nhất giữa 2 thành phố bất kỳ
int findMinCost()
{
    int minCost = INT_MAX;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (cost[i][j] < minCost)
                minCost = cost[i][j];
    return minCost;
}

// Hàm thử xây dựng hành trình
void tryNew(int k, int *totalCost, int *minCost, int costMin)
{
    for (int i = 2; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            x[k] = i;
            visited[i] = 1;
            *totalCost += cost[x[k - 1] - 1][x[k] - 1]; // Trừ 1 vì mảng index từ 0

            if (k == n - 1)
            {
                *totalCost += cost[x[k] - 1][0];
                if (*totalCost < *minCost)
                {
                    *minCost = *totalCost;
                    for (int j = 0; j < n; j++)
                        path[j] = x[j];
                }
                *totalCost -= cost[x[k] - 1][0];
            }
            else
            {
                if (*totalCost + (n - k + 1) * costMin < *minCost)
                    tryNew(k + 1, totalCost, minCost, costMin);
            }

            // Quay lui
            *totalCost -= cost[x[k - 1] - 1][x[k] - 1];
            visited[i] = 0;
        }
    }
}

int main()
{
    // Nhập số lượng thành phố
    scanf("%d", &n);

    // Cấp phát bộ nhớ cho các mảng
    x = (int *)malloc(n * sizeof(int));
    path = (int *)malloc(n * sizeof(int));
    visited = (int *)calloc(n + 1, sizeof(int));
    cost = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        cost[i] = (int *)malloc(n * sizeof(int));

    // Nhập ma trận chi phí
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    // Xây dựng hành trình bằng quay lui
    x[0] = 1;
    visited[1] = 1;
    try(1, &totalCost, &minCost);

    // Xây dựng hành trình bằng nhánh cận
    // int costMin = findMinCost();
    // tryNew(1, &totalCost, &minCost, costMin);

    // In ra hành trình tối ưu và chi phí nhỏ nhất
    printf("Min cost: %d\n", minCost);
    printPath();

    // Giải phóng bộ nhớ
    free(x);
    free(path);
    free(visited);
    for (int i = 0; i < n; i++)
        free(cost[i]);
    free(cost);

    return 0;
}