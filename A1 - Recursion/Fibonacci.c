#include <stdio.h>

// Đề bài: Tính số Fibonacci thứ n.

// Cách đệ quy -> O(2^n)
int fibonacci_v1(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Cách lưu trữ kết quả đã tính -> Time: O(n) | Space: O(n)
int fibonacci_v2(int n)
{
    int f[n + 2];
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

// Cách lưu trữ 2 số trước -> Time: O(n) | Space: O(1)
int fibonacci_v3(int n)
{
    int a = 0, b = 1, c;
    if (n == 0)
    {
        return a;
    }
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", fibonacci_v3(n));
    return 0;
}