#include <stdio.h>

// Các biến có thể được bổ nghĩa bởi các từ khóa: const, volatile, restrict
/* - const: Biến không thể thay đổi giá trị.
 * - volatile: Biến có thể thay đổi bất kỳ lúc nào.
 * - restrict: Biến chỉ được truy cập thông qua con trỏ mà nó được khai báo.
 */

// Bổ ngữ restrict được sử dụng trong các định nghĩa con trỏ để cho biết rằng
// con trỏ đó là con trỏ duy nhất truy cập đến vùng nhớ mà nó trỏ tới.
// Điều này giúp trình biên dịch tối ưu hóa các hoạt động của con trỏ,
// bởi vì nó có thể chắc chắn rằng không có con trỏ khác truy cập đến vùng nhớ đó.
void copyArray(int n, int *restrict a, int *restrict b)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
}
// -> a và b là 2 con trỏ duy nhất mà thông qua đó có thể truy cập hoặc thay đổi dữ liệu mà chúng trỏ tới.

int main()
{
    const int a = 10;
    // a = 20; -> Lỗi biên dịch: không thể thay đổi giá trị của biến const

    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[5];

    copyArray(5, arr2, arr1);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr2[i]);
    }

    return 0;
}
