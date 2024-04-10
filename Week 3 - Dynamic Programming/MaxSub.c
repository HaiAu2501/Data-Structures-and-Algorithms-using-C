#include <stdio.h>

// Đề bài: Tìm trọng lượng (tổng) của dãy con lớn nhất trong dãy a[0], a[1], ..., a[n - 1]
/* Nhận xét:
 * Giải bài này bằng quy hoạch động, gọi s[i] là tổng lớn nhất của dãy con lấy từ a[0], a[1], ..., a[i]
 * Vậy lời giải của bài toán là s[n - 1]
 * Dãy con lớn nhất:
 * - Nếu không kết thúc tại a[i] thì s[i] = s[i - 1]
 * - Nếu kết thúc tại a[i] thì là dãy con lớn nhất kết thúc tại a[i]
 * Gọi dãy con lớn nhất kết thúc tại a[i] là e[i], ta có: s[i] = max(s[i - 1], e[i])
 * Trong đó:
 * e[0] = a[0], e[i] = max(e[i - 1] + a[i], a[i])
 */

int max(int a, int b)
{
    return a > b ? a : b;
}

int maxSub(int a[], int n)
{
    int s[n];
    int e[n];

    s[0] = e[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        e[i] = max(e[i - 1] + a[i], a[i]);
        s[i] = max(s[i - 1], e[i]);
    }

    return s[n - 1];
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("%d", maxSub(a, n));
    return 0;
}