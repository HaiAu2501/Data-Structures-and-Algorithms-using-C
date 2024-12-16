#include <stdio.h>

/* ĐỀ BÀI: Sinh hoán vị của n số nguyên dương đầu tiên theo thứ tự từ điển.
 | - Thứ tự từ điển: Dãy a < b nếu tồn tại vị trí i sao cho a[i] < b[i] và a[j] = b[j] với mọi j < i.
 | - Ví dụ: n = 3 thì các hoán vị theo thứ tự từ điển là (1, 2, 3), (1, 3, 2), (2, 1, 3), (2, 3, 1), (3, 1, 2), (3, 2, 1).
 */

/* THAM SỐ:
 | - Đầu vào: n.
 | - Đầu ra: In ra tất cả các hoán vị của n số nguyên dương đầu tiên theo thứ tự từ điển.
 */

/* THUẬT TOÁN SINH HOÁN VỊ THEO THỨ TỰ TỪ ĐIỂN: -> ĐỆ QUY
 | - Sử dụng đệ quy để sinh hoán vị của mảng a từ vị trí start đến vị trí end (start = 0, end = n - 1).
 | - Bước cơ sở: Nếu start == end thì in ra mảng a.
 | - Ngược lại, đổi chỗ a[start] với a[i] với i chạy từ start đến end.
 | - Gọi đệ quy hàm permute với start = start + 1.
 | - Đổi chỗ lại a[start] với a[i] để trở về trạng thái ban đầu.
 */

int n;

/* HÀM ĐỔI CHỖ 2 BIẾN:
 | - Đổi chỗ 2 biến a và b.
 | - Sử dụng con trỏ để truy cập và thay đổi giá trị thực sự của 2 biến.
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm in ra mảng
void printArray(int *a)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

/* HÀM SINH HOÁN VỊ:
 | - Ví dụ: permute([1, 2, 3], 0, 2) sẽ sinh ra tất cả các hoán vị của 3 số 1, 2, 3.
 | - (1) start = 0, end = 2, i = 0: swap(&a[0], &a[0]) -> permute([1, 2, 3], 1, 2).
 | - (2) start = 1, end = 2, i = 1: swap(&a[1], &a[1]) -> permute([1, 2, 3], 2, 2).
 | - (3) start = 2, end = 2, i = 2: printArray([1, 2, 3]).
 | - (4) start = 1, end = 2, i = 2: swap(&a[1], &a[2]) -> permute([1, 3, 2], 2, 2).
 | - (5) start = 2, end = 2, i = 2: printArray([1, 3, 2]).
 | - (6) start = 1, end = 2, i = 2: swap(&a[1], &a[2]) -> permute([1, 2, 3], 2, 2).
 | - (...)
 */
void permute(int *a, int start, int end)
{
    if (start == end)
    {
        printArray(a);
    }
    else
    {
        for (int i = start; i <= end; i++)
        {
            swap(&a[start], &a[i]);

            // Gọi đệ quy với start = start + 1
            permute(a, start + 1, end);

            // Đổi chỗ lại a[start] với a[i] để trở về trạng thái ban đầu.
            // Đảm bảo mảng a không bị thay đổi khi quay lui.
            swap(&a[start], &a[i]);
        }
    }
}

int main()
{
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }

    permute(a, 0, n - 1);
    return 0;
}