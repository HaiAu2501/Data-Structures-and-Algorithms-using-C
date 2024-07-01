#include <stdio.h>

/* ĐỀ BÀI: Liệt kê tất cả xâu nhị phân có độ dài n theo thứ tự từ điển.
 | - Sử dụng cấu trúc chung của Backtracking.
 */

/* THAM SỐ:
 | - Đầu vào: n.
 | - Đầu ra: In ra tất cả các xâu nhị phân có độ dài n theo thứ tự từ điển.
 */

int n;

void printArray(int *a)
{
    for (int i = 0; i < n; i++)
        printf("%d", a[i]);
    printf("\n");
}

void try(int k, int *a)
{
    for (int i = 0; i <= 1; i++)
    {
        a[k] = i;
        if (k == n - 1)
            printArray(a);
        else
            try(k + 1, a);
    }
}

int main()
{
    scanf("%d", &n);
    int a[n];
    try(0, a);
    return 0;
}
