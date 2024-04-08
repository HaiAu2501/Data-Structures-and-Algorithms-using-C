#include <stdio.h>

// Đề bài: Sắp xếp tăng dần dãy a[0], a[1], ..., a[n - 1]
/* Nhận xét:
 * Sắp xếp dãy a[0], a[1], ..., a[n - 1] tăng dần bằng thuật toán Quick Sort
 * - Chọn một phần tử chốt (pivot) từ dãy a
 * - Chia dãy a thành hai phần: một phần có giá trị nhỏ hơn pivot, một phần có giá trị lớn hơn pivot
 * - Sắp xếp hai phần trên đệ quy
 * - Kết quả là dãy a đã sắp xếp
 */

// Hàm hoán đổi giá trị của hai số nguyên
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int a[], int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int pivot = a[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j)
    {
        while (a[i] < pivot)
        {
            i++;
        }

        while (a[j] > pivot)
        {
            j--;
        }

        if (i <= j)
        {
            swap(&a[i], &a[j]);
            i++;
            j--;
        }
    }

    quickSort(a, left, j);
    quickSort(a, i, right);
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}