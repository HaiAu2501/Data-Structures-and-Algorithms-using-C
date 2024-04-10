#include <stdio.h>
#include <stdlib.h>

// Đề bài: Cho dãy a[1..n], và m số nguyên l[1..m] mà 1 <= l[i] <= n, 0 <= a[i] <= 10^5
// Tìm số các số đôi một phân biệt trong a[l[i]..n]
/* Giải bài này bằng Quy hoạch động:
 * - Gọi d[i] là số các số đôi một phân biệt trong a[i..n]
 * - Nếu a[i - 1] không xuất hiện trong a[i..n], d[i - 1] = d[i] + 1
 * - Ngược lại, d[i - 1] = d[i]
 * Sử dụng mảng used[a[i]] để xem phần tử a[i] đã xuất hiện chưa.
 */

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    // Đọc dãy số a[0..n - 1], các số l nhập vào nằm trong [0, n - 1]

    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int d[100010] = {}, used[100010] = {};

    for (int i = n; i > 0; i--)
    {
        if (used[a[i - 1]] == 0)
            d[i]++;

        d[i - 1] = d[i];
        used[a[i - 1]]++;
    }

    // Đầu tiên, khi i = n: d[n] = 1, d[n - 1] = 1, used[a[n - 1]] = 1 tức là a[n - 1] đã xuất hiện.
    // Khi i = n - 1, kiểm tra used. Chỉ khi used[a[i - 1]] == 0 nghĩa là a[i - 1] chưa xuất hiện thì d[i - 1] = d[i] + 1

    while (m--)
    {
        int l;
        scanf("%d", &l);
        printf("%d\n", d[l]);
    }

    free(a);
}