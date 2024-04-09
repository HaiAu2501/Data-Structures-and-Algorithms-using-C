#include <stdio.h>
#include <stdlib.h>

// Đề bài: Cho X = {(a1, b1), (a2, b2), ..., (an, bn)} với 0 < ai < bi là đầu mút của đoạn thẳng thứ i
// Tìm tập các đoạn thẳng không giao nhau mà có số phần tử lớn nhất.
/* Giải bài toán này bằng thuật toán Tham lam.
 * - Bước 1: Sắp xếp các đoạn thẳng theo thứ tự tăng dần của đầu mút b.
 * - Bước 2: Chọn đoạn thẳng đầu tiên, sau đó chọn đoạn thẳng tiếp theo mà đầu mút của nó không giao với đoạn thẳng đã chọn.
 * - Lặp lại bước 2 cho đến khi không còn đoạn thẳng nào thỏa mãn.
 */

// Định nghĩa cấu trúc đoạn thẳng
typedef struct Segment
{
    int start, end;
} Segment;

int compareSegments(const void *a, const void *b)
{
    Segment *A = (Segment *)a;
    Segment *B = (Segment *)b;
    return A->end - B->end;
}

// Hàm giải quyết bài toán
int maxNonOverlappingSegments(Segment segment[], int n)
{
    qsort(segment, n, sizeof(Segment), compareSegments);

    int count = 1;
    int currentEnd = -1;
    for (int i = 0; i < n; i++)
    {
        if (segment[i].start >= currentEnd)
        {
            count++;
            currentEnd = segment[i].end;
        }
    }
    return count;
}

void main()
{
    int n;
    scanf("%d", &n);
    Segment segment[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &segment[i].start, &segment[i].end);
    }

    printf("%d", maxNonOverlappingSegments(segment, n));
}