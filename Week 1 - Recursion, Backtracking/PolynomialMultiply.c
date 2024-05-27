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

int max(int x, int y)
{
    return x > y ? x : y;
}

int min(int x, int y)
{
    return x < y ? x : y;
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
int *multiplyRecursive(int *a, int *b, int n)
{
    int *result = (int *)calloc(2 * n + 1, sizeof(int));
    if (n == 0)
    {
        result[0] = a[0] * b[0];
    }
    else
    {
        int first_size = (n + 1) / 2, second_size = n / 2 + 1; // first_size <= second_size
        int *p1 = a, *p2 = a + first_size, *q1 = b, *q2 = b + first_size,
            *p1q1_prod = multiplyRecursive(p1, q1, first_size - 1),
            *p2q2_prod = multiplyRecursive(p2, q2, second_size - 1),
            *p1p2_sum = (int *)calloc(second_size, sizeof(int)),
            *q1q2_sum = (int *)calloc(second_size, sizeof(int));
        for (int i = 0; i < second_size; i++)
        {
            if (i < first_size)
            {
                p1p2_sum[i] += p1[i];
                q1q2_sum[i] += q1[i];
            }

            p1p2_sum[i] += p2[i];
            q1q2_sum[i] += q2[i];
        }

        int *p1p2_sum_q1q2_sum_prod = multiplyRecursive(p1p2_sum, q1q2_sum, second_size - 1);
        free(p1p2_sum);
        free(q1q2_sum);

        for (int i = 0; i < 2 * n + 1; i++)
        {
            if (i < 2 * first_size - 1)
            {
                result[i] += p1q1_prod[i];
            }
            if (i - n / 2 >= 0 && i - n / 2 < first_size + second_size - 1)
            {
                result[i] += p1p2_sum_q1q2_sum_prod[i - n / 2] - p1q1_prod[i - n / 2] - p2q2_prod[i - n / 2];
            }
            if (i - 2 * (n / 2) >= 0 && i - 2 * (n / 2) < 2 * second_size - 1)
            {
                result[i] += p2q2_prod[i - 2 * (n / 2)];
            }
        }

        free(p1q1_prod);
        free(p2q2_prod);
        free(p1p2_sum_q1q2_sum_prod);
    }

    return result;
}

// Hàm cộng hai đa thức
void addPolynomials(int *A, int *B, int *result, int n)
{
    for (int i = 0; i <= n; i++)
    {
        result[i] = A[i] + B[i];
    }
}

// Hàm trừ hai đa thức
void subPolynomials(int *A, int *B, int *result, int n)
{
    for (int i = 0; i <= n; i++)
    {
        result[i] = A[i] - B[i];
    }
}

// Hàm nhân đa thức bằng thuật toán Karatsuba
int *karatsuba(int *a, int *b, int n)
{
    // Cấp phát bộ nhớ cho mảng kết quả
    int *result = (int *)calloc(2 * n + 1, sizeof(int)); // result[0..2n]

    if (n == 0)
    {
        result[0] = a[0] * b[0];
        return result;
    }
    else if (n == 1)
    {
        result[0] = a[0] * b[0];
        result[1] = a[0] * b[1] + a[1] * b[0];
        result[2] = a[1] * b[1];
        return result;
    }

    int m = n / 2 + 1;

    // Cấp phát bộ nhớ cho A, B
    int *A = (int *)calloc(m, sizeof(int));
    int *B = (int *)calloc(m, sizeof(int));

    for (int i = 0; i < m; i++)
    {
        A[i] = a[i] + a[i + m];
        B[i] = b[i] + b[i + m];
    }

    if (n > 2 * m - 1)
    {
        A[m] = a[n];
        B[m] = b[n];
    }
    else
    {
        A[m] = 0;
        B[m] = 0;
    }

    int *r1 = karatsuba(a, b, m - 1);
    int *r2 = karatsuba(a + m, b + m, n - m);
    int *r3 = karatsuba(A, B, m);

    // Cấp phát bộ nhớ cho r4
    int *r4 = (int *)calloc(2 * m + 1, sizeof(int));

    for (int i = 0; i < 2 * m + 1; i++)
    {
        r4[i] = r3[i] - r1[i] - r2[i];
    }

    for (int i = 0; i < 2 * n + 1; i++)
    {
        if (i < m)
        {
            result[i] = r1[i];
        }
        else if (i >= m && i < 2 * m)
        {
            result[i] = r1[i] + r4[i - m];
        }
        else
        {
            result[i] = r1[i] + r4[i - m] + r2[i - 2 * m];
        }
    }

    free(A);
    free(B);
    free(r1);
    free(r2);
    free(r3);
    free(r4);

    return result;
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

    int *result = karatsuba(a, b, n);

    // int *result = multiplyRecursive(a, b, n);

    // In kết quả
    for (int i = 0; i <= 2 * n; i++)
    {
        printf("%d ", result[i]);
    }

    return 0;
}