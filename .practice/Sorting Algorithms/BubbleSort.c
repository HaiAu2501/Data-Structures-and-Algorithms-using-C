#include <stdio.h>

// Thuật toán sắp xếp nổi bọt (bubble sort) sắp xếp mảng arr gồm n phần tử
/* - Đầu vào: mảng arr gồm n phần tử.
 * - Đầu ra: mảng arr sau khi đã được sắp xếp tăng dần.
 * - Các bước:
 * + Lặp i từ 0 đến n - 1:
 * + Lặp j từ 0 đến n - i - 1:
 * + Nếu arr[j] > arr[j + 1], đổi chỗ 2 phần tử này.
 */

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        // Dừng sớm nếu mảng đã được sắp xếp
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}