#include <stdio.h>
#include <stdlib.h>

// Ngăn xếp (Stack) là một cấu trúc dữ liệu dạng LIFO (Last In First Out, vào sau ra trước)
/* Ngăn xếp có thể được triển khai bằng cách sử dụng mảng hoặc danh sách liên kết.
 * Trong bài này, chúng ta sẽ sử dụng danh sách liên kết để triển khai ngăn xếp.
 * Các phép toán cơ bản trên ngăn xếp:
 * - push: Thêm một phần tử vào đỉnh ngăn xếp.
 * - pop: Xóa phần tử ở đỉnh ngăn xếp.
 * - peek/top: Lấy giá trị của phần tử ở đỉnh ngăn xếp (mà không xóa nó).
 * - isEmpty: Kiểm tra xem ngăn xếp có rỗng không.
 */

// Định nghĩa cấu trúc Node
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Không cần hàm khởi tạo ngắn xếp vì stack trống được biểu diễn bởi con trỏ 'NULL'

// Hàm tạo một Node mới
Node *newNode(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Hàm kiểm tra ngăn xếp có rỗng không
int isEmpty(Node *root) // root là đỉnh ngăn xếp, nếu root = NULL thì ngăn xếp rỗng
{
    return !root;
}

// Hàm thêm một phần tử vào đỉnh ngăn xếp
/* - Thêm một phần tử vào đỉnh ngăn xếp tương đương với việc thêm một Node mới vào đầu danh sách liên kết.
 * - Đầu tiên, tạo một Node mới với dữ liệu là data.
 * - Gán con trỏ next của Node mới trỏ đến root (đỉnh ngăn xếp).
 * - Cập nhật root trỏ đến Node mới.
 */
void push(Node **root, int data)
{
    Node *new_node = newNode(data);
    new_node->next = *root;
    *root = new_node;
}

// Hàm lấy giá trị của phần tử ở đỉnh ngăn xếp (và xóa nó khỏi ngăn xếp)
/* - Lấy giá trị của phần tử ở đỉnh ngăn xếp tương đương với việc lấy giá trị của Node đầu tiên trong danh sách liên kết.
 * - Lưu giá trị của Node đầu tiên vào biến result.
 * - Cập nhật root trỏ đến Node thứ hai trong danh sách liên kết.
 * - Trả về giá trị của result.
 */
int pop(Node **root)
{
    int result = (*root)->data;
    *root = (*root)->next;
    return result;
}

// Hàm lấy giá trị của phần tử ở đỉnh ngăn xếp (mà không xóa nó)
int peek(Node *root)
{
    return root->data;
}

// Hàm in ngăn xếp
void printStack(Node *root)
{
    while (root != NULL)
    {
        printf("%d ", root->data);
        root = root->next;
    }
    printf("\n");
}

void main()
{
    Node *root = NULL;

    push(&root, 1);
    push(&root, 2);
    push(&root, 3);

    printf("Stack: ");
    printStack(root);

    printf("Top element: %d\n", peek(root));

    printf("Pop: %d\n", pop(&root));
    printf("Stack after pop: ");
    printStack(root);
}
