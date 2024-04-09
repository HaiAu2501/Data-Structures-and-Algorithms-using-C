#include <stdio.h>
#include <stdlib.h>

// Đề bài: Cho ma trận nhị phân có kích thước m x n. Tìm hình vuông lớn nhất chứa toàn bộ số 1.
/* Nhận xét:
 * Giải bằng thuật toán quy hoạch động.
 * - Gọi squareSide[i][j] là cạnh của hình vuông lớn nhất chứa trong ma trận có ô (i, j) là đỉnh phải dưới.
 * 1 1
 * 1 1
 * - Xét hình vuông 2 x 2 nếu toàn số 1 thì squareSide = 2
 * - Nếu chứa bất cứ số 0 nào thì squareSide = 1 hoặc 0
 * Như vậy, squareSide[i][j] = min(squareSide[i - 1][j], squareSide[i][j - 1], squareSide[i - 1][j - 1]) + 1
 */

#define MIN(x, y) ((x) < (y) ? (x) : (y))

int m, n;

// 
int maxSquare(char **matrix)
{
    int squareSide[m][n];
    int maxSide = 0;

    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (r == 0 || c == 0)
            {
                squareSide[r][c] = matrix[r][c] - '0';
            }
            else if (matrix[r][c] == '1')
            {
                squareSide[r][c] = MIN(squareSide[r - 1][c], squareSide[r][c - 1]);
                squareSide[r][c] = MIN(squareSide[r][c], squareSide[r - 1][c - 1]) + 1;
            }
            else
            {
                squareSide[r][c] = 0;
            }

            if (squareSide[r][c] > maxSide)
                maxSide = squareSide[r][c];
        }
    }

    return maxSide * maxSide;
}

void main()
{
    scanf("%d%d", &m, &n);

    char *matrix[m];

    for (int r = 0; r < m; r++)
    {
        matrix[r] = (char *)malloc(n * sizeof(char));
        scanf("%s", matrix[r]);
    }

    printf("%d", maxSquare(matrix));
    return;
}