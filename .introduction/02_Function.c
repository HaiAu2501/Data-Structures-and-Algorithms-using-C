#include <stdio.h>

// Trong ngôn ngữ C, có 2 kiểu truyền tham số (argument/parameter) cho hàm:
/* - Truyền tham trị (pass by value): truyền giá trị của biến cho hàm, hàm chỉ thao tác trên bản sao giá trị đó
 * điều này có nghĩa, mọi thay đổi trên biến trong hàm không ảnh hưởng đến biến gốc
 * - Truyền tham chiếu (pass by reference): truyền địa chỉ của biến cho hàm, hàm thao tác trực tiếp trên biến gốc
 * điều này có nghĩa, mọi thay đổi trên biến trong hàm ảnh hưởng đến biến gốc
 */

// Ví dụ về truyền tham trị
void addTen_ByValue(int a)
{
    a += 10;
}

// Ví dụ về truyền tham chiếu
void addTen_ByReference(int *a) // a là một biến con trỏ trỏ đến kiểu dữ liệu int
{
    *a += 10;
}

void main()
{
    int a = 5;

    addTen_ByValue(a);
    printf("a = %d\n", a); // a = 5, không bị thay đổi

    addTen_ByReference(&a);
    printf("a = %d\n", a); // a = 15, bị thay đổi thực sự
}