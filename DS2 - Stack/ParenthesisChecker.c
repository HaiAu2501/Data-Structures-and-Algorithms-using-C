#include <stdio.h>
#include <stdlib.h>

/* ĐỀ BÀI: Kiểm tra dãy ngoặc cân đối.
 | -  Ví dụ: [()]{} là dãy ngoặc cân đối, còn [({)}] không cân đối
 | - Sử dụng ngăn xếp để kiểm tra dãy ngoặc cân đối.
 | - Mỗi khi gặp một dấu mở ngoặc (gồm '(', '[', '{'), đẩy nó vào ngăn xếp.
 | - Mỗi khi gặp một dấu đóng ngoặc, kiểm tra xem dấu này có tương ứng với dấu mở ngoặc trên cùng của ngăn xếp hay không.
 | + Nếu không tương ứng, dãy ngoặc không cân đối.
 | + Nếu tương ứng, loại bỏ dấu mở ngoặc trên cùng khỏi ngăn xếp.
 | - Nếu ngăn xếp rỗng sau khi duyệt hết dãy ngoặc, dãy ngoặc cân đối.
 */

// Định nghĩa cấu trúc Node
typedef struct Node
{
    char data;
    struct Node *next;
} Node;

// Hàm tạo một Node mới
Node *createNode(char data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm một phần tử vào đỉnh ngăn xếp
void push(Node **top, char data)
{
    Node *newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

// Hàm lấy giá trị của phần tử ở đỉnh ngăn xếp (và xóa nó khỏi ngăn xếp)
char pop(Node **top)
{
    if (*top == NULL)
        return '\0';
    char data = (*top)->data;
    Node *temp = *top;
    *top = (*top)->next;
    free(temp);
    return data;
}

// Hàm kiểm tra xem dãy ngoặc có cân đối hay không
int isBalanced(char *s)
{
    Node *stack = NULL;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            push(&stack, s[i]);
        else
        {
            if (stack == NULL)
                return 0;
            char top = pop(&stack);
            if ((s[i] == ')' && top != '(') || (s[i] == ']' && top != '[') || (s[i] == '}' && top != '{'))
                return 0;
        }
    }
    return stack == NULL;
}

int main()
{
    char s[100];
    printf("Nhap day ngoac: ");
    gets(s);
    if (isBalanced(s))
        printf("Day ngoac can doi\n");
    else
        printf("Day ngoac khong can doi\n");
    return 0;
}