#include <stdio.h>
#include <stdlib.h>

// Đề bài: Cho 2 dãy số nguyên a và b, tìm dãy con chung dài nhất của a và b.
// Ví dụ: a = {1, 2, 3, 4, 5}, b = {2, 4, 5, 6}, kết quả là {2, 4, 5}.
/* Giải bài này bằng Quy hoạch động:
 * - Gọi c[i][j] là độ dài dãy con chung dài nhất của 2 dãy a[1..i] và b[1..j]
 * - Nếu a[i] = b[j], c[i][j] = c[i-1][j-1] + 1
 * - Nếu a[i] != b[j], c[i][j] = max(c[i-1][j], c[i][j-1])
 */

#define MAX(x, y) ((x) > (y) ? (x) : (y))

int m, n;

int longestCommonSubsequence(int *a, int *b, int **c)
{
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                c[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
                c[i][j] = MAX(c[i - 1][j], c[i][j - 1]);
        }
    }

    return c[m][n];
}

void main()
{
    scanf("%d %d", &m, &n);

    int *a = (int *)malloc(sizeof(int) * m);
    int *b = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < m; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);

    int *c[m];
    for (int i = 0; i < m; i++)
        c[i] = (int *)malloc(sizeof(int) * n);

    printf("%d\n", longestCommonSubsequence(a, b, c));
}