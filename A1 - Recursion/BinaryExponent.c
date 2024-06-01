#include <stdio.h>

// ĐỀ BÀI: Tính a^n với n >= 0, n là số tự nhiên.

/* THAM SỐ:
 | - Đầu vào: a, n.
 | - Đầu ra: kết quả của phép tính a^n.
 */

/* THUẬT TOÁN: -> ĐỆ QUY: O(log(n)) | O(1)
 | - Công thức: a^n = a^(n/2) * a^(n/2) nếu n chẵn và a^n = a^(n/2) * a^(n/2) * a nếu n lẻ.
 | - Nếu n = 0, trả về 1.
 | - Theo Định lý thợ: T(n) = T(n/2) + O(1) -> T(n) = O(log(n)).
 */

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