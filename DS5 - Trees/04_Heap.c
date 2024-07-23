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