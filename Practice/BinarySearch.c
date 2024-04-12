#include <stdio.h>

// Thuật toán tìm kiếm nhị phân (binary search) trên mảng đã sắp xếp
/* - Đầu vào: mảng arr gồm n phần tử đã sắp xếp tăng dần, số nguyên cần tìm x.
 * - Đầu ra: vị trí của x trong mảng arr, hoặc -1 nếu không tìm thấy.
 * - Các bước:
 * + Khởi tạo biến left = 0, right = n - 1.
 * + Lặp đến khi left <= right:
 * + Khởi tạo biến mid = (left + right) / 2.
 * + Nếu arr[mid] = x, trả về mid.
 * + Nếu arr[mid] < x, đặt left = mid + 1.
 * + Nếu arr[mid] > x, đặt right = mid - 1.
 */
int binarySearch(int arr[], int n, int x)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 2;
    int result = binarySearch(arr, n, x);
    if (result == -1)
        printf("Not found\n");
    else
        printf("Found at index %d\n", result);
    return 0;
}