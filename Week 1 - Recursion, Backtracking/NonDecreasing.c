#include <stdio.h>
#include <stdlib.h>

// Đề bài: Cho một dãy số, liệt kê tất cả các dãy con không giảm của dãy số đó.
// Ví dụ: Dãy số 1 2 5 4 -> {1}, {2}, {5}, {4}, {1, 2}, {2, 5}, {1, 2, 5}.
/* SỬ DỤNG QUAY LUI */
int n;

// Hàm kiểm tra xem dãy con có phải là dãy không giảm không
int isValid(int subseq[], int k)
{
    for (int i = 0; i < k - 1; i++)
    {
        if (subseq[i] > subseq[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

// Hàm in ra dãy con
void printSubsequence(int subseq[], int j)
{
    for (int i = 0; i < j; i++)
    {
        printf("%d ", subseq[i]);
    }
    printf("\n");
}

// Hàm quay lui liệt kê tất cả các dãy con không giảm của dãy số
/* Tham số:
 * - a[]: dãy số đầu vào
 * - subseq[]: dãy con
 * - i: vị trí hiện tại đang xét trong dãy số
 * - j: vị trí hiện tại đang xét trong dãy con
 */
void generate(int a[], int subseq[], int i, int j)
{
    // Nếu đã xét đến phần tử cuối cùng của dãy số
    if (i == n)
    {
        if (isValid(subseq, j))
        {
            printSubsequence(subseq, j);
        }
        return;
    }

    // Chọn phần tử a[i] vào dãy con
    subseq[j] = a[i];
    generate(a, subseq, i + 1, j + 1);

    // Không chọn phần tử a[i] vào dãy con
    generate(a, subseq, i + 1, j);
}

int main()
{
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int subseq[n];
    generate(a, subseq, 0, 0);

    return 0;
}
