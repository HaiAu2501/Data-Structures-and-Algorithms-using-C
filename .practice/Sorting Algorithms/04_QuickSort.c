#include <stdio.h>

/* ĐỀ BÀI: Sắp xếp mảng số thực theo thứ tự tăng dần.
 * Ví dụ: 5 3 2 1 4 -> 1 2 3 4 5.
 */

/* THAM SỐ:
 | - Đầu vào: n là độ dài của mảng a[], a[] là mảng số nguyên.
 | - Đầu ra: mảng a[] sau khi sắp xếp.
 */

/* THUẬT TOÁN: -> ĐỆ QUY: O(n*log(n)) | O(log(n))
 | - Chọn một phần tử pivot từ mảng a[].
 | - Phân hoạch mảng a[] thành hai phần: một phần có giá trị nhỏ hơn pivot và một phần có giá trị lớn hơn pivot.
 | - Sắp xếp hai phần đó.
 | - LƯU Ý: Độ phức tạp trung bình: O(n*log(n)), độ phức tạp xấu nhất: O(n^2) (khi mảng sắp xếp ngược).
 */

// Hàm hoán đổi giá trị của hai số nguyên
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Cách 1: Chọn pivot là phần tử giữa của mảng.
 | - Phân hoạch mảng a[] thành hai phần: một phần có giá trị nhỏ hơn pivot và một phần có giá trị lớn hơn pivot.
 | - Điều này được thực hiện bằng cách duyệt mảng từ hai phía, nếu phần tử bên trái lớn hơn pivot và phần tử bên phải nhỏ hơn pivot thì đổi chỗ hai phần tử đó.
 | - Kết thúc khi hai chỉ số i và j gặp nhau.
 | - Sắp xếp hai phần đó bằng cách gọi đệ quy.
 */
void quickSortV1(int a[], int left, int right)
{
    if (left >= right)
        return;

    int pivot = a[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j)
    {
        while (a[i] < pivot)
            i++;

        while (a[j] > pivot)
            j--;

        if (i <= j)
        {
            swap(&a[i], &a[j]);
            i++;
            j--;
        }
    }

    quickSortV1(a, left, j);
    quickSortV1(a, i, right);
}

/* Cách 2: Chọn pivot là phần tử đầu tiên của mảng.
 | - Phân hoạch mảng a[] thành hai phần: một phần có giá trị nhỏ hơn pivot và một phần có giá trị lớn hơn pivot.
 | - Sau khi phân hoạch xong, đổi chỗ pivot với phần tử cuối cùng của phần nhỏ hơn pivot.
 | - Sắp xếp hai phần đó bằng cách gọi đệ quy.
 */
void quickSortV2(int a[], int left, int right)
{
    if (left >= right)
        return;

    int pivot = a[left];
    int i = left + 1;
    int j = right;

    while (i <= j)
    {
        while (i <= j && a[i] <= pivot)
            i++;

        while (i <= j && a[j] > pivot)
            j--;

        if (i < j)
            swap(&a[i], &a[j]);
    }

    swap(&a[left], &a[j]);

    quickSortV2(a, left, j - 1);
    quickSortV2(a, j + 1, right);
}

/* Cách 3: Chọn pivot là phần tử cuối cùng của mảng.
 | - Phân hoạch mảng a[] thành hai phần: một phần có giá trị nhỏ hơn pivot và một phần có giá trị lớn hơn pivot.
 | - Sau khi phân hoạch xong, đổi chỗ pivot với phần tử đầu tiên của phần lớn hơn pivot.
 | - Sắp xếp hai phần đó bằng cách gọi đệ quy.
 */
void quickSortV3(int a[], int left, int right)
{
    if (left >= right)
        return;

    int pivot = a[right];
    int i = left;
    int j = right - 1;

    while (i <= j)
    {
        while (i <= j && a[i] < pivot)
            i++;

        while (i <= j && a[j] >= pivot)
            j--;

        if (i < j)
            swap(&a[i], &a[j]);
    }

    swap(&a[right], &a[i]);

    quickSortV3(a, left, i - 1);
    quickSortV3(a, i + 1, right);
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quickSortV2(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}