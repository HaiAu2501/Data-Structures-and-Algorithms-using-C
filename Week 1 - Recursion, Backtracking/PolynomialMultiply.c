#include <stdio.h>
#include <stdlib.h>

// Đề bài: Nhân hai đa thức P(x) và Q(x) có bậc không vượt quá n.
// P(x) = a[0] + a[1]x + a[2]x^2 + ... + a[n]x^n
// Q(x) = b[0] + b[1]x + b[2]x^2 + ... + b[n]x^n
/* Sử dụng đệ quy */

// Hàm nhân hai đa thức P(x) và Q(x) có bậc không vượt quá n -> Time: O(n^2) | Space: O(n)
void multiply(int a[], int b[], int n)
{
    int c[2 * n + 1];
    for (int i = 0; i <= 2 * n; i++)
    {
        c[i] = 0;
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            c[i + j] += a[i] * b[j];
        }
    }

    for (int i = 0; i <= 2 * n; i++)
    {
        printf("%d ", c[i]);
    }
}

// Nhân bằng đệ quy (chia để trị)
/* P(x) = P1(x) + x^(n/2)P2(x), Q(x) = Q1(x) + x^(n/2)Q2(x) với P1(x), P2(x), Q1(x), Q2(x) là các đa thức bậc không quá.
 * P(x)Q(x) = P1(x)Q1(x) + x^(n)P2(x)Q2(x) + x^(n/2)(P1(x)Q2(x) + P2(x)Q1(x))
 * ________________
 * Theo định lý thợ: T(n) = 4T(n/2) + O(n) có log_2(4) = 2 => Time: O(n^2)
 * ________________
 * Ta có thể giảm số lượng phép nhân xuống còn 3:
 * X = P1(x)Q1(x), Y = P2(x)Q2(x), Z = (P1(x) + P2(x))(Q1(x) + Q2(x)) => P(x)Q(x) = X + x^(n)Y + x^(n/2)(Z - X - Y)
 * Theo định lý thợ: T(n) = 3T(n/2) + O(n) có log_2(3) ~ 1.58 => Time: O(n^1.58)
 */
// Hàm nhân hai đa thức sử dụng chia để trị
void multiplyRecursive(int a[], int b[], int result[], int n);

// Hàm để in một đa thức
void printPoly(int poly[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (poly[i] == 0)
            continue;
        if (i != n - 1 && i != 0)
            printf(" + ");
        printf("%dx^%d", poly[i], i);
    }
    printf("\n");
}

int main()
{
    int n;

    scanf("%d", &n);

    int a[n + 1], b[n + 1];

    for (int i = 0; i <= n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i <= n; i++)
        scanf("%d", &b[i]);

    int result[2 * n + 1];

    // Khởi tạo kết quả bằng 0
    for (int i = 0; i < 2 * n + 1; i++)
        result[i] = 0;

    // Gọi hàm nhân hai đa thức
    multiplyRecursive(a, b, result, n);

    // In kết quả
    printPoly(result, 2 * n + 1);

    return 0;
}