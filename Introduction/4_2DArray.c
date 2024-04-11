#include <stdio.h>
#include <stdlib.h>

// Mảng 2 chiều (Two-Dimensional Array) là một mảng mà mỗi phần tử trong mảng là một mảng khác.
// Khai báo mảng 2 chiều: <kiểu dữ liệu> <tên mảng>[<số hàng>][<số cột>];
// Ví dụ: int arr[2][3]; // Mảng 2 hàng, 3 cột; mỗi phần tử là một số nguyên.
/* - Khai báo con trỏ trỏ tới mảng 2 chiều: <kiểu dữ liệu> (*<tên con trỏ>)[<số cột>];
 * - Ví dụ:
 * + int matrix[3][4]
 * + int (*ptr)[4] = matrix;
 * Trong trường hợp này, con trỏ ptr sẽ trỏ tới hàng đầu tiên của mảng 2 chiều matrix.
 * ptr + 1 sẽ trỏ tới hàng thứ 2 của matrix.
 * Có thể truy cập phần tử bằng cách sử dụng cú pháp: ptr[i][j] hoặc (*(ptr + i))[j] hoặc *(*(ptr + i) + j).
 */

void main()
{
    int rows, cols;
    scanf("%d %d", &rows, &cols);

    // Cấp phát động cho mảng 2 chiều
    int **dynamicMatrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        dynamicMatrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // Nhập giá trị cho mảng 2 chiều
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &dynamicMatrix[i][j]);
        }
    }

    // Giải phóng bộ nhớ
    for (int i = 0; i < rows; i++)
    {
        free(dynamicMatrix[i]);
    }
    free(dynamicMatrix);
}
