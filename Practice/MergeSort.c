#include <stdio.h>
#include <stdlib.h>

// MergeSort là một thuật toán sắp xếp đệ quy dựa trên chia để trị.
/* - Thuật toán chia mảng thành hai mảng con, sắp xếp hai mảng con đó và sau đó trộn hai mảng con đó lại với nhau.
 * - Độ phức tạp thời gian trung bình và trường hợp xấu nhất của thuật toán MergeSort là O(n*log(n)).
 * - Độ phức tạp không gian của thuật toán MergeSort là O(n).
 */

// Hàm trộn hai mảng con của mảng arr[]
// Mảng con thứ nhất là arr[l..m]
// Mảng con thứ hai là arr[m+1..r]
