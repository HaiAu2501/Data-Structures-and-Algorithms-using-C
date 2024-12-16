#include <stdio.h>

/* ĐỀ BÀI: Giải bài toán cái ba lô nhị phân (0/1 Knapsack Problem) bằng phương pháp Branch and Bound.
 | - Đầu vào: Số lượng vật phẩm n, dung tích ba lô M, mảng w chứa trọng lượng của n vật phẩm, mảng v chứa giá trị của n vật phẩm.
 | - Đầu ra: Giá trị lớn nhất có thể đựng được trong ba lô với trọng lượng không vượt quá M.
 | - Tức là, sum(v[i] * x[i]) -> max với điều kiện sum(w[i] * x[i]) <= M, x[i] = 0 hoặc 1.
 */

/* THUẬT TOÁN NHÁNH CẬN:
 | - Săp xếp các vật phẩm theo tỷ lệ giá trị/trọng lượng giảm dần.
 */