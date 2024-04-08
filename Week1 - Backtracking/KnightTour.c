#include <stdio.h>
#include <stdlib.h>

// Đề bài: Cho bàn cờ n x n và vị trí đầu của con mã, tìm đường đi của con mã đi qua tất cả
// các ô trên bàn cờ mà không đi qua ô nào 2 lần
/* Nhận xét:
 * - Giải bài toán này bằng quay lui (backtracking)
 * -
 */

int n, count = 0;

void knightTour(int **a, int x, int y, int filled)
{
    if (x < 0 || y < 0 || x > n - 1 || y > n - 1 || a[x][y] > 0)
    {
        return;
    }

    a[x][y] = ++filled;

    if (filled == n * n)
    {
        count++;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%2d ", a[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    else
    {
        knightTour(a, x + 2, y + 1, filled);
        knightTour(a, x + 2, y - 1, filled);
        knightTour(a, x - 2, y + 1, filled);
        knightTour(a, x - 2, y - 1, filled);
        knightTour(a, x + 1, y + 2, filled);
        knightTour(a, x + 1, y - 2, filled);
        knightTour(a, x - 1, y + 2, filled);
        knightTour(a, x - 1, y - 2, filled);
    }

    a[x][y] = 0;
    filled--;
}

int main()
{
    scanf("%d", &n);

    int *a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }

    knightTour(a, 0, 0, 0);
    printf("Found %d solutions\n", count);
}
