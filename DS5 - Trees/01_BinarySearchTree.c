#include <stdio.h>
#include <stdlib.h>

// ĐỀ BÀI: Thiết lập cấu trúc dữ liệu cây nhị phân tìm kiếm (BST) và các hàm xử lý.

/* MÔ TẢ:
 | - Cây nhị phân tìm kiếm (BST) là một cấu trúc dữ liệu cây nhị phân mà mỗi Node có tối đa 2 con,
 |   Node con bên trái có giá trị nhỏ hơn Node cha và Node con bên phải có giá trị lớn hơn Node cha.
 | - BST có thể được sử dụng để tìm kiếm, thêm, xóa một phần tử trong thời gian O(h) với h là chiều cao của cây.
 */

// Cấu trúc Node của cây nhị phân tìm kiếm
typedef struct Node
{
    int data;           // Dữ liệu của Node
    struct Node *left;  // Con trái
    struct Node *right; // Con phải
} Node;

// Hàm tạo một Node mới | Time: O(1)
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// HÀM THÊM MỘT NODE VÀO CÂY NHỊ PHÂN TÌM KIẾM | Time: O(h) với h là chiều cao của cây
void addNode(Node **root, int data)
{
    // Nếu cây rỗng thì tạo Node mới và gán vào gốc cây
    if (*root == NULL)
    {
        *root = createNode(data);
        return;
    }

    if (data < (*root)->data)
        // Nếu giá trị cần thêm nhỏ hơn giá trị của Node hiện tại thì thêm vào cây con bên trái
        addNode(&(*root)->left, data);
    else
        // Nếu giá trị cần thêm lớn hơn hoặc bằng giá trị của Node hiện tại thì thêm vào cây con bên phải
        addNode(&(*root)->right, data);
}

// HÀM TÌM KIẾM NODE TRONG CÂY NHỊ PHÂN TÌM KIẾM
// Time: O(h) với h là chiều cao của cây, O(n) trong trường hợp xấu nhất khi cây trở thành danh sách liên kết
/* - Tìm kiếm Node có giá trị data trong cây nhị phân tìm kiếm.
 | - Nếu tìm thấy thì trả về Node đó, ngược lại trả về NULL.
 */
Node *searchNode(Node *root, int data)
{
    // Nếu cây rỗng hoặc Node hiện tại chính là Node cần tìm thì trả về Node hiện tại
    if (root == NULL || root->data == data)
        return root;

    if (data < root->data)
        // Nếu giá trị cần tìm nhỏ hơn giá trị của Node hiện tại thì tìm kiếm trong cây con bên trái
        return searchNode(root->left, data);
    else
        // Nếu giá trị cần tìm lớn hơn giá trị của Node hiện tại thì tìm kiếm trong cây con bên phải
        return searchNode(root->right, data);
}

// HÀM XÓA NODE TRONG CÂY NHỊ PHÂN TÌM KIẾM | Time: O(h) với h là chiều cao của cây
void deleteNode(Node **root, int data)
{
    // Nếu cây rỗng thì trả về
    if (*root == NULL)
        return;

    if (data < (*root)->data)
        // Nếu giá trị cần xóa nhỏ hơn giá trị của Node hiện tại thì xóa trong cây con bên trái
        deleteNode(&(*root)->left, data);
    else if (data > (*root)->data)
        // Nếu giá trị cần xóa lớn hơn giá trị của Node hiện tại thì xóa trong cây con bên phải
        deleteNode(&(*root)->right, data);
    else
    {
        // Nếu Node cần xóa không có hoặc chỉ có một con
        // thì gán Node con đó vào Node cần xóa và giải phóng Node cần xóa
        if ((*root)->left == NULL)
        {
            Node *temp = (*root)->right;
            free(*root);
            *root = temp;
        }
        else if ((*root)->right == NULL)
        {
            Node *temp = (*root)->left;
            free(*root);
            *root = temp;
        }
        else
        {
            // Nếu Node cần xóa có cả hai con
            // thì tìm Node lớn nhất trong cây con bên trái hoặc Node nhỏ nhất trong cây con bên phải
            Node *temp = (*root)->right;
            while (temp->left != NULL)
                temp = temp->left;
            (*root)->data = temp->data;
            deleteNode(&(*root)->right, temp->data);
        }
    }
}

// HÀM DUYỆT CÂY THEO THỨ TỰ TRƯỚC (Pre-order)
/* - Duyệt cây theo thứ tự: Node - Trái - Phải
 | - In ra giá trị của Node hiện tại trước khi duyệt sang cây con bên trái và cây con bên phải.
 */
void preOrder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// HÀM DUYỆT CÂY THEO THỨ TỰ GIỮA (In-order)
/* - Duyệt cây theo thứ tự: Trái - Node - Phải
 | - In ra giá trị của Node hiện tại sau khi duyệt cây con bên trái và trước khi duyệt cây con bên phải.
 | - Kết quả của việc duyệt cây theo thứ tự In-order sẽ được sắp xếp tăng dần.
 */
void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// HÀM DUYỆT CÂY THEO THỨ TỰ SAU (Post-order)
/* - Duyệt cây theo thứ tự: Trái - Phải - Node
 | - In ra giá trị của Node hiện tại sau khi duyệt cây con bên trái và cây con bên phải.
 */
void postOrder(Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    Node *root = NULL;

    // Thêm các Node vào cây
    addNode(&root, 5);
    addNode(&root, 3);
    addNode(&root, 2);
    addNode(&root, 4);
    addNode(&root, 7);
    addNode(&root, 6);
    addNode(&root, 8);

    /* Cây nhị phân tìm kiếm sau khi thêm các Node:
     |               5
     |             /   \
     |            3     7
     |           / \   / \
     |          2   4 6   8
     | - Pre-order: 5 3 2 4 7 6 8
     | - In-order: 2 3 4 5 6 7 8
     | - Post-order: 2 4 3 6 8 7 5
     */

    // Duyệt cây theo thứ tự Pre-order
    printf("Pre-order: ");
    preOrder(root);
    printf("\n");

    // Duyệt cây theo thứ tự In-order
    printf("In-order: ");
    inOrder(root);
    printf("\n");

    // Duyệt cây theo thứ tự Post-order
    printf("Post-order: ");
    postOrder(root);
    printf("\n");

    // Tìm kiếm Node có giá trị 4
    Node *searchedNode = searchNode(root, 4);
    if (searchedNode != NULL)
        printf("Node 4 found\n");
    else
        printf("Node 4 not found\n");

    // Xóa Node có giá trị 4
    deleteNode(&root, 4);

    // Duyệt cây theo thứ tự In-order sau khi xóa Node có giá trị 4
    printf("In-order after deleting 4: ");
    inOrder(root);
    printf("\n");

    // Xóa Node có giá trị 7
    deleteNode(&root, 7);

    // Duyệt cây theo thứ tự In-order sau khi xóa Node có giá trị 7
    printf("In-order after deleting 7: ");
    inOrder(root);
    printf("\n");

    return 0;
}