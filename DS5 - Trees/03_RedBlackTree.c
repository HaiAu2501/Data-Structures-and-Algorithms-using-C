#include <stdio.h>
#include <stdlib.h>

// ĐỀ BÀI: Thiết lập cấu trúc dữ liệu cây đỏ đen (Red-Black Tree) và các hàm xử lý.

/* MÔ TẢ:
 | - Cây đỏ đen (Red-Black Tree hay RBT) là một cấu trúc dữ liệu cây nhị phân tìm kiếm (BST) mà mỗi Node được gán thêm một thuộc tính màu (đỏ hoặc đen).
 | - Cây đỏ đen phải tuân thủ một số quy tắc sau:
 |   1. Mỗi Node là đỏ hoặc đen.
 |   2. Gốc của cây luôn là Node đen.
 |   3. Tất cả Node lá (NIL) là Node đen (Node lá không chứa dữ liệu).
 |   4. Nếu một Node là đỏ thì cả hai con của nó đều là đen.
 |   5. Từ mỗi Node đến mọi Node lá (NIL) đi qua cùng số lượng Node đen.
 | - Cây đỏ đen có thể được sử dụng để tìm kiếm, thêm, xóa một phần tử trong thời gian O(log n) với n là số lượng Node trong cây.
 | - Cây mà có toàn bộ Node màu đen vẫn là cây đỏ đen hợp lệ.
 */

// Định nghĩa màu của Node: Đỏ hoặc Đen
typedef enum Color
{
    RED,
    BLACK
} Color;

// Cấu trúc Node của cây đỏ đen
typedef struct Node
{
    int data;            // Dữ liệu của Node
    Color color;         // Màu của Node
    struct Node *left;   // Con trái
    struct Node *right;  // Con phải
    struct Node *parent; // Cha, khác với BST, mỗi Node trong RBT cần lưu trữ thêm con trỏ tới cha
} Node;

// Cấu trúc cây đỏ đen
typedef struct RedBlackTree
{
    Node *root; // Gốc của cây
} RedBlackTree;

// Khởi tạo Node mới, mặc định màu đỏ
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->color = RED; // Mặc định màu đỏ
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

// Hàm chèn một Node mới vào RBT | Time: O(log n)
/* - Chèn Node mới vào cây như BST.
 | - Node mới được chèn luôn có màu đỏ (mặc định).
 | - Sau khi chèn, nếu vi phạm các quy tắc của RBT thì cần phải điều chỉnh lại cây.
 | - Xét 5 điều kiện:
 | 1. Mọi Node đều phải có màu đỏ hoặc đen. => Đã thỏa mãn.
 | 2. Gốc của cây phải luôn là Node đen.    => Không thỏa mãn nếu Node mới là gốc.
 | 3. Mọi Node lá (NIL) phải là Node đen.   => Đã thỏa mãn.
 | 4. Nếu một Node là đỏ thì cả hai con của nó phải là đen. => Cần kiểm tra và điều chỉnh.
 | 5. Từ mỗi Node đến mọi Node lá (NIL) phải đi qua cùng số lượng Node đen. => Cần kiểm tra và điều chỉnh (nếu cần, thỏa mãn nếu Node thêm vào màu đỏ).
 | - Các bước của hàm chèn:
 | 1. Chèn Node mới vào (màu đỏ).
 | 2. Nếu Node mới là gốc thì cập nhật màu đen cho Node đó.
 | 3. Nếu Node mới không là gốc -> Kiểm tra màu của Node cha:
 |    + Nếu Node cha là đen thì không cần điều chỉnh.
 |    + Nếu Node cha là đỏ (thì Node ông đen) -> Kiểm tra màu của Node chú:
 |         +> Nếu Node chú là đỏ:
 |                     B
 |                    / \
 |                   R   R
 |                  /
 |                 R
 |         -> Đổi màu cho Node cha và Node chú, đổi màu cho Node ông (nếu có) và kiểm tra lại từ Node ông.
 |         [Vì Node cha và Node chú đều là đỏ nên cần phải đổi màu cho Node cha và Node chú để thỏa mãn điều kiện 4 (và 5).]
 |         +> Nếu Node chú là đen hoặc NULL:
 |                     B
 |                    / \
 |                   R   B
 |                  /
 |                 R
 |         -> Xoay cây và đổi màu cho Node cha và Node ông (nếu có).
 |
 */

/* XOAY CÂY:
 | - Cây đỏ đen sử dụng 2 phép xoay: xoay trái và xoay phải.
 | - Xoay trái: Đối với Node x, xoay trái sẽ đưa con phải của x lên trở thành cha của x.
 |   Là phép xoay:
 |          x              y
 |           \   =====>   /
 |            y          x
 | - Xoay phải: Đối với Node x, xoay phải sẽ đưa con trái của x lên trở thành cha của x.
 |   Là phép xoay:
 |            y          x
 |           /   =====>   \
 |          x              y
 | - Xoay trái và xoay phải đều giữ nguyên tính chất của cây đỏ đen.
 */

// Hàm xoay trái
void leftRotate(RedBlackTree *rbt, Node *x)
{
    Node *y = x->right;
    x->right = y->left;
    if (y->left != NULL)
    {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL)
    {
        rbt->root = y;
    }
    else if (x == x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

// Hàm xoay phải
void rightRotate(RedBlackTree *rbt, Node *x)
{
    Node *y = x->left;
    x->left = y->right;
    if (y->right != NULL)
    {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL)
    {
        rbt->root = y;
    }
    else if (x == x->parent->right)
    {
        x->parent->right = y;
    }
    else
    {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

// Hàm chèn Node mới vào RBT
void insertNode(RedBlackTree *rbt, int data)
{
    Node *newNode = createNode(data);
    Node *y = NULL;
    Node *x = rbt->root;

    // Tìm vị trí để chèn Node mới
    while (x != NULL)
    {
        y = x;
        if (newNode->data < x->data)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }

    // Gán cha cho Node mới
    newNode->parent = y;

    // Nếu cây rỗng thì Node mới là gốc
    if (y == NULL)
    {
        rbt->root = newNode;
    }
    else if (newNode->data < y->data)
    {
        y->left = newNode;
    }
    else
    {
        y->right = newNode;
    }

    // Điều chỉnh cây
    while (newNode != rbt->root && newNode->parent->color == RED)
    {
        if (newNode->parent == newNode->parent->parent->left)
        {
            Node *uncle = newNode->parent->parent->right;
            if (uncle != NULL && uncle->color == RED)
            {
                newNode->parent->color = BLACK;
                uncle->color = BLACK;
                newNode->parent->parent->color = RED;
                newNode = newNode->parent->parent;
            }
            else
            {
                if (newNode == newNode->parent->right)
                {
                    newNode = newNode->parent;
                    leftRotate(rbt, newNode);
                }
                newNode->parent->color = BLACK;
                newNode->parent->parent->color = RED;
                rightRotate(rbt, newNode->parent->parent);
            }
        }
        else
        {
            Node *uncle = newNode->parent->parent->left;
            if (uncle != NULL && uncle->color == RED)
            {
                newNode->parent->color = BLACK;
                uncle->color = BLACK;
                newNode->parent->parent->color = RED;
                newNode = newNode->parent->parent;
            }
            else
            {
                if (newNode == newNode->parent->left)
                {
                    newNode = newNode->parent;
                    rightRotate(rbt, newNode);
                }
                newNode->parent->color = BLACK;
                newNode->parent->parent->color = RED;
                leftRotate(rbt, newNode->parent->parent);
            }
        }
    }
    rbt->root->color = BLACK;
}

// Hàm inOrder: Duyệt cây theo thứ tự trung tố
void inOrder(Node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

int main()
{
    RedBlackTree rbt;
    rbt.root = NULL;

    // Thêm các Node vào cây
    insertNode(&rbt, 5);
    insertNode(&rbt, 3);
    insertNode(&rbt, 2);
    insertNode(&rbt, 4);
    insertNode(&rbt, 7);
    insertNode(&rbt, 6);
    insertNode(&rbt, 8);

    // Duyệt cây theo thứ tự In-order
    inOrder(rbt.root);
    printf("\n");

    return 0;
}
