#include <stdio.h>
#include <stdlib.h>

// MergeSort là một thuật toán sắp xếp đệ quy dựa trên chia để trị.
/* - Thuật toán chia mảng thành hai mảng con, sắp xếp hai mảng con đó và sau đó trộn hai mảng con đó lại với nhau.
 * - Độ phức tạp thời gian trung bình và trường hợp xấu nhất của thuật toán MergeSort là O(n*log(n)).
 * - Độ phức tạp không gian của thuật toán MergeSort là O(n).
 */

// Hàm trộn hai mảng con của arr[]
// Mảng con đầu tiên là arr[l..m]
// Mảng con thứ hai là arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1; // Kích thước mảng con thứ nhất
    int n2 = r - m;     // Kích thước mảng con thứ hai

    // Tạo mảng tạm để lưu trữ mảng con thứ nhất
    int L[n1];
    // Tạo mảng tạm để lưu trữ mảng con thứ hai
    int R[n2];

    // Sao chép dữ liệu từ mảng arr[] vào mảng tạm L[] và R[]
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    // Trộn hai mảng con đã sắp xếp vào mảng arr[]
    int i = 0; // Chỉ mục của mảng con thứ nhất
    int j = 0; // Chỉ mục của mảng con thứ hai
    int k = l; // Chỉ mục của mảng arr[]

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của mảng con thứ nhất (nếu có)
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại của mảng con thứ hai (nếu có)
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Hàm sắp xếp mảng arr[] từ chỉ mục l đến chỉ mục r
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Tìm chỉ mục của phần tử ở giữa
        int m = l + (r - l) / 2;

        // Sắp xếp mảng con thứ nhất và mảng con thứ hai
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Trộn hai mảng con đã sắp xếp
        merge(arr, l, m, r);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Mang truoc khi sap xep: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    mergeSort(arr, 0, n - 1);

    printf("Mang sau khi sap xep: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
