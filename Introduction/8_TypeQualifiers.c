#include <stdio.h>

// Các biến có thể được bổ nghĩa bởi các từ khóa: const, volatile, restrict
/* - const: Biến không thể thay đổi giá trị.
 * - volatile: Biến có thể thay đổi bất kỳ lúc nào.
 * - restrict: Biến chỉ được truy cập thông qua con trỏ mà nó được khai báo.
 */

int main()
{
    const int a = 10;
    // a = 20; -> Lỗi biên dịch: không thể thay đổi giá trị của biến const
}