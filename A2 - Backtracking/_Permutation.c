#include <stdio.h>

/* ĐỀ BÀI: Sinh hoán vị của n số nguyên dương đầu tiên theo thứ tự từ điển.
 | - Sử dụng cách viết mã khác với Permutation.
 | - Sử dụng cấu trúc chung của Backtracking.
 */

/* THAM SỐ:
 | - Đầu vào: n.
 | - Đầu ra: In ra tất cả các hoán vị của n số nguyên dương đầu tiên theo thứ tự từ điển.
 */

/* CẤU TRÚC CHUNG CỦA BACKTRACKING:
 | - Bài toán liệt kê tổ hợp: Liệt kê các bộ x = (x[1], x[2], ..., x[n]) với x[i] thuộc A_i, i = 1..n và thỏa mãn ràng buộc P.
 | - Hàm quay lui:
 | try(k) { // Xây dựng bộ x[1..k]
 |     for (v in candidates(k)) { // Duyệt các ứng viên của x[k]
 |         x[k] = v; // Chọn ứng viên v
 |         // Kiểm tra ràng buộc
 |         if (k == n) { // Nếu x[1..n] là tổ hợp hợp lệ thì in ra
 |             print(x[1..n]);
 |         } else {
 |             try(k + 1); // Xây dựng tiếp x[k + 1]
 |         }
 |         // Quay lui về trạng thái trước đó
 |     }
 | }
 */

int n;

// Hàm in ra mảng
void printArray(int *a)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// Hàm sinh hoán vị
void try(int k, int *a, int *used)
{
    for (int i = 0; i < n; i++)
    {
        // Nếu chưa sử dụng i
        if (used[i] == 0)
        {
            // Chọn i vào vị trí k
            a[k] = i + 1;

            // Đánh dấu i đã sử dụng
            used[i] = 1;

            // Nếu đã chọn đủ n phần tử thì in ra
            if (k == n - 1)
                printArray(a);
            else
                // Gọi đệ quy xây dựng tiếp kể từ vị trí k + 1
                try(k + 1, a, used);

            // Bỏ đánh dấu i, khôi phục trạng thái
            used[i] = 0;
        }
    }
}

int main()
{
    scanf("%d", &n);
    int a[n], used[n];
    for (int i = 0; i < n; i++)
        used[i] = 0;
    try(0, a, used);
    return 0;
}