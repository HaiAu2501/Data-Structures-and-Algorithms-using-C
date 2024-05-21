#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc Node
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

// Định nghĩa cấu trúc Doubly Linked List
typedef struct List
{
    Node *head;
    Node *tail;
} List;

// Một DSLK đôi rỗng là head = tail = NULL.

// Các thao tác:
/*
 * - find, update, count.
 * - pushFirst, pushLast, pushAfter, pushBefore.
 * - popFirst, popLast, popAfter.
 * - reverse.
 * - merge
 * - printList.
 */

// Hàm tạo Node mới
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Hàm tạo DSLK đôi
List *createList()
{
    List *newList = (List *)malloc(sizeof(List));
    newList->head = NULL;
    newList->tail = NULL;
    return newList;
}

// Tìm Node đầu tiên có data == key
Node *find(List *list, int key)
{
    if (list->head == NULL)
        return NULL;
    Node *current = list->head;
    while (current != NULL)
    {
        if (current->data == key)
            return current;
        current = current->next;
    }
    return NULL;
}

// Đếm số phần tử
int count(List *list)
{
    int count = 0;
    if (list->head == NULL)
        return 0;
    Node *current = list->head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

// In ra danh sách
void printList(List *list)
{
    Node *current = list->head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}

// Thêm phần tử vào đầu: O(1)
void pushFirst(List *list, int data)
{
    // Nếu danh sách rỗng, cả head và tail là Node mới
    if (list->head == NULL)
        list->head = list->tail = createNode(data);
    else
    {
        Node *new = createNode(data);
        Node *temp = list->head;
        temp->prev = new;
        new->next = temp;
        list->head = new;
    }
}

// Thêm phần tử vào cuối: O(1)
void pushBack(List *list, int data)
{
    // Nếu danh sách rỗng, cả head và tail là Node mới
    if (list->head == NULL)
        list->head = list->tail = createNode(data);
    else
    {
        Node *new = createNode(data);
        list->tail->next = new;
        new->prev = list->tail;
        list->tail = new;
    }
}

// Thêm phần tử vào trước phần tử có data = key
void pushBefore(List *list, int key, int data)
{
    // Nếu danh sách rỗng, không làm gì cả
    if (list->head == NULL)
        return;
    // Nếu head giữ key, thực hiện pushFirst
    if (list->head->data == key)
        pushFirst(list, data);
    else
    {
        Node *current = list->head->next;
        while (current != NULL)
        {
            if (current->data == key)
            {
                Node *new = createNode(data);
                Node *prev = current->prev;
                prev->next = new;
                new->prev = prev;
                new->next = current;
                current->prev = new;
            }
            current = current->next;
        }
    }
}

// Thêm phần tử vào sau phần tử có data = key
void pushAfter(List *list, int key, int data)
{
    if (list->head == NULL)
    {
        return;
    }

    if (list->tail->data == key)
    {
        pushBack(list, data);
    }
    else
    {
        Node *current = list->head;
        while (current != NULL)
        {
            if (current->data == key)
            {
                Node *new = createNode(data);
                Node *next = current->next;
                current->next = new;
                new->prev = current;
                new->next = next;
                next->prev = new;
            }
            current = current->next;
        }
    }
}

// Hàm đảo ngược DSLK đôi
void reverse(List *list)
{
    if (list->head == NULL)
        return;
    Node *prev = NULL, *current = list->head, *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }
    list->head = prev;
    list->tail = list->head;
}

void main()
{
    List *list = createList();

    int x;
    while (scanf("%d", &x) == 1)
    {
        pushBack(list, x);
        if (getchar() == '\n')
            break;
    }

    pushBefore(list, 4, 3);
    pushAfter(list, 4, 5);

    reverse(list);

    printList(list);
}