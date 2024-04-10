#include <stdio.h>
#include <stdlib.h>

// Đề bài: Cho mảng prices[1..n] với prices[i] là giá của loại hoa quả thứ i.
// Nếu mua quả thứ i với giá prices[i] sẽ được nhận miễn phí i quả tiếp theo (có thể chọn miễn phí hoặc mua tiếp).
// Tìm số tiền nhỏ nhất cần thiết để nhận hết các quả.
/* Giải bằng thuật toán Quy hoạch động:
 * - Gọi coins[i] là số tiền nhỏ nhất cần thiết mà ta đã dùng cho i quả đầu tiên
 *
 */