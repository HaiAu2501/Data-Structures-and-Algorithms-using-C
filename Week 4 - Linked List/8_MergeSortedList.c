#include <stdio.h>
#include <stdlib.h>

// Đề bài: Cho 2 DSLK (đơn) đã được sắp xếp tăng dần. Hãy hợp 2 DSLK này thành 1 DSLK mới vẫn giữ nguyên thứ tự tăng dần.
// Ví dụ: 1 -> 3 -> 5 và 2 -> 4 -> 6 => Kết quả: 1 -> 2 -> 3 -> 4 -> 5 -> 6

// Định nghĩa cấu trúc Node
typedef struct Node
{
    int data;
    struct Node *next;
} Node;