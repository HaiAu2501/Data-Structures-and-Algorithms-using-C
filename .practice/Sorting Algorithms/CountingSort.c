#include <stdio.h>
#include <stdlib.h>

/* THUẬT TOÁN: -> Counting Sort: O(n + k) với n là số phần tử của mảng và k là phạm vi giá trị của mảng.
 | - Là thuật toán sắp xếp ổn định (stable).
 | - Ý tưởng: Sắp xếp mảng dựa trên số lần xuất hiện của các phần tử.
 | - Áp dụng cho mảng chứa các số nguyên không âm.
 | + Bước 1: Tạo mảng count[] với kích thước là giá trị lớn nhất trong mảng + 1, khởi tạo tất cả phần tử bằng 0.
 | + Bước 2: Đếm số lần xuất hiện của các phần tử và lưu vào mảng count[].
 | + Bước 3: Cập nhật mảng count[] sao cho count[i] chứa vị trí cuối cùng của phần tử i trong mảng kết quả.
 | + Bước 4: Tạo mảng kết quả res[] với kích thước bằng kích thước mảng ban đầu.
 | + Bước 5: Duyệt mảng ban đầu, đưa phần tử vào mảng kết quả và giảm count[] tương ứng.
 */

/* Ví dụ:
 | Input: arr[] = (4, 2, 2, 8, 3, 3, 1)
 | + Bước 1: max = 8, count[] = (0, 0, 0, 0, 0, 0, 0, 0, 0)
 | + Bước 2: count[] = (0, 1, 2, 2, 1, 0, 0, 0, 1) => loop n
 | + Bước 3: count[] = (0, 1, 3, 5, 6, 6, 6, 6, 7) => loop k
 | + Bước 5:
 |   - Lần 1: arr[6] = 1, count[1] = 1 => count[1] = 0, res[0] = 1, res[] = (1, 0, 0, 0, 0, 0, 0)
 |   - Lần 2: arr[5] = 3, count[3] = 5 => count[3] = 4, res[4] = 3, res[] = (1, 0, 0, 0, 3, 0, 0)
 |   - Lần 3: arr[4] = 3, count[3] = 4 => count[3] = 3, res[3] = 3, res[] = (1, 0, 0, 3, 3, 0, 0)
 |   - Lần 4: arr[3] = 8, count[8] = 7 => count[8] = 6, res[6] = 8, res[] = (1, 0, 0, 3, 3, 0, 8)
 |   - Lần 5: arr[2] = 2, count[2] = 3 => count[2] = 2, res[2] = 2, res[] = (1, 0, 2, 3, 3, 0, 8)
 |   - Lần 6: arr[1] = 2, count[2] = 2 => count[2] = 1, res[1] = 2, res[] = (1, 2, 2, 3, 3, 0, 8)
 |   - Lần 7: arr[0] = 4, count[4] = 6 => count[4] = 5, res[5] = 4, res[] = (1, 2, 2, 3, 3, 4, 8)
 | Output: 1, 2, 2, 3, 3, 4, 8
 */

int n;

void countingSort(int *arr)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    int *count = (int *)calloc(max + 1, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    int *res = (int *)malloc(n * sizeof(int));
    for (int i = n - 1; i >= 0; i--)
    {
        res[--count[arr[i]]] = arr[i];
        // Tương đương với res[count[arr[i]] - 1] = arr[i]; count[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = res[i];
    }

    free(count);
    free(res);
}

/* THUẬT TOÁN COUNTING SORT VER 2:
 | - Trong cách trước, mảng count[] có kích thước là (max + 1) để lưu được số lần xuất hiện của các phần tử từ 0 đến max.
 | => Tuy nhiên không cần thiết, có thể giảm bộ nhớ bằng cách tìm min và max của mảng, sau đó tạo mảng count[] với kích thước (max - min + 1).
 | - min sẽ được tìm cũng với max trong vòng lặp đầu tiên => vẫn lặp n.
 | - Tuy nhiên, vòng lặp thứ 2 chỉ lặp (max - min + 1) lần, để tìm số lần xuất hiện của các phần tử từ min đến max.
 | => Độ phức tạp giảm từ O(n + max) xuống O(n + (max - min)).
 */

// Triển khai cách mới của Counting Sort (countingSort2)
void countingSort2(int *arr)
{
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        else if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    int *count = (int *)calloc(max - min + 1, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        count[arr[i] - min]++;
    }

    for (int i = 1; i <= max - min; i++)
    {
        count[i] += count[i - 1];
    }

    int *res = (int *)malloc(n * sizeof(int));
    for (int i = n - 1; i >= 0; i--)
    {
        res[--count[arr[i] - min]] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = res[i];
    }

    free(count);
    free(res);
}

/* TRONG TRƯỜNG HỢP MẢNG CHỨA CẢ CÁC SỐ NGUYÊN ÂM:
 | - Để sắp xếp mảng chứa cả số nguyên âm, ta cần thêm một bước để chuyển mảng về dạng không âm.
 | - Cách 1: Tìm min của mảng, sau đó cộng mỗi phần tử với -min để chuyển mảng về dạng không âm.
 | - Cách 2: Tạo mảng count[] với kích thước là (max - min + 1) và lưu số lần xuất hiện của các phần tử từ min đến max.
 */

int main()
{
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    countingSort(arr);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}