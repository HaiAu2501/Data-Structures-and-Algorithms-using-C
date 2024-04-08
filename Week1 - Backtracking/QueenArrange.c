#include <stdio.h>
#include <stdlib.h>

// Đề bài: Liệt kê tất cả cách xếp n quân hậu trên bàn cờ n x n sao cho chúng không ăn nhau
/* Biểu diễn lời giải là (a[0], a[1], ..., a[n - 1]) trong đó a[i] là cột của con hậu ở hàng i
 * Nhận xét:
 * - Không có 2 con hậu cùng cột: a[i] != a[j] với mọi i khác j
 * - Không có 2 con hậu cùng đường chéo: |a[i] - a[j]| != |i - j| với mọi i khác j
 */

// Hàm kiểm tra xem cách xếp quân hậu thứ k có hợp lệ không
int isValid(int a[], int k)
{
    for (int i = 0; i < k; i++)
    {
        if (a[i] == a[k] || abs(a[i] - a[k]) == abs(i - k))
        {
            return 0;
        }
    }

    return 1;
}

// Hàm in ra cách xếp quân hậu
void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
}

// Hàm quay lui xếp quân hậu
void queenArrange(int a[], int k, int n)
{
    for (int i = 0; i < n; i++)
    {
        a[k] = i;
        if (isValid(a, k))
        {
            if (k == n - 1)
            {
                print(a, n);
            }
            else
            {
                queenArrange(a, k + 1, n);
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    queenArrange(a, 0, n);
    return 0;
}