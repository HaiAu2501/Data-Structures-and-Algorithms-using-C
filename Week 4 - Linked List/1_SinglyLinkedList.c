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
    Node *node = (Node *)malloc(sizeof(Node)); // malloc trả về con trỏ kiểu void, cần ép kiểu về con trỏ kiểu Node
    node->data = data;                         // Gán giá trị data cho Node
    node->next = NULL;                         // Khởi tạo con trỏ next trỏ đến NULL
    return node;
}

// Hàm in ra danh sách liên kết
void printList(Node *head)
{
    while (head != NULL) // Duyệt qua danh sách liên kết
    {
        printf("%d ", head->data); // In ra dữ liệu của Node hiện tại
        head = head->next;         // Di chuyển con trỏ đến Node tiếp theo
    }
    printf("\n");
}

// Hàm thêm một Node vào cuối danh sách liên kết
void append(Node **head, int data)
{
    if (*head == NULL)
    {
        *head = create(data);
    }
    else
    {
        Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = create(data);
    }
}

// Hàm thêm một Node vào đầu danh sách liên kết
void prepend(Node **head, int data)
{
    if (*head == NULL)
    {
        *head = create(data);
    }
    else
    {
        Node *newNode = create(data);
        newNode->next = *head;
        *head = newNode;
    }
}

/* Nhận xét:
 * - Hàm này sử dụng **head để tham chiếu đến con trỏ head, vì khi thêm một Node vào đầu danh sách
 *   thì con trỏ head sẽ thay đổi, nếu sử dụng *head thì con trỏ head chỉ thay đổi trong hàm
 *   và không ảnh hưởng đến con trỏ head ở ngoài hàm
 * - Hàm này tạo một Node mới với dữ liệu là data, gán con trỏ next của Node mới trỏ đến con trỏ head
 */

// Hàm thêm một Node vào trước Node thứ chứa dữ liệu key
void insertBefore(Node **head, int key, int data)
{
    Node *newNode = create(data);
    Node *current = *head;
    Node *prev = NULL;

    while (current != NULL)
    {
        if (current->data == key)
        {
            if (prev == NULL)
            {
                newNode->next = *head;
                *head = newNode;
            }
            else
            {
                prev->next = newNode;
                newNode->next = current;
            }
            return;
        }

        prev = current;
        current = current->next;
    }
}

// Hàm thêm một Node vào sau một Node chứa dữ liệu key
void insertAfter(Node **head, int key, int data)
{
    Node *newNode = create(data);
    Node *current = *head;

    while (current != NULL)
    {
        if (current->data == key)
        {
            newNode->next = current->next;
            current->next = newNode;
            return;
        }

        current = current->next;
    }
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
    Node *head = NULL; // Khởi tạo danh sách liên kết rỗng

    int n;

    while (scanf("%d", &n) == 1)
    {
        append(&head, n);
        if (getchar() == '\n')
            break;
    }

    printList(head);

    append(&head, 10);
    printList(head);

    prepend(&head, 20);
    printList(head);

    return 0;
}
