#include <stdio.h>
#include <stdlib.h>

// Đề bài: Tính giá trị biểu thức hậu tố.
// Ví dụ: 2 3 1 * + 9 - là 2 + 3 * 1 - 9 = 14

/* Sử dụng Stack */
/* 1. Khởi tạo stack rỗng.
 * 2. Duyệt các phần tử trong biểu thức hậu tố từ trái sang phải:
 *    - Nếu gặp toán hạng, push vào stack.
 *    - Nếu gặp toán tử, pop 2 toán hạng ra khỏi stack, thực hiện phép toán và push kết quả vào stack.
 * 3. Phần tử cuối cùng trong stack chính là kết quả cuối cùng.
 */

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Node **top, int data)
{
    Node *newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

int pop(Node **top)
{
    if (*top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    Node *temp = *top;
    *top = (*top)->next;
    int data = temp->data;
    free(temp);
    return data;
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

double evaluatePostfix(char *exp)
{
    Node *stack = NULL;
    for (int i = 0; exp[i]; i++)
    {
        if (exp[i] == ' ')
            continue;
        if (isOperator(exp[i]))
        {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            switch (exp[i])
            {
            case '+':
                push(&stack, operand1 + operand2);
                break;
            case '-':
                push(&stack, operand1 - operand2);
                break;
            case '*':
                push(&stack, operand1 * operand2);
                break;
            case '/':
                push(&stack, operand1 / operand2);
                break;
            }
        }
        else
        {
            int operand = 0;
            while (exp[i] >= '0' && exp[i] <= '9')
            {
                operand = operand * 10 + (exp[i] - '0');
                i++;
            }
            i--;
            push(&stack, operand);
        }
    }
    return pop(&stack);
}

int main()
{
    char exp[100];
    printf("Enter a postfix expression: ");
    scanf(" %[^\n]", exp);
    printf("Result: %.2f\n", evaluatePostfix(exp));
    return 0;
}