#include <stdio.h>

/* ĐỀ BÀI: Sắp xếp mảng số nguyên sử dụng thuật toán Selection Sort (Sắp xếp chọn).
 | - Tìm phần tử nhỏ nhất đưa vào vị trí đầu tiên.
 | - Tìm phần tử nhỏ nhì đưa vào vị trí thứ hai.
 | - Lặp lại cho đến khi mảng được sắp xếp...
 */

int n;    // Số phần tử của mảng
int *arr; // Mảng cần sắp xếp

// Hàm đổi chỗ hai phần tử
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm Sắp xếp chọn (Selection Sort)
void selectionSort()
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

// Hàm in mảng
void printArray()
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    // Nhập số phần tử của mảng
    scanf("%d", &n);

    // Nhập mảng
    arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Sắp xếp mảng
    selectionSort();

    // In mảng sau khi sắp xếp
    printArray();

    free(arr);
    return 0;
}