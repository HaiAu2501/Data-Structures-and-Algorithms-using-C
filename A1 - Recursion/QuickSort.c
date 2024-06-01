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

void quickSort(int a[], int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int pivot = a[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j)
    {
        while (a[i] < pivot)
        {
            i++;
        }

        while (a[j] > pivot)
        {
            j--;
        }

        if (i <= j)
        {
            swap(&a[i], &a[j]);
            i++;
            j--;
        }
    }

    quickSort(a, left, j);
    quickSort(a, i, right);
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}