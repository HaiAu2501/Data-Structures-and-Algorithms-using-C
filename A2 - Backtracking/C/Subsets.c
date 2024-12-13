#include <stdio.h>

// Đề bài: Cho một mảng các số nguyên (các phần tử là duy nhất), hãy in ra tất cả các tập con của mảng đó.
// Ví dụ: 1 2 5 -> {}, {1}, {2}, {5}, {1, 2}, {1, 5}, {2, 5}, {1, 2, 5}
/* Sử dụng quay lui để sinh tất cả các tập con của mảng */

#define MAX_LENGTH 10

int n;

// In tập con độ dài j
void printSubset(int subset[], int j)
{
    printf("{");
    for (int i = 0; i < j; i++)
    {
        printf("%d", subset[i]);
        if (i < j - 1)
        {
            printf(", ");
        }
    }
    printf("}\n");
}

// Hàm quay lui:
/* - arr là mảng input.
 * - subset là tập con.
 * - i là chỉ số phần tử đang xét của mảng arr.
 * - j là chỉ số phần tử đang xét của mảng subset.
 */
void generateSubset(int arr[], int subset[], int i, int j)
{
    if (i == n)
    {
        printSubset(subset, j);
        return;
    }

    // Không chọn phần tử arr[i]
    generateSubset(arr, subset, i + 1, j);

    // Chọn phần tử arr[i]
    subset[j] = arr[i];
    generateSubset(arr, subset, i + 1, j + 1);
}

int main()
{
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int subset[n];

    generateSubset(arr, subset, 0, 0);
    return 0;
}
