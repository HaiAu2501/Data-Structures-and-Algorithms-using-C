#include <stdio.h>

int main()
{
    int n = 100;                     // n là biến kiểu int lưu giá trị 100
    int *p = &n;                     // p là biến con trỏ lưu địa chỉ của n
    printf("Dereference: %d\n", *p); // toán tử * truy xuất giá trị của biến mà con trỏ p trỏ tới
    // Kết quả in ra: 100

    // Nếu thay đổi n, giá trị của p cũng thay đổi theo
    n = 200;
    printf("Afer change n: %d\n", *p); // Kết quả in ra: 200

    // Nếu thay đổi giá trị của p, giá trị của n cũng thay đổi theo
    *p = 300;
    printf("After change p: %d\n", n); // Kết quả in ra: 300
}