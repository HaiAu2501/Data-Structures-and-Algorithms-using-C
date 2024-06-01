#include <stdio.h>

// Thuật toán sắp xếp vun đống (Heap Sort) là một thuật toán sắp xếp dựa trên cấu trúc dữ liệu heap
// Heap là một cấu trúc dữ liệu cây nhị phân mà tại mỗi nút, giá trị của nút cha lớn hơn hoặc nhỏ hơn giá trị của nút con
/* Heap được chia thành hai loại: max heap và min heap
 * - Max heap: Giá trị của nút cha lớn hơn hoặc bằng giá trị của nút con
 * - Min heap: Giá trị của nút cha nhỏ hơn hoặc bằng giá trị của nút con
 * Các bước của thuật toán:
 * 1. Xây dựng heap: Chuyển mảng thành một heap
 * 2. Sắp xếp: Đưa phần tử lớn nhất (đối với max heap) hoặc nhỏ nhất (đối với min heap) về cuối mảng
 * và giảm kích thước heap đi một đơn vị, sau đó sắp xếp lại heap
 * 3. Lặp lại bước 2 cho đến khi heap chỉ còn một phần tử
 */

// Hàm hoán vị hai số nguyên
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm heapify: Sắp xếp một nút trong heap
// arr[]: Mảng cần sắp xếp
// n: Kích thước của heap
// i: Nút cần sắp xếp
void heapify(int arr[], int n, int i)
{
    int largest = i;       // Khởi tạo largest là nút cha
    int left = 2 * i + 1;  // Nút con trái
    int right = 2 * i + 2; // Nút con phải

    // So sánh nút cha với nút con trái
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    // So sánh nút cha với nút con phải
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // Nếu nút cha không phải là lớn nhất
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        // Sắp xếp lại heap
        heapify(arr, n, largest);
    }
}

// Hàm heapSort: Sắp xếp mảng bằng thuật toán heap sort
void heapSort(int arr[], int n)
{
    // Xây dựng heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // Sắp xếp mảng
    for (int i = n - 1; i > 0; i--)
    {
        // Đưa phần tử lớn nhất về cuối mảng
        swap(&arr[0], &arr[i]);
        // Sắp xếp lại heap
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
