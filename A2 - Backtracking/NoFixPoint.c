#include <stdio.h>
#include <stdlib.h>

// Đề bài: Nhập vào n nguyên dương, liệt kê tất cả dãy hoán vị a[1..n] của n số nguyên dương đầu tiên
// thỏa mãn a[i] != i với mọi i = 1..n (Hoán vị không có điểm cố định).
/* SỬ DỤNG QUAY LUI */

int n;

// Hàm đổi chỗ 2 số nguyên (để sử dụng trong thuật toán sinh hoán vị)
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm kiểm tra hoán vị có điểm cố định không
int isValid(int a[])
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == i + 1)
        {
            return 0;
        }
    }
    return 1;
}

// Hàm in ra dãy hoán vị
void printPermutation(int a[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Thuật toán sinh hoán vị không có điểm cố định
void generate(int a[], int i)
{
    // Nếu đã sinh đủ n phần tử
    if (i == n)
    {
        if (isValid(a))
        {
            printPermutation(a);
        }
        return;
    }

    // Sinh hoán vị bắt đầu từ vị trí i
    for (int j = i; j < n; j++)
    {
        swap(&a[i], &a[j]); // Hoán đổi vị trí
        generate(a, i + 1);
        swap(&a[i], &a[j]); // Trả lại hoán vị cũ
    }
}

int main()
{
    scanf("%d", &n);
    int a[n];

    // Khởi tạo hoán vị a[1..n]
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }

    generate(a, 0);
    return 0;
}