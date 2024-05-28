#include <stdio.h>

// Trong nhiều bài toán lập trình thi đấu, cần tính MOD (10^9 + 7) của một số nguyên.
// Đây là một số nguyên tố. Trong trường hợp tính mod a/b, ta có thể thay đổi thành a * b^-1 mod p.
// -> Sử dụng định lý Fermat nhỏ: a^(p-1) ≡ 1 (mod p) -> a^(p-2) ≡ a^-1 (mod p).

#define MOD 1000000007

/* THUẬT TOÁN TÍNH MŨ:
 * - Đầu vào: a, b.
 * - Đầu ra: a^b mod MOD.
 * - Độ phức tạp: O(logb), tính bằng đệ quy.
 */
int power(int a, int b)
{
    if (b == 0)
        return 1;
    int temp = power(a, b / 2);
    if (b % 2 == 0)
        return (temp * temp) % MOD;
    return (a * temp * temp) % MOD;
}

/* THUẬT TOÁN TÍNH a/b MOD MOD:
 * - Đầu vào: a, b.
 * - Đầu ra: a * b^-1 mod MOD.
 */
int divide(int a, int b)
{
    return (a * power(b, MOD - 2)) % MOD;
}

int main()
{
    int a = 5, b = 3;
    printf("%d\n", divide(a, b));
    return 0;
}