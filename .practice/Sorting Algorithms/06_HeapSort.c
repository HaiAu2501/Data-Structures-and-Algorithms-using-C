#include <stdio.h>

/* ĐỀ BÀI: Sắp xếp mảng số nguyên sử dụng thuật toán Heap Sort (Sắp xếp vun đống).
 | - Cấu trúc dữ liệu heap (đống) là 1 cây nhị phân hoàn chỉnh có 2 tính chất:
 | + Tất cả các mức trừ mức cuối cùng đều đầy, mức cuối cùng điền từ trái sang phải.
 | + Giá trị của nút cha lớn hơn hoặc bằng giá trị của nút con.
 | -> Từ chính chất có thể suy ra, gốc của heap (nút đầu tiên) là phần tử lớn nhất.
 | - Heap được cài đặt bằng mảng, ví dụ A[1..n] (đánh số từ 1).
 | + Gốc của heap là A[1].
 | + Con trái của nút cha A[i] là A[2*i].
 | + Con phải của nút cha A[i] là A[2*i + 1].
 | + Cha của nút con A[i] là A[i/2].
 | -> Các phần tử trong mảng con A[n/2 + 1..n] là các nút lá.
 */

/* Với mảng đánh số từ 0, ta có các công thức:
 | - Gốc của heap là A[0].
 | - Con trái của nút cha A[i] là A[2*i + 1].
 | - Con phải của nút cha A[i] là A[2*i + 2].
 | - Cha của nút con A[i] là A[(i - 1)/2].
 | -> Các phần tử trong mảng con A[n/2..n-1] là các nút lá.
 */

/* CÓ 2 DẠNG HEAP:
 | - Max heap: Giá trị của nút cha lớn hơn hoặc bằng giá trị của nút con. -> Gốc là phần tử lớn nhất.
 | - Min heap: Giá trị của nút cha nhỏ hơn hoặc bằng giá trị của nút con. -> Gốc là phần tử nhỏ nhất.
 | Trong bài này, sử dụng Max heap. Min heap tương tự.
 */

/* CÁC PHÉP TOÁN TRÊN HEAP:
 | - Khôi phục tính chất max heap (vun đống): maxHeapify
 | - Tạo max heap từ mảng: buildMaxHeap
 */

// Hàm hoán vị hai số nguyên
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Khôi phục tính chất đống:
 | - Giả sử có nút i với giá trị bé hơn con của nó và giả thiết cây con trái và cây con phải của nó đều là max heap.
 | - Để loại bỏ vi phạm, ta đổi chỗ i với con lớn hơn, di chuyển xuống đến khi nút i không còn bé hơn con của nó.
 | Ví dụ:
 |        4
 |       / \
 |      14  7
 |     / \
 |    2   1
 */
void maxHeapify(int arr[], int n, int i)
{
    int largest = i;       // Khởi tạo largest là nút cha
    int left = 2 * i + 1;  // Nút con trái
    int right = 2 * i + 2; // Nút con phải

    // So sánh nút cha với nút con trái
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // So sánh nút cha với nút con phải
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Nếu nút cha không phải là lớn nhất
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        // Sắp xếp lại heap
        maxHeapify(arr, n, largest);
    }
}

/* Xây dựng max heap từ mảng:
 | - Để tạo max heap từ mảng, ta cần xây dựng max heap từ các nút lá (n/2) đến gốc (0).
 */
void buildMaxHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

/* Heap Sort:
 | - Tạo max heap từ mảng.
 | - Đổi chỗ phần tử lớn nhất (gốc) với phần tử cuối cùng của mảng.
 | - Loại bỏ phần tử cuối cùng (đã sắp xếp) và giảm kích thước heap.
 | - Thực hiện maxHeapify đối với gốc mới.
 | - Lặp lại cho đến khi heap chỉ còn một phần tử.
 */
void heapSort(int arr[], int n)
{
    // Xây dựng max heap
    buildMaxHeap(arr, n);

    // Sắp xếp mảng
    for (int i = n - 1; i > 0; i--)
    {
        // Đổi chỗ phần tử lớn nhất với phần tử cuối cùng
        swap(&arr[0], &arr[i]);

        // Sắp xếp lại heap
        maxHeapify(arr, i, 0);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    heapSort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}