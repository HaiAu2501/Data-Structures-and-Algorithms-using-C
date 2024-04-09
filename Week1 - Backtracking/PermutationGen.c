#include <stdio.h>

// Hàm hoán đổi giá trị của 2 biến
// dùng con trỏ để thực sự thay đổi giá trị của biến, không tạo ra bản sao
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm in ra mảng
void printArray(int *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

/* Hàm sinh hoán vị của mảng a từ vị trí start đến vị trí end
 * - Nếu start == end thì in ra mảng a
 * - Ngược lại, đổi chỗ a[end] với a[i] với i chạy từ end đến 0
 * - Gọi đệ quy hàm permute với start = start + 1
 * - Đổi chỗ lại a[end] với a[i] để trở về trạng thái ban đầu
 * Ví dụ: 1, 2, 3, 4
 * - 1, 2, 3, 4
 * - Khi start = 0, end = 3; i = 3 -> 1, 2, 4, 3 -> permute(0, 2) tức là sinh hoán vị của 1, 2, 4
 * -> permute(0, 1) -> hoán vị của 1, 4 -> permute(0, 0) -> hoán vị của 4
 */
void permute(int *a, int start, int end)
{
    if (start == end)
    {
        printArray(a, end + 1);
    }
    else
    {
        for (int i = end; i >= 0; i--)
        {
            swap(&a[end], &a[i]);
            permute(a, start, end - 1);
            swap(&a[end], &a[i]);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }

    permute(a, 0, n - 1);
    return 0;
}