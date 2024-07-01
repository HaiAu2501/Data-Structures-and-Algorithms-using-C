#include <stdio.h>

/* ĐỀ BÀI: Biểu diễn CTDL cây bằng mảng
 | - Giả sử T là cây với các nút 1, 2, ..., n.
 | - Biểu diễn T bằng mảng A với n phần tử sao cho:
 | + Phần tử A[i] chứa cha của nút i.
 | + Nếu i là nút gốc thì A[i] = 0.
 */

/* ĐỀ BÀI: Biểu diễn CTDL cây bằng con trái và em kế cận phải
 | - Mỗi nút của câu hoặc là:
 | + Không có con.
 | + Có con, thì có đúng 1 con cực trái.
 | + Không có em kế cận phải.
 | + Có đúng 1 em kế cận phải.
 | -> Để biểu diễn cây: lưu trữ thông tin về con cực trái và em kế cận phải của mỗi nút.
 */

// Định nghĩa cấu trúc Node
typedef struct Node
{
    int data;                   // Dữ liệu của Node
    struct Node *leftMostChild; // Con cực trái
    struct Node *rightSibling;  // Em kế cận phải
} Node;

Node *root; // Node gốc của cây

// Hàm tạo một Node mới
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->leftMostChild = NULL;
    newNode->rightSibling = NULL;
    return newNode;
}

// Duyệt cây theo thứ tự trước (Preorder)
// Đưa ra nút mỗi khi gặp nút đó
void preOrder(Node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);

    // Duyệt qua tất cả các con cùng cấp
    Node *child = root->leftMostChild;
    while (child != NULL)
    {
        preOrder(child);
        child = child->rightSibling;
    }
}

// Duyệt cây theo thứ tự sau (Postorder)
// Đưa ra nút khi qua nó ở lần cuối trước khi quay lại nút cha
void postOrder(Node *root)
{
    if (root == NULL)
        return;

    // Duyệt qua tất cả các con cùng cấp
    Node *child = root->leftMostChild;
    while (child != NULL)
    {
        postOrder(child);
        child = child->rightSibling;
    }

    printf("%d ", root->data);
}

// Duyệt cây theo thứ tự giữa (Inorder)
// Đưa ra lá ngay khi đi qua nó, còn những nút trong được đưa ra khi lần thứ hai được đi qua
void inOrder(Node *root)
{
    if (root == NULL)
        return;

    // Duyệt các con cùng cấp bên trái
    Node *child = root->leftMostChild;
    if (child != NULL)
    {
        inOrder(child);
    }

    printf("%d ", root->data);

    // Duyệt qua tất cả các con cùng cấp bên phải
    while (child != NULL && child->rightSibling != NULL)
    {
        inOrder(child->rightSibling);
        child = child->rightSibling;
    }
}

// Chiều cao của nút trên cây là bằng độ dài đường đi dài nhất từ nút đó đến nút lá cộng thêm 1
// Chiều cao của cây là chiều cao của nút gốc

// Hàm tìm độ cao của 1 nút trên cây -> Độ phức tạp: O(n), xấu nhất khi cây trở thành danh sách liên kết
int height(Node *node)
{
    if (node == NULL)
        return 0;
    int maxHeight = 0;
    Node *child = node->leftMostChild;
    // Tìm độ cao lớn nhất của các con cùng cấp
    while (child != NULL)
    {
        int heightChild = height(child);
        if (heightChild > maxHeight)
            maxHeight = heightChild;
        child = child->rightSibling;
    }
    return maxHeight + 1;
}

// Độ sâu của nút trên cây là độ dài đường đi từ nút gốc đến nút đó cộng thêm 1
// Độ sâu của nút gốc là 1

// Hàm tìm độ sâu của 1 nút trên cây -> Độ phức tạp: O(n), xấu nhất khi cây trở thành danh sách liên kết
int depth(Node *root, int key, int d)
{
    // key là giá trị của nút cần tìm độ sâu, d là độ sâu của nút hiện tại
    if (root == NULL)
        return -1;
    if (root->data == key)
        return d;
    Node *child = root->leftMostChild;
    while (child != NULL)
    {
        if (child->data == key)
            return d + 1;
        int depthChild = depth(child, key, d + 1);
        if (depthChild != -1)
            return depthChild;
        child = child->rightSibling;
    }
    return -1;
}

int findDepth(Node *root, int key)
{
    return depth(root, key, 1);
}
