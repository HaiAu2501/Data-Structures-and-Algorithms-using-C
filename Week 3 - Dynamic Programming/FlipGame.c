#include <stdio.h>

// https://codeforces.com/problemset/problem/327/A

// Đề bài: Cho dãy nhị phân a[1..n]. Có thể đảo bit một dãy con bất kỳ của dãy này một lần.
// Tìm số bit 1 lớn nhất có thể có sau khi đảo bit.

/* THAM SỐ:
 * - Đầu vào: n (1 ≤ n ≤ 100), a[1..n] (a[i] = 0 hoặc 1).
 * - Đầu ra: số bit 1 lớn nhất có thể có sau khi đảo bit.
 */

/* THUẬT TOÁN -> QUY HOẠCH ĐỘNG:
 * - Gọi f[i] là số bit 1 lớn nhất có thể có sau khi đảo bit dãy con a[1..i] -> cần tìm f[n].
 * - Nếu a[i] = 0, thì f[i] += 1, nếu a[i] = 1, thì f[i] += -1.
 * => Ta sẽ sử dụng mảng b[n] để lưu giá trị +1 hoặc -1 tương ứng với a[i].
 * => Như vậy, cần tìm dãy con có tổng lớn nhất trong mảng b[1..n] rồi cộng với số bit 1 ban đầu.
 */

#define max(a, b) (a > b ? a : b)

/* THUẬT TOÁN TÌM TỔNG LỚN NHẤT CỦA DÃY CON:
 * - Gọi end[i] là tổng lớn nhất của dãy con kết thúc tại a[i].
 * - Gọi sum[i] là tổng lớn nhất của dãy con lấy từ a[1..i].
 * - Dãy con sum[i] có thể chứa a[i] hoặc không chứa a[i] => cần tìm max(end[i - 1] + a[i], a[i]).
 * - end[0] = sum[0] = a[0].
 * - end[i] = max(end[i - 1] + a[i], a[i]).
 * - sum[i] = max(sum[i - 1], end[i]).
 */
int maxSub(int *a, int n)
{
    int end[n];
    int sum[n];

    end[0] = sum[0] = a[0];

    for (int i = 1; i < n; i++)
    {
        end[i] = max(end[i - 1] + a[i], a[i]);
        sum[i] = max(sum[i - 1], end[i]);
    }

    return sum[n - 1];
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] == 1)
        {
            result++;
            a[i] = -1;
        }
        else
        {
            a[i] = 1;
        }
    }
    printf("%d", result + maxSub(a, n));
    return 0;
}