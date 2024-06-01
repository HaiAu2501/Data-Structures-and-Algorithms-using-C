#include <stdio.h>
#include <stdlib.h>

// QuickSort là một thuật toán sắp xếp phổ biến nhất
/* - QuickSort là một thuật toán sắp xếp đệ quy dựa trên chia để trị.
 * - Độ phức tạp thời gian trung bình của thuật toán QuickSort là O(n*log(n)).
 * - Thời gian xấu nhất của thuật toán QuickSort là O(n^2), xảy ra khi mảng sắp xếp ngược.
 */

// Trong C cung cấp hàm qsort() trong thư viện stdlib.h để sắp xếp mảng
// Cú pháp: void qsort(array, size of array, size of an element, compare function)
/* - array: mảng cần sắp xếp
 * - size of array: số lượng phần tử của mảng
 * - size of an element: kích thước của một phần tử trong mảng
 * - compare function: hàm so sánh
 */

// Hàm so sánh dùng cho qsort
// Cú pháp: int compare(const void *a, const void *b)
/* - Kiểu trả về: int
 * - Có 2 tham số là 2 con trỏ kiểu void, khi sắp xếp cần ép 2 con trỏ này về kiểu dữ liệu mong muốn
 * - Có giá trị trả về dựa vào logic sau:
 * + < 0 nếu phần tử trỏ bởi a đứng trước phần tử trỏ bởi b
 * + = 0 nếu phần tử trỏ bởi a và b bằng nhau
 * + > 0 nếu phần tử trỏ bởi a đứng sau phần tử trỏ bởi b
 */

// Ví dụ:
int compareIncrease(const void *a, const void *b)
{
    // Ép kiểu con trỏ void về kiểu int và trả về hiệu của 2 số
    int *A = (int *)a;
    int *B = (int *)b;
    return *A - *B;
    // Để sắp xếp mảng theo thứ tự tăng dần trả về *A - *B vì:
    // Nếu *A - *B < 0 tức *A < *B thì A đứng trước B
}

int compareDecrease(const void *a, const void *b)
{
    // Ép kiểu con trỏ void về kiểu int và trả về hiệu của 2 số
    int *A = (int *)a;
    int *B = (int *)b;
    return *B - *A;
}

void main()
{
    int arr[] = {5, 2, 8, 7, 1};
    int n = sizeof(arr) / sizeof(int);

    // Sắp xếp mảng arr theo thứ tự tăng dần
    qsort(arr, n, sizeof(int), compareIncrease);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sắp xếp mảng arr theo thứ tự giảm dần
    qsort(arr, n, sizeof(int), compareDecrease);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}