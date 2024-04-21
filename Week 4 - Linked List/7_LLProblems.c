#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Đề bài: Xây dựng DSLK với các khóa ban đầu a[1..n] sau đó thực hiện 1 số thao tác.
/* Đầu vào:
 * - Dòng 1: Số nguyên dương n.
 * - Dòng 2: Các số a[1..n].
 * - Các dòng tiếp theo là các lệnh thao tác (kết thúc bởi #):
 *   + addlast k
 *   + addfirst k
 *   + add after u v: thêm phần tử u vào sau phần tử v (nếu v đã tồn tại và u chưa tồn tại)
 *   + add before u v: thêm phần tử u vào trước phần tử v (nếu v đã tồn tại và u chưa tồn tại)
 *   + remove k
 *   + reverse
 */

// Sử dụng danh sách liên kết đơn

// ############ Các struct và hàm cơ bản ############
typedef struct Node
{
    int key;
    struct Node *next;
} Node;

Node *createNode(int key)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

Node *find(Node *head, int key)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->key == key)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Hàm thêm vào cuối DSLK
// Sử dụng **head (thay vì *head) để thay đổi *head ở ngoài hàm
// Trong trường hợp *head = NULL, cần thay đổi *head nên cần dùng **head
void addLast(Node **head, int key)
{
    if (find(*head, key) != NULL)
        return; // Do not add if key exists
    Node *newNode = createNode(key);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Hàm thêm vào đầu DSLK
// Sử dụng **head để thay đổi *head ở ngoài hàm
// Khi thêm vào đầu, *head cần thay đổi nên cần dùng **head
void addFirst(Node **head, int key)
{
    if (find(*head, key) != NULL)
        return; // Do not add if key exists
    Node *newNode = createNode(key);
    newNode->next = *head;
    *head = newNode;
}

void addAfter(Node **head, int u, int v)
{
    if (find(*head, u) != NULL)
        return; // Do not add if u exists
    Node *vNode = find(*head, v);
    if (vNode != NULL)
    { // Add only if v exists
        Node *newNode = createNode(u);
        newNode->next = vNode->next;
        vNode->next = newNode;
    }
}

// Hàm thêm vào trước một Node cho trước
// Sử dụng **head để thay đổi *head ở ngoài hàm
// Nếu Node bị thêm vào trước là Node đầu tiên -> addFirst
void addBefore(Node **head, int u, int v)
{
    if (find(*head, u) != NULL)
        return; // Nếu u đã tồn tại thì không thực hiện hàm này nữa
    if (*head == NULL)
        return; // Nếu DSLK rỗng cũng không thực hiện

    if ((*head)->key == v)
    {
        addFirst(head, u);
    }
    else
    {
        Node *current = *head;
        while (current->next != NULL && current->next->key != v)
        {
            current = current->next;
        }
        if (current->next != NULL)
        { // v exists in the list
            Node *newNode = createNode(u);
            newNode->next = current->next;
            current->next = newNode;
        }
    }
}

void removeNode(Node **head, int key)
{
    if (find(*head, key) == NULL)
        return; // Do not remove if key doesn't exist
    Node *temp = *head, *prev = NULL;
    while (temp != NULL && temp->key != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return; // Key not found
    if (prev == NULL)
    {
        *head = temp->next; // Head needs to be removed
    }
    else
    {
        prev->next = temp->next;
    }
    free(temp);
}

void reverseList(Node **head)
{
    Node *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL)
    {
        next = current->next; // Lưu trữ con trỏ next của Node hiện tại
        current->next = prev; // Đảo ngược con trỏ next của Node hiện tại
        prev = current;       // Cập nhật prev
        current = next;       // Cập nhật current
    }
    *head = prev; // Cập nhật head mới (khi current = NULL, prev chính là head mới)
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->key);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int n, key;
    scanf("%d", &n);
    Node *head = NULL;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &key);
        addLast(&head, key);
    }

    char command[20];
    int u, v;
    while (scanf("%s", command) && command[0] != '#')
    {
        if (strcmp(command, "addlast") == 0)
        {
            scanf("%d", &key);
            addLast(&head, key);
        }
        else if (strcmp(command, "addfirst") == 0)
        {
            scanf("%d", &key);
            addFirst(&head, key);
        }
        else if (strcmp(command, "addafter") == 0)
        {
            scanf("%d %d", &u, &v);
            addAfter(&head, u, v);
        }
        else if (strcmp(command, "addbefore") == 0)
        {
            scanf("%d %d", &u, &v);
            addBefore(&head, u, v);
        }
        else if (strcmp(command, "remove") == 0)
        {
            scanf("%d", &key);
            removeNode(&head, key);
        }
        else if (strcmp(command, "reverse") == 0)
        {
            reverseList(&head);
        }
    }

    printList(head);
    return 0;
}
