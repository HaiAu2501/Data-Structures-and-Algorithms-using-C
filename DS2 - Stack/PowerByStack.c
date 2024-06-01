#include <stdio.h>
#include <stdlib.h>

// Đề bài: Tính a^n với n là số nguyên không âm, sử dụng stack thay vì đệ quy.
/* Ý tưởng:
 * - push lần lượt n/2 vào stack, đến khi = 0 thì dừng.
 * - result = 1, pop từng phần tử ra khỏi stack, nếu phần tử đó lẻ thì result = result * result * a, ngược lại result = result * result.
 */

// Định nghĩa các cấu trúc dữ liệu
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *top = NULL; // Khởi tạo stack rỗng

// Hàm tạo Node mới
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Hàm push phần tử vào stack
void push(Node **top, int data)
{
    Node *newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

// Hàm pop phần tử ra khỏi stack (xem data của phần tử đó, xóa nó khỏi stack)
int pop(Node **top)
{
    if (*top == NULL)
    {
        return -1;
    }

    Node *temp = (*top);
    *top = (*top)->next;
    int data = temp->data;
    free(temp);
    return data;
}

// Hàm tính a^n
double power(Node **top, double a, int n)
{
    double result = 1;

    // push lần lượt vào stack cho đến khi n = 0
    while (n > 0)
    {
        push(top, n);
        n /= 2;
    }

    // Pop đến khi stack rỗng
    while (*top != NULL)
    {
        n = pop(top);
        result *= result;
        if (n % 2 == 1)
        {
            result *= a;
        }
    }
    return result;
}

int main()
{
    double a;
    scanf("%lf", &a);

    int n;
    scanf("%d", &n);

    printf("%lf\n", power(&top, a, n));
    return 0;
}