#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct Point
    {
        int x, y;
    };

    // Cấp phát bộ nhớ động cho biến kiểu struct Point
    // sizeof(struct Point) trả về kích thước của biến kiểu struct Point
    // Hàm malloc trả về con trỏ kiểu void, cần ép kiểu về kiểu con trỏ kiểu struct Point
    struct Point *p = (struct Point *)malloc(sizeof(struct Point));
    p->x = 10; // Thay thế p.x = 10;
    p->y = 20; // Thay thế p.y = 20;

    printf("%d %d\n", p->x, p->y);

    free(p); // Giải phóng bộ nhớ đã cấp phát cho biến p
}