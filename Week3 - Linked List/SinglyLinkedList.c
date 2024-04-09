#include <stdio.h>
#include <stdlib.h>

// Danh sách liên kết (linked list) là một cấu trúc dữ liệu mà mỗi phần tử trong danh sách
// chứa một giá trị và một con trỏ trỏ đến phần tử tiếp theo trong danh sách

// Định nghĩa cấu trúc Node
typedef struct Node
{
    int data;          // Dữ liệu của Node, ở đây là một số nguyên
    struct Node *next; // Con trỏ trỏ đến Node tiếp theo
} Node;

// Hàm tạo một Node mới
Node *create(int data) // data là dữ liệu của Node, hàm này trả về con trỏ kiểu Node
{
    Node *node = malloc(sizeof(Node)); // malloc trả về con trỏ kiểu void, cần ép kiểu về con trỏ kiểu Node
    node->data = data;                 // Gán giá trị data cho Node
    node->next = NULL;                 // Khởi tạo con trỏ next trỏ đến NULL
    return node;
}

// Hàm in ra danh sách liên kết
void printList(Node *head)
{
    Node *current = head;   // Con trỏ current trỏ đến head
    while (current != NULL) // Duyệt qua danh sách liên kết
    {
        printf("%d ", current->data); // In ra dữ liệu của Node hiện tại
        current = current->next;      // Di chuyển con trỏ current đến Node tiếp theo
    }
    printf("\n");
}

// Hàm thêm một Node vào cuối danh sách liên kết
void apppend(Node *head, int data)
{
    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = create(data);
}

// Hàm thêm một Node vào đầu danh sách liên kết
void prepend(Node **head, int data)
{
    Node *newNode = create(data);
    newNode->next = *head;
    *head = newNode;
}

/* Nhận xét:
 * - Hàm này sử dụng **head để tham chiếu đến con trỏ head, vì khi thêm một Node vào đầu danh sách
 *   thì con trỏ head sẽ thay đổi, nếu sử dụng *head thì con trỏ head chỉ thay đổi trong hàm
 *   và không ảnh hưởng đến con trỏ head ở ngoài hàm
 * - Hàm này tạo một Node mới với dữ liệu là data, gán con trỏ next của Node mới trỏ đến con trỏ head
 */

// Hàm thêm một Node vào trước một Node cho trước
void insertBefore(Node **head, Node *before, int data)
{
    Node *newNode = create(data);

    // Kiểm tra xem danh sách có rỗng hoặc before có phải là Node đầu tiên không
    if (*head == NULL || before == *head)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        Node *current = *head;
        while (current->next != before)
        {
            current = current->next;
        }

        newNode->next = before;
        current->next = newNode;
    }
}

// Hàm thêm một Node vào sau một Node cho trước
void insertAfter(Node *after, int data)
{
    Node *newNode = create(data);
    newNode->next = after->next;
    after->next = newNode;
}

// Hàm xóa một Node với dữ liệu cho trước
void deleteNode(Node **head, int data)
{
    Node *current = *head;
    Node *prev = NULL;

    // Duyệt qua danh sách liên kết
    while (current != NULL)
    {
        // Nếu tìm thấy Node cần xóa
        if (current->data == data)
        {
            // Nếu Node cần xóa là Node đầu tiên
            if (prev == NULL)
            {
                *head = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            free(current); // Giải phóng bộ nhớ của Node cần xóa
            return;
        }

        prev = current;
        current = current->next;
    }
}

// Ví dụ
int main()
{
    // Tạo một danh sách liên kết
    Node *head = create(1);       // Tạo một Node đầu tiên với dữ liệu là 1
    head->next = create(2);       // Tạo một Node tiếp theo với dữ liệu là 2
    head->next->next = create(3); // Tạo một Node tiếp theo với dữ liệu là 3

    // In ra danh sách liên kết
    printList(head);

    // Thêm một Node vào cuối danh sách liên kết
    apppend(head, 4);
    printList(head);

    // Thêm một Node vào đầu danh sách liên kết
    prepend(&head, 0);
    printList(head);

    // Thêm một Node vào trước một Node cho trước
    insertBefore(&head, head->next->next, 5);
    printList(head);

    // Thêm một Node vào sau một Node cho trước
    insertAfter(head->next->next, 6);
    printList(head);

    // Xóa một Node với dữ liệu cho trước
    deleteNode(&head, 3);
    printList(head);

    return 0;
}
