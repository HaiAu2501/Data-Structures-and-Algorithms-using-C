#include <stdio.h>
#include <stdlib.h>

// Danh sách liên kết đôi (Doubly Linked List) là một cấu trúc dữ liệu
// mà mỗi phần tử trong danh sách chứa một con trỏ tới phần tử trước và phần tử sau nó.
/* - Có hai nút đặc biệt là head và tail.
 * - Mỗi nút chứa một giá trị và hai con trỏ prev và next.
 * - Có hai kiểu biểu diễn danh sách liên kết đôi:
 *  + Kiểu 1: head trỏ tới nút đầu tiên,
 *
 */

// Định nghĩa cấu trúc Node trong danh sách liên kết đôi
typedef struct DNode
{
    int data;           // Giá trị của nút
    struct DNode *prev; // Con trỏ kiểu Node trỏ tới Node trước nó
    struct DNode *next; // Con trỏ kiểu Node trỏ tới Node sau nó
} DNode;

// Hàm tạo một Node
DNode *create(int data)
{
    DNode *node = malloc(sizeof(DNode));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

// Hàm in ra danh sách liên kết đôi từ đầu
void printListFromBegin(DNode *head)
{
    DNode *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Hàm in ra danh sách liên kết đôi từ cuối
void printListFromEnd(DNode *tail)
{
    DNode *current = tail;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

void main()
{
    DNode *head = create(1);
    head->next = create(2);
    head->next->prev = head;
    head->next->next = create(3);
    head->next->next->prev = head->next;
    DNode *tail = head->next->next;

    printListFromBegin(head);

    printListFromEnd(tail);
}