#include <stdio.h>
#include <stdlib.h>

// Hàng đợi 2 đầu (Deque hay Double-ended queue) là một cấu trúc dữ liệu cho phép thêm và xóa phần tử ở cả hai đầu của hàng đợi.
/* Các phép toán cơ bản:
 * - insertFront(): Thêm một phần tử vào đầu hàng đợi.
 * - insertBack(): Thêm một phần tử vào cuối hàng đợi.
 * - eraseFront(): Xóa phần tử ở đầu hàng đợi.
 * - eraseBack(): Xóa phần tử ở cuối hàng đợi.
 * - front(): Lấy giá trị của phần tử ở đầu hàng đợi.
 * - back(): Lấy giá trị của phần tử ở cuối hàng đợi.
 * - isEmpty(): Kiểm tra xem hàng đợi có rỗng không.
 */

// Đinh nghĩa cấu trúc Node cho hàng đợi 2 đầu
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

// Triển khai hàng đợi 2 đầu bằng danh sách liên kết đôi vì:
// Thao tác thêm và lấy ra ở cả hai đầu đều có độ phức tạp O(1).

// Hàm tạo một Node mới
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Đinh nghĩa cấu trúc Deque
typedef struct Deque
{
    Node *front, *back;
} Deque;

// Hàm khởi tạo một hàng đợi 2 đầu
Deque *createDeque()
{
    Deque *q = (Deque *)malloc(sizeof(Deque));
    q->front = q->back = NULL;
    return q;
}

// Hàm in ra các phần tử trong hàng đợi
void printDeque(Deque *q)
{
    Node *current = q->front;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Hàm thêm một phần tử vào đầu hàng đợi
void push_front(Deque *q, int data)
{
    Node *newNode = createNode(data);

    // Nếu hàng đợi rỗng, gán cả front và back trỏ đến Node mới
    if (q->front == NULL)
    {
        q->front = q->back = newNode;
    }
    else
    {
        newNode->next = q->front;
        q->front->prev = newNode;
        q->front = newNode;
    }
}

// Hàm thêm một phần tử vào cuối hàng đợi
void push_back(Deque *q, int data)
{
    Node *newNode = createNode(data);

    // Nếu hàng đợi rỗng, gán cả front và back trỏ đến Node mới
    if (q->front == NULL)
    {
        q->front = q->back = newNode;
    }
    else
    {
        q->back->next = newNode;
        newNode->prev = q->back;
        q->back = newNode;
    }
}

// Hàm lấy ra phần tử ở đầu hàng đợi
int pop_front(Deque *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else if (q->front == q->back)
    {
        int data = q->front->data;
        q->front = q->back = NULL;
        return data;
    }
    else
    {
        int data = q->front->data;
        q->front = q->front->next;
        q->front->prev = NULL;
        return data;
    }
}

// Hàm lấy ra phần tử ở cuối hàng đợi
int pop_back(Deque *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else if (q->front == q->back)
    {
        int data = q->back->data;
        q->front = q->back = NULL;
        return data;
    }
    else
    {
        int data = q->back->data;
        q->back = q->back->prev;
        q->back->next = NULL;
        return data;
    }
}

void main()
{
    Deque *q = createDeque();

    push_front(q, 1);
    push_front(q, 2);
    push_back(q, 3);
    push_back(q, 4);

    printf("%d\n", pop_front(q)); // 2
    printDeque(q);                // 1 3 4

    printf("%d\n", pop_back(q)); // 4
    printDeque(q);               // 1 3

    printf("%d\n", pop_front(q)); // 1
    printDeque(q);                // 3

    printf("%d\n", pop_back(q)); // 3
    printDeque(q);               // NULL

    printf("%d\n", pop_front(q)); // Queue is empty, -1
}