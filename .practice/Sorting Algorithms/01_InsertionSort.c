#include <stdio.h>
#include <stdlib.h>

// ĐỀ BÀI: Sắp xếp mảng số nguyên sử dụng thuật toán Insertion Sort (Sắp xếp chèn).

/* THUẬT TOÁN:
 | - Sắp xếp chèn là một thuật toán sắp xếp đơn giản và hiệu quả với dữ liệu nhỏ hoặc đã gần sắp xếp.
 | - Cách hoạt động:
 | + Tại bước k = 1, 2, ..., n, đưa phần tử thứ k vào đúng vị trí trong dãy gồm k phần tử đầu tiên.
 | + Sau n bước, dãy gồm n phần tử đã được sắp xếp.
 */

int n;    // Số phần tử của mảng
int *arr; // Mảng cần sắp xếp

// Hàm Sắp xếp chèn (Insertion Sort)
void insertionSort()
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        // Di chuyển các phần tử của mảng có giá trị lớn hơn key về sau
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    insertionSort();

    // In mảng sau khi sắp xếp
    printArray();

    free(arr);
    return 0;
}