#include <stdio.h>
#include <stdlib.h>

// Đề bài: Cho dãy nhị phân (độ dài <= 10^5).
// Tìm số cách chia dãy thành các đoạn liên tiếp sao cho mỗi đoạn có đúng một số 1.
// Ví dụ:
// 0 1 0 -> có 1 cách
// 0 1 0 0 1 -> có 3 cách
/* Giải bài toán bằng thuật toán Quy hoạch động:
 * - Gọi num[i] là số cách chia dãy a[1..i] thỏa mãn yêu cầu đề bài.
 * - Nếu a[i + 1] = 0, num[i + 1] = num[i].
 *

 */