#include <stdio.h>
#include <stdlib.h>

// Bài toán người du lịch (Traveling Salesman Problem - TSP) là bài toán tìm đường đi ngắn nhất
// để thăm tất cả các thành phố một lần rồi quay về thành phố xuất phát.
// Đây là một bài toán NP khó, không có giải thuật đa thức thời gian nào cho bài toán này.
/* - Có thể sử dụng giải thuật nhánh cận (Branch and Bound) để giải bài toán TSP.
 * - Độ phức tạp trong trường hợp xấu nhất là O(n!) với n là số lượng thành phố, tương tự như giải thuật vét cạn (Brute Force).
 */

// Input: Ma trận chi phí cost[][] với cost[i][j] là chi phí từ thành phố i đến thành phố j.
// Output: Chi phí nhỏ nhất để thăm tất cả các thành phố một lần rồi quay về thành phố xuất phát.

int n;

// Hàm giải bài toán TSP
int solveTSP(int **cost)
{
}

void main()
{
    scanf("%d", &n);
}