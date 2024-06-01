#include <stdio.h>
#include <stdlib.h>

// Thời hạn lưu trữ (storage duration) bao gồm:
/* - Thời hạn lưu trữ tĩnh (static storage duration): Biến tồn tại trong suốt thời gian chạy chương trình
 * chỉ được khởi tạo một lần duy nhất trước khi chương trình bắt đầu chạy, dù khai báo ngoài hoặc trong hàm
 * - Thời hạn lưu trữ tự động (automatic storage duration): Biến tồn tại trong phạm vi của một hàm
 * tự động được tạo ra khi hàm được gọi và tự động bị hủy khi hàm kết thúc.
 * - Thời hạn lưu trữ động (allocated storage duration): Biến này được cấp phảt động bởi chương trình
 * từ một khu vực bộ nhớ được gọi là heap (thông qua hàm như malloc). Biến tồn tại cho đến khi chúng được giải phóng bằng free
 */

// Khi nào nên sử dụng bộ nhớ được cấp phát động?
/* - Khi không thể xác định nhu cầu lưu trữ của một chương trình trước khi chương trình chạy
 * Chẳng hạn: Khi không biết trước kích thước của dữ liệu mà chương trình sẽ xử lý; khi số lượng
 * đối tượng cần xử lý không được biết trước (xử lý mảng động, tạo cấu trúc dữ liệu động)
 */

// Bộ nhớ được cấp phát động kém hiệu quả hơn so với bộ nhớ tĩnh vì:
/* - Chi phí quản lý bộ nhớ: Khi sử dụng bộ nhớ động, trình quản lý bộ nhớ (thường là một phần của hệ điều hành)
 * cần phải tìm kiếm và quản lý các khối bộ nhớ trên heap. Việc này đòi hỏi các thao tác bổ sung để kiểm soát và
 * sắp xếp lại bộ nhớ, gây ra độ trễ và sử dụng CPU thêm.
 * - Cần giải phóng bộ nhớ: Người lập trình phải chủ động giải phóng bộ nhớ đã cấp phát khi nó không còn được sử dụng nữa.
 * Nếu không làm vậy sẽ gây ra hiện tượng rò rỉ bộ nhớ, nơi bộ nhớ không còn cần thiết nhưng không được trả lại cho hệ thống,
 * dẫn đến lãng phí tài nguyên.
 */

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