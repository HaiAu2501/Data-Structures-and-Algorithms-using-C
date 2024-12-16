#include <stdio.h>
#include <stdlib.h>

// Hàm biến thể của thuật toán tìm kiếm nhị phân
/* - Tìm vị trí mà để chèn key vào mảng a sao cho mảng vẫn tăng dần
 * - binarySearch(a, -1, length - 1, key) trả về vị trí thích hợp để chèn key vào mảng a
 * Ví dụ a = 1, 3, 5, 7, key = 4 thì trả về 2
 * - Nếu dùng binarySearch(a, 0, length - 1, key) thì trả về 1 vì a[1] = 3 < key
 */
int binarySearch(int *a, int l, int r, int key)
{
    while (r - l > 1)
    {
        int m = l + (r - l) / 2;
        if (a[m] >= key)
            r = m;
        else
            l = m;
    }
    return r;
}

// Hàm tìm dãy con tăng dài nhất theo thuật toán Quy hoạch động
/* Gọi tailTable[i] là phần tử cuối cùng của dãy con tăng dài nhất có i phần tử
 * - Nếu a[i] nhỏ hơn tailTable[0] thì a[i] trở thành phần tử mới nhất
 * - Nếu a[i] lớn hơn tailTable[length - 1] thì thêm vào cuối
 * - Ngược lại, tìm vị trí thích hợp cho a[i] trong tailTable và thay thế
 */
int longestIncreasingSubsequence(int *a, int n)
{
    if (n == 0)
        return 0;

    int *tailTable = (int *)malloc(n * sizeof(int));
    int length; // Luôn có ít nhất một dãy con tăng bắt đầu bằng a[0]

    tailTable[0] = a[0];
    length = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < tailTable[0])
            // a[i] nhỏ hơn tất cả => a[i] trở thành phần tử mới nhất
            tailTable[0] = a[i];
        else if (a[i] > tailTable[length - 1])
            // a[i] lớn hơn tất cả => thêm vào cuối và tăng chiều dài
            tailTable[length++] = a[i];
        else
            // a[i] nằm giữa hai giá trị => thay thế
            tailTable[binarySearch(tailTable, -1, length - 1, a[i])] = a[i];
    }

    free(tailTable);
    return length;
}
/* Ví dụ:
 * 1 4 5 3 2
 * - tailTable = 1, length = 1
 * - a[1] = 4 > tailTable[0] = 1 => tailTable = 1, 4; length = 2
 * - a[2] = 5 > tailTable[1] = 4 => tailTable = 1, 4, 5; length = 3
 * - a[3] = 3 nằm giữa: tailTable[0] <= a[3] <= tailTable[1] => tailTable = 1, 3, 5; length = 3
 * - a[4] = 2 nằm giữa: tailTable[0] <= a[4] <= tailTable[1] => tailTable = 1, 2, 5; length = 3
 */

int main()
{
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("%d\n", longestIncreasingSubsequence(a, n));
    free(a);
    return 0;
}
