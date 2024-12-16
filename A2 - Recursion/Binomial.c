#include <stdio.h>
#include <stdlib.h>

/* ĐỀ BÀI: Tính hệ số nhị thức C(n, k) với n, k là số nguyên không âm.
 * - Công thức: C(n, k) = n! / (k! * (n - k)!).
 * - Tính chất: C(n, k) = C(n - 1, k - 1) + C(n - 1, k).
 */

/* THAM SỐ:
 | - Đầu vào: n, k.
 | - Đầu ra: hệ số nhị thức C(n, k).
 */

/* THUẬT TOÁN: -> ĐỆ QUY: O(2^n) | O(1)
 | - Công thức: C(n, k) = C(n - 1, k - 1) + C(n - 1, k).
 | - Nếu k = 0 hoặc k = n, trả về 1.
 | - Độ phức tạp: O(2^n).
 */

// Nếu sử dụng đệ quy -> Độ phức tạp O(2^n).
int binomial(int n, int k)
{
    if (k == 0 || k == n)
    {
        return 1;
    }
    return binomial(n - 1, k - 1) + binomial(n - 1, k);
}

/* THUẬT TOÁN: -> QUY HOẠCH ĐỘNG/ĐỆ QUY CÓ NHỚ: O(n*k) | O(n*k)
 | - Công thức: C(n, k) = C(n - 1, k - 1) + C(n - 1, k).
 | - Nếu k = 0 hoặc k = n, trả về 1.
 | - Sử dụng bảng C[n + 1][k + 1] để lưu trữ giá trị của C(n, k).
 | - Độ phức tạp: O(n*k).
 */

// Sử dụng quy hoạch động để giảm độ phức tạp xuống còn O(n*k).
int binomialDP(int n, int k)
{
    int C[n + 1][k + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (j == 0 || j == i)
            {
                C[i][j] = 1;
            }
            else
            {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }
    return C[n][k];
}

void main()
{
    int n = 5, k = 2;
    printf("C(%d, %d) = %d\n", n, k, binomial(n, k));
    printf("C(%d, %d) = %d\n", n, k, binomialDP(n, k));
}
