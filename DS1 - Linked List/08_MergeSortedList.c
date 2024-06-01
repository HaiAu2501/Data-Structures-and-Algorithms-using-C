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

// Hàm tạo Node mới
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Hàm in ra DSLK
void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

Node *head1 = NULL;
Node *head2 = NULL;

// Hàm hợp 2 DSLK đã cho -> Time: O(max(n, m)) với n, m là số phần tử của 2 DSLK
Node *mergeSortedLists(Node *head1, Node *head2)
{
    // Khởi tạo DSLK rỗng, là kết quả của việc hợp 2 DSLK đã cho
    Node *head = NULL;
    Node *current = NULL;

    // Lặp qua cả 2 DSLK
    while (head1 != NULL && head2 != NULL)
    {
        // Chọn phần tử nhỏ hơn trong 2 DSLK để thêm vào DSLK kết quả
        Node *smaller = NULL;
        if (head1->data < head2->data)
        {
            smaller = head1;
            head1 = head1->next;
        }
        else
        {
            smaller = head2;
            head2 = head2->next;
        }

        // Thêm smaller vào DSLK kết quả
        if (head == NULL)
        {
            head = smaller;
            current = head;
        }
        else
        {
            current->next = smaller;
            current = current->next;
        }
    }

    // Nêu một trong 2 DSLK còn phần tử thì thêm hết vào DSLK kết quả
    if (head1 != NULL)
    {
        if (head == NULL)
            head = head1;
        else
            current->next = head1;
    }
    if (head2 != NULL)
    {
        if (head == NULL)
            head = head2;
        else
            current->next = head2;
    }
    return head;
}

// Cách khác: Sử dụng đệ quy
Node *merge(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    Node *head = NULL;
    if (head1->data < head2->data)
    {
        head = head1;
        head->next = merge(head1->next, head2);
    }
    else
    {
        head = head2;
        head->next = merge(head1, head2->next);
    }
    return head;
}

int main()
{
    Node *current;

    // Đọc đầu vào và tạo danh sách liên kết 1
    int x;
    while (scanf("%d", &x) == 1)
    {
        if (head1 == NULL)
        {
            head1 = createNode(x);
            current = head1;
        }
        else
        {
            current->next = createNode(x);
            current = current->next;
        }
        if (getchar() == '\n')
            break;
    }

    // Đọc đầu vào và tạo danh sách liên kết 2
    while (scanf("%d", &x) == 1)
    {
        if (head2 == NULL)
        {
            head2 = createNode(x);
            current = head2;
        }
        else
        {
            current->next = createNode(x);
            current = current->next;
        }
        if (getchar() == '\n')
            break;
    }

    // Hợp 2 danh sách liên kết đã cho
    Node *head = merge(head1, head2);

    // In ra danh sách liên kết kết quả
    printList(head);

    return 0;
}
