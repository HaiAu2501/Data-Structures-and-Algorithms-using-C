#include <stdio.h>
#include <stdlib.h>

// ĐỀ BÀI: Thiết lập cấu trúc dữ liệu cây đỏ đen (Red-Black Tree) và các hàm xử lý.

/* MÔ TẢ:
 | - Cây đỏ đen (Red-Black Tree) là một cấu trúc dữ liệu cây nhị phân tìm kiếm (BST) mà mỗi Node được gán thêm một thuộc tính màu (đỏ hoặc đen).
 | - Cây đỏ đen phải tuân thủ một số quy tắc sau:
 |   1. Mỗi Node là đỏ hoặc đen.
 |   2. Gốc của cây luôn là Node đen.
 |   3. Mỗi Node lá (NULL) được coi là Node đen.
 |   4. Nếu một Node là đỏ thì cả hai con của nó đều là đen.
 |   5. Từ mỗi Node đến mọi Node lá (NULL) đi qua cùng số lượng Node đen.
 | - Cây đỏ đen có thể được sử dụng để tìm kiếm, thêm, xóa một phần tử trong thời gian O(log n) với n là số lượng Node trong cây.
 */

// Cấu trúc Node của cây đỏ đen
typedef struct Node
{
    int data;
    char color;          // Màu của Node: 'R' (Red) hoặc 'B' (Black)
    struct Node *left;   // Con trái
    struct Node *right;  // Con phải
    struct Node *parent; // Cha
} Node;

// Hàm tạo một Node mới
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->color = 'R'; // Mặc định màu của Node mới là đỏ
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}