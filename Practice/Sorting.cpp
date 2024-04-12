#include <iostream>
#include <algorithm>
using namespace std;

// Hàm sắp xếp được cung cấp trong thư viện <algorithm>
/* Cú pháp hàm sort() là: sort(start, end, comparator)
 * Trong đó:
 * - start: địa chỉ phần tử đầu tiên của dãy cần sắp xếp.
 * - end: địa chỉ phần tử cuối cùng của dãy cần sắp xếp.
 * - comparator: hàm so sánh hai phần tử.
 */

// Hàm in ra mảng
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Ví dụ về cách sử dụng hàm sort()
int main()
{
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sắp xếp mảng theo thứ tự tăng dần
    sort(arr, arr + n);
    printArray(arr, n); // 1 1 2 3 3 4 5 5 6 9

    return 0;
}
