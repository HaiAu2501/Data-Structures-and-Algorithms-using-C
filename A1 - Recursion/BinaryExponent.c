#include <stdio.h>

// Đề bài: Tính a^n bằng cách đệ quy.
// Ý tưởng: a^n = a^(n/2) * a^(n/2) nếu n chẵn và a^n = a^(n/2) * a^(n/2) * a nếu n lẻ.

// Hàm đệ quy tính a^n -> Time: O(log(n))
int power(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        int temp = power(a, n / 2);
        return temp * temp;
    }
    return a * power(a, n - 1);
}

int main()
{
    int a, n;
    scanf("%d%d", &a, &n);
    printf("%d\n", power(a, n));
    return 0;
}