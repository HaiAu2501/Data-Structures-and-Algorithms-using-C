#include <stdio.h>

// ĐỀ BÀI: Tìm ước chung lớn nhất của hai số nguyên dương a và b.

/* THAM SỐ:
 | - Đầu vào: a, b.
 | - Đầu ra: ước chung lớn nhất của a và b.
 */

/* THUẬT TOÁN: -> ĐỆ QUY: O(log(min(a, b))) | O(1)
 | - Công thức: gcd(a, b) = gcd(b, a % b).
 | - Nếu b = 0, trả về a.
 */

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));
    return 0;
}