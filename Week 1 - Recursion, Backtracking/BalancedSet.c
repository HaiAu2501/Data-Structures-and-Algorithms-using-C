#include <stdio.h>

// https://codeforces.com/problemset/problem/1133/C

// Đề bài: Cho dãy a[1..n] và k, tìm số phần tử lớn nhất sao cho |a[i] - a[j]| <= k với mọi i, j trong đó.
/* SẮP XẾP + 2 CON TRỎ */

// Hàm sắp xếp mảng tăng dần

int n, k;

int main()
{
    scanf("%d %d", &n, &k);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}
