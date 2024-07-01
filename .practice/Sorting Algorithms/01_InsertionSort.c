#include <stdio.h>
#include <stdlib.h>

// ĐỀ BÀI: Sắp xếp mảng số nguyên sử dụng thuật toán Insertion Sort (Sắp xếp chèn).

/* THUẬT TOÁN:
 | - Sắp xếp chèn là một thuật toán sắp xếp đơn giản và hiệu quả với dữ liệu nhỏ hoặc đã gần sắp xếp.
 | - Cách hoạt động:
 |  + Chia mảng thành 2 phần: một phần đã sắp xếp và một phần chưa sắp xếp.
 |  + Duyệt qua từng phần tử trong mảng chưa sắp xếp và chèn vào đúng vị trí trong mảng đã sắp xếp.
 | - Độ phức tạp: O(n^2) trong trường hợp xấu nhất và trung bình, O(n) trong trường hợp tốt nhất.
 */