#include <stdio.h>
#include <stdlib.h>

// Hàm tìm kiếm nhị phân để tìm vị trí thích hợp cho phần tử trong dãy con tăng
int binarySearch(int *a, int l, int r, int key)
{
    while (r - l > 1)
    {
        int m = l + (r - l) / 2;
        if (a[m] >= key)
            r = m;
        else
            l = m;
    }
    return r;
}

int longestIncreasingSubsequence(int *a, int n)
{
    if (n == 0)
        return 0;

    int *tailTable = (int *)malloc(n * sizeof(int));
    int length; // Luôn có ít nhất một dãy con tăng bắt đầu bằng a[0]

    tailTable[0] = a[0];
    length = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < tailTable[0])
            // a[i] nhỏ hơn tất cả => a[i] trở thành phần tử mới nhất
            tailTable[0] = a[i];
        else if (a[i] > tailTable[length - 1])
            // a[i] lớn hơn tất cả => thêm vào cuối
            tailTable[length++] = a[i];
        else
            // a[i] nằm giữa hai giá trị => thay thế
            tailTable[binarySearch(tailTable, -1, length - 1, a[i])] = a[i];
    }

    free(tailTable);
    return length;
}

int main()
{
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("%d\n", longestIncreasingSubsequence(a, n));
    free(a);
    return 0;
}
