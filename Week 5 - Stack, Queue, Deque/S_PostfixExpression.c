#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Biểu thức trung tố (Infix Expression) có toán tử ở giữa các toán hạng. Ví dụ: (A + B) * C
// Biểu thức hậu tố (Postfix Expression) có toán tử ở sau các toán hạng. Ví dụ: AB+C*

// Đề bài: Chuyển biểu thức trung tố sang hậu tố.
// -> Sử dụng thuật toán Shunting Yard, trong đó có sử dụng Stack.
/* Các bước:
 * 1. Khởi tạo stack rỗng và chuỗi kết quả rỗng.
 * 2. Duyệt các phần tử trong biểu thức trung tố từ trái sang phải:
 *    - Nếu gặp toán hạng, thêm vào chuỗi kết quả.
 *    - Nếu gặp "(" thì push vào stack.
 *    - Nếu gặp ")" thì pop các phần tử trong stack và thêm vào chuỗi kết quả cho đến khi gặp "(".
 *    - Nếu gặp toán tử:
 *    + Nếu stack không rỗng và độ ưu tiên của toán tử hiện tại <= toán tử ở đỉnh stack thì
 *      pop toán tử ở đỉnh stack ra và thêm vào chuỗi kết quả.
 *    + push toán tử hiện tại vào stack.
 * 3. Pop các phần tử còn lại trong stack và thêm vào chuỗi kết quả.
 */

// Độ ưu tiên của các toán tử:
int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (c == '^')
        return 3;
    return 0;
}

// Ví dụ, vẽ trạng thái stack và chuỗi kết quả sau mỗi bước: (A + B) * (C - D) -> A B + C D - *
/* Bước 1: Stack: RỖNG, Chuỗi kết quả: RỖNG
 * Bước 2: Stack: (, Chuỗi kết quả: RỖNG
 * Bước 3: Stack: (, Chuỗi kết quả: A
 * Bước 4: Stack: + (, Chuỗi kết quả: A
 * Bước 5: Stack: + (, Chuỗi kết quả: AB
 * Bước 6: Stack: RỖNG, Chuỗi kết quả: AB+
 * Bước 7: Stack: *, Chuỗi kết quả: AB+
 * Bước 8: Stack: ( *, Chuỗi kết quả: AB+
 * Bước 9: Stack: ( *, Chuỗi kết quả: AB+C
 * Bước 10: Stack: - ( *, Chuỗi kết quả: AB+C
 * Bước 11: Stack: - ( *, Chuỗi kết quả: AB+CD
 * Bước 12: Stack: *, Chuỗi kết quả: AB+CD-
 * Bước 13: Stack: RỖNG, Chuỗi kết quả: AB+CD-*
 */

// Cài đặt stack
typedef struct Node
{
    char data;
    struct Node *next;
} Node;

Node *createNode(char data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Node **top, char data)
{
    Node *newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

char pop(Node **top)
{
    if (*top == NULL)
        return '\0';
    Node *temp = *top;
    *top = (*top)->next;
    char data = temp->data;
    free(temp);
    return data;
}

// Hàm chuyển biểu thức trung tố sang hậu tố
void changeInfixToPostfix(char *infix, char *postfix)
{
    Node *top = NULL; // Khởi tạo stack rỗng
    int k = 0;        // Vị trí hiện tại của chuỗi kết quả

    for (int i = 0; infix[i] != '\0'; i++)
    {
        // Nếu là toán hạng, thêm vào postfix
        if ((infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= 'a' && infix[i] <= 'z'))
        {
            postfix[k++] = infix[i];
        }
        // Nếu là '(' thì push vào stack
        else if (infix[i] == '(')
        {
            push(&top, infix[i]);
        }
        // Nếu là ')' thì pop các phần tử trong stack và thêm vào postfix cho đến khi gặp '('
        else if (infix[i] == ')')
        {
            while (top != NULL && top->data != '(')
            {
                postfix[k++] = pop(&top);
            }
            pop(&top); // Pop '(' ra khỏi stack
        }
        // Nếu là toán tử
        else
        {
            // Nếu stack không rỗng và độ ưu tiên của toán tử hiện tại <= toán tử ở đỉnh stack
            while (top != NULL && precedence(infix[i]) <= precedence(top->data))
            {
                postfix[k++] = pop(&top);
            }
            // Push toán tử hiện tại vào stack
            push(&top, infix[i]);
        }
    }

    // Pop các phần tử còn lại trong stack và thêm vào postfix
    while (top != NULL)
    {
        postfix[k++] = pop(&top);
    }
    postfix[k] = '\0'; // Kết thúc chuỗi
}

int main()
{
    char infix[100], postfix[100] = "";
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    changeInfixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
