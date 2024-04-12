#include <stdio.h>
#include <stdlib.h>

// Đề bài: Tính hệ số nhị thức C(n, k).
// Công thức truy hồi: C(n, k) = C(n - 1, k - 1) + C(n - 1, k).
// Cơ sở truy hồi: C(n, 0) = C(n, n) = 1.

// Nếu sử dụng đệ quy -> Độ phức tạp O(2^n).
int binomial(int n, int k)
{
    if (k == 0 || k == n)
    {
        return 1;
    }
    return binomial(n - 1, k - 1) + binomial(n - 1, k);
}

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
