#include <stdio.h>
#include <stdlib.h>

/* ĐỀ BÀI: Triển khai CTDL Heap
 | - Heap (đống) là một cây nhị phân đầy đủ. Có 2 loại Heap:
 | + Max Heap: Giá trị của mỗi nút cha lớn hơn hoặc bằng giá trị của các nút con → Nút gốc có giá trị lớn nhất.
 | + Min Heap: Giá trị của mỗi nút cha nhỏ hơn hoặc bằng giá trị của các nút con → Nút gốc có giá trị nhỏ nhất.
 | - Tính chất của Heap:
 | + Tất cả các mức của Heap, trừ mức lá cuối cùng, đều phải đầy đủ các nút.
 | + Nút lá ở mức cuối cùng được thêm từ trái sang phải.
 */

/* 2 PHÉP TOÁN CHÍNH TRÊN HEAP:
 | - Heapify: Đưa một nút về đúng vị trí trong Heap (khôi phục tính chất Heap).
 | - Build Heap: Xây dựng Heap từ một mảng bất kỳ.
 */

// Hàm hoán vị 2 số nguyên
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ##############################
// ########## MIN HEAP ##########
// ##############################

// Cấu trúc dữ liệu đại diện cho Min Heap
typedef struct MinHeap
{
    int *arr;     // Mảng chứa các phần tử của Heap
    int size;     // Số lượng phần tử hiện tại của Heap
    int capacity; // Sức chứa tối đa của Heap
} MinHeap;

// Hàm khởi tạo Min Heap
MinHeap *createMinHeap(int capacity)
{
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    minHeap->arr = (int *)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    return minHeap;
}

// Hàm lấy chỉ số
int parent(int i) { return (i - 1) / 2; }
int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }

// Hàm duy trì tính chất Min Heap (heapify): Đưa nút i về đúng vị trí trong Heap
void minHeapify(MinHeap *minHeap, int i)
{
    int smallest = i; // Khởi tạo nút cha là nút nhỏ nhất
    int l = left(i);  // Nút con trái
    int r = right(i); // Nút con phải

    // So sánh nút cha với nút con trái:
    if (l < minHeap->size && minHeap->arr[l] < minHeap->arr[smallest])
        smallest = l;

    // So sánh nút cha với nút con phải
    if (r < minHeap->size && minHeap->arr[r] < minHeap->arr[smallest])
        smallest = r;

    // Nếu nút cha không phải là nút nhỏ nhất
    if (smallest != i)
    {
        swap(&minHeap->arr[i], &minHeap->arr[smallest]);
        minHeapify(minHeap, smallest); // Đệ quy với nút con vừa hoán vị
    }
}

// Hàm thêm một phần tử vào Min Heap
void insertMinHeap(MinHeap *minHeap, int key)
{
    if (minHeap->size == minHeap->capacity)
    {
        printf("Heap is full!\n");
        return;
    }

    // Chèn phần tử vào cuối Heap
    int i = minHeap->size++; // Tăng kích thước Heap và gán i bằng kích thước mới
    minHeap->arr[i] = key;   // Thêm phần tử vào cuối Heap

    // Duy trì tính chất Min Heap
    while (i != 0 && minHeap->arr[parent(i)] > minHeap->arr[i])
    {
        swap(&minHeap->arr[i], &minHeap->arr[parent(i)]);
        i = parent(i);
    }
}

// Hàm để trích xuất phần tử nhỏ nhất từ Min Heap
int extractMin(MinHeap *minHeap)
{
    if (minHeap->size <= 0)
        return -1;

    if (minHeap->size == 1)
        return minHeap->arr[--minHeap->size];

    // Lưu giá trị phần tử nhỏ nhất
    int root = minHeap->arr[0];

    // Đổi chỗ phần tử nhỏ nhất với phần tử cuối cùng
    minHeap->arr[0] = minHeap->arr[--minHeap->size];

    // Duy trì tính chất Min Heap
    minHeapify(minHeap, 0);

    return root;
}

// Hàm in Min Heap
void printMinHeap(MinHeap *minHeap)
{
    for (int i = 0; i < minHeap->size; i++)
        printf("%d ", minHeap->arr[i]);
    printf("\n");
}

int main()
{
    MinHeap *minHeap = createMinHeap(10);

    insertMinHeap(minHeap, 4);
    insertMinHeap(minHeap, 10);
    insertMinHeap(minHeap, 1);
    insertMinHeap(minHeap, 25);
    insertMinHeap(minHeap, 6);
    insertMinHeap(minHeap, 9);

    printMinHeap(minHeap);

    printf("Extract Min: %d\n", extractMin(minHeap));
    printMinHeap(minHeap);

    return 0;
}

// ###################################
// ## MỘT SỐ THAO TÁC NÂNG CAO KHÁC ##
// ###################################

/* Hàm giảm giá trị của một phần tử trong Min Heap:
 | - Giảm giá trị của phần tử tại chỉ số i trong Min Heap thành giá trị mới key.
 | - Sau khi giảm giá trị, cần đảm bảo tính chất Min Heap vẫn được duy trì.
 | - Thường được sử dụng trong thuật toán Dijkstra.
 */
void decreaseKey(MinHeap *minHeap, int i, int key)
{
    minHeap->arr[i] = key;

    // Duy trì tính chất Min Heap
    while (i != 0 && minHeap->arr[parent(i)] > minHeap->arr[i])
    {
        swap(&minHeap->arr[i], &minHeap->arr[parent(i)]);
        i = parent(i);
    }
}

/* Hàm xóa một phần tử khỏi Min Heap:
 | - Xóa phần tử tại chỉ số i khỏi Min Heap.
 | - Sau khi xóa, cần đảm bảo tính chất Min Heap vẫn được duy trì.
 */
void deleteKey(MinHeap *minHeap, int i)
{
    decreaseKey(minHeap, i, INT_MIN); // Giảm giá trị phần tử i về INT_MIN
    extractMin(minHeap);              // Trích xuất phần tử nhỏ nhất (phần tử i)
}

/* Hàm tạo Min Heap từ mảng:
 | - Để tạo Min Heap từ mảng, ta cần xây dựng Min Heap từ các nút không phải lá (n/2) đến gốc (0).
 */
void buildMinHeap(MinHeap *minHeap, int *array, int size)
{
    if (size > minHeap->capacity)
    {
        printf("Size exceeds capacity!\n");
        return;
    }

    // Sao chép mảng vào Min Heap
    for (int i = 0; i < size; i++)
        minHeap->arr[i] = array[i];

    minHeap->size = size;

    // Heapify từ nút không phải lá cuối cùng đến gốc
    for (int i = minHeap->size / 2 - 1; i >= 0; i--)
        minHeapify(minHeap, i);
}