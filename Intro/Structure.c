#include <stdio.h>

int main()
{
    // structure là một kiểu dữ liệu dùng để lưu trữ nhiều biến có thể có kiểu dữ liệu khác nhau
    struct Point
    {
        int x, y;
    };

    struct Point p1; // Khai báo biến p1 có kiểu dữ liệu là struct Point
    p1.x = 10;       // Gán giá trị 10 cho biến x của p1
    p1.y = 20;       // Gán giá trị 20 cho biến y của p1

    printf("%d %d\n", p1.x, p1.y); // In ra giá trị của x và y của p1

    struct Circle
    {
        struct Point center; // Circle có một trường center kiểu Point
        double radius;
    };

    struct Circle c1; // Khai báo biến c1 có kiểu dữ liệu là struct Circle
    c1.center = p1;
    c1.radius = 5.5;

    double area = 3.14 * c1.radius * c1.radius;
    printf("%f\n", area);
}