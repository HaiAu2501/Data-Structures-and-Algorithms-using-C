#include <stdio.h>

// https://codeforces.com/problemset/problem/1928/B

// ✏️ ĐỀ BÀI: Cho dãy a[1..n], ta có thể cộng 1 hoán vị p[1..n] nào đó của n số nguyên dương đầu tiên vào dãy a.
// Tìm số lượng lớn nhất các số giống nhau có thể có trong a sau khi cộng.

/* ❇️ THAM SỐ:
 * - Đầu vào: n, a[1..n].
 * - Đầu ra: số lượng lớn nhất các số giống nhau trong a sau khi cộng.
 */

/* 📌 THUẬT TOÁN THAM LAM:
 * - Có n số -> Có không quá n số giống nhau.
 * - Thường thì, nếu số nào lớn trong a -> cộng nó với số nhỏ trong p.
 * -> Hai số trong a có thể cộng với 2 số trong {1, 2, ..., n} để trở nên giống nhau nếu hiệu nó không quá n - 1.
 * -> Phải tìm số lượng số lớn nhất trong a mà hiệu hai số bất kỳ không quá n - 1.
 * (Dãy a có thể có số giống nhau, nên loại bỏ số giống nhau trước khi xử lý. Có thể làm điều này ngay từ khi nhập dữ liệu.)
 * Độ phức tạp: O(nlogn) (do sắp xếp dãy a).
 */

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    
}