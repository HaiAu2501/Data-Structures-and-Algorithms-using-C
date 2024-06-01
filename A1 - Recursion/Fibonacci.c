#include <stdio.h>

/* ĐỀ BÀI: Tìm số Fibonacci thứ n.
 | - Dãy Fibonacci: 0, 1, 1, 2, 3, 5, 8, 13, 21, ...
 | - F(0) = 0, F(1) = 1, F(n) = F(n - 1) + F(n - 2) với n >= 2.
 */

/* THAM SỐ:
 | - Đầu vào: n.
 | - Đầu ra: số Fibonacci thứ n.
 */

/* THUẬT TOÁN: -> ĐỆ QUY: O(1.618^n) | O(1)
 | - Công thức: F(n) = F(n - 1) + F(n - 2).
 | - Nếu n <= 1, trả về n.
 | - Theo Định lý thợ: T(n) = T(n - 1) + T(n - 2) + O(1) -> T(n) = O(1.618^n).
 */

int fibonacci_v1(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

/* THUẬT TOÁN: -> QUY HOẠCH ĐỘNG/ĐỆ QUY CÓ NHỚ: O(n) | O(n)
 | - Sử dụng mảng f[] để lưu trữ kết quả của các số Fibonacci đã tính.
 | - Công thức: F(n) = F(n - 1) + F(n - 2).
 */

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