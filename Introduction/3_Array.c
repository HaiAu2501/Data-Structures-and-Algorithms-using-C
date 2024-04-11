#include <stdio.h>

int main()
{
    // Một mảng là một tập hợp các biến cùng kiểu dữ liệu
    int a[5];                // Mảng a gồm 5 phần tử kiểu int
    a[0] = 1;                // Gán giá trị 1 cho phần tử đầu tiên của mảng
    a[1] = 2;                // Gán giá trị 2 cho phần tử thứ 2 của mảng
    printf("%d\n", a[a[0]]); // a[a[0]] = a[1] = 2

    // Ngoài ra có thể khai báo
    int b[] = {1, 2, 3, 4, 5}; // Mảng b gồm 5 phần tử, giá trị của mỗi phần tử lần lượt là 1, 2, 3, 4, 5
    printf("%d\n", b[2]);      // In ra giá trị của phần tử thứ 3 của mảng b

    // Một mảng tương đương với một con trỏ trỏ tới phần tử đầu tiên của mảng
    int *p = a;
    int *q = &a[0];

    printf("%d\n", a[0]);
    printf("%d\n", *p);
    printf("%d\n", *q); // Kết quả in ra giống nhau

    // a là địa chỉ của phần tử đầu tiên của mảng a
    // *a tương đương với a[0]
    *a = 10;              // Gán giá trị 10 cho phần tử đầu tiên của mảng
    printf("%d\n", a[0]); // Kết quả in ra: 10

    // a + 1 là địa chỉ của phần tử thứ 2 của mảng a
    // a + 1 tương đương với &a[1]
    *(a + 1) = 20;        // Gán giá trị 20 cho phần tử thứ 2 của mảng
    printf("%d\n", a[1]); // Kết quả in ra: 20
}