#include <stdio.h>
#include <stdlib.h> // -> for qsort()

// https://codeforces.com/problemset/problem/1843/A

// ✏️ ĐỀ BÀI: Cho một dãy a[1..n], có thể tô màu cho các phần tử của nó, mỗi phần tử chỉ được tô một trong các màu.
// Giá trị của 1 màu là hiệu lớn nhất giữa 2 phần tử có cùng màu đó. Tìm tổng giá trị lớn nhất có thể đạt được.

/* ❇️ THAM SỐ:
 * - Đầu vào: n, a[1..n].
 * - Đầu ra: tổng giá trị lớn nhất có thể đạt được.
 */

/* 📌 THUẬT TOÁN THAM LAM -> O(nlogn)
 * - Nếu một màu chỉ tô cho 1 phần tử, thì giá trị của màu đó sẽ là 0 => Nên tô mỗi màu cho ít nhất 2 phần tử.
 * - Vậy, có thể tô <= [n / 2] màu cho dãy a.
 * - Giả sử các có [n/2] màu tô cho các phần tử, và số nhỏ nhất và lớn nhất màu i là max[i] và min[i].
 * => Giá trị màu i là max[i] - min[i].
 * => Giá trị của tất cả [n/2] màu là hiệu của [n/2] cặp max[i] - min[i], và max[i], min[i] là phần tử của a.
 * => Muốn nó lớn nhất, thì chọn [n/2] số max[i] là [n/2] số lớn nhất của a, [n/2] số min[i] là [n/2] số nhỏ nhất của a.
 */

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    qsort(a, n, sizeof(int), cmp);

    long long result = 0;
    for (int i = 0; i < n / 2; i++)
        result += a[n - i - 1] - a[i];

    printf("%lld", result);

    return 0;
}