#include <stdio.h>
#include <stdlib.h>

// Đề bài: Cộng hai đa thức bằng danh sách liên kết
/* - Mỗi đa thức được biểu diễn bằng một danh sách liên kết với mỗi nút chứa một hệ số và một số mũ.
 * - Cộng hai đa thức: Cộng các hệ số của các số mũ giống nhau và thêm các số mũ không giống nhau vào đa thức kết quả.
 */

typedef struct Node
{
    int coeff; // Hệ số
    int exp;   // Số mũ
    struct Node *next;
} Node;

// Hàm tạo một đơn thức
Node *createNode(int coeff, int exp)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm một đơn thức vào đa thức
void addTerm(Node **head, int coeff, int exp)
{
    Node *newNode = createNode(coeff, exp);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *cur = *head;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = newNode;
    }
}

// Hàm cộng hai đa thức
Node *addPolynomial(Node *poly1, Node *poly2)
{
    Node *result = NULL;
    Node *cur1 = poly1;
    Node *cur2 = poly2;

    while (cur1 != NULL && cur2 != NULL)
    {
        if (cur1->exp > cur2->exp)
        {
            addTerm(&result, cur1->coeff, cur1->exp);
            cur1 = cur1->next;
        }
        else if (cur1->exp < cur2->exp)
        {
            addTerm(&result, cur2->coeff, cur2->exp);
            cur2 = cur2->next;
        }
        else
        {
            addTerm(&result, cur1->coeff + cur2->coeff, cur1->exp);
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
    }

    // Thêm các đơn thức còn lại của đa thức 1
    while (cur1 != NULL)
    {
        addTerm(&result, cur1->coeff, cur1->exp);
        cur1 = cur1->next;
    }

    // Thêm các đơn thức còn lại của đa thức 2
    while (cur2 != NULL)
    {
        addTerm(&result, cur2->coeff, cur2->exp);
        cur2 = cur2->next;
    }

    return result;
}

// Hàm in đa thức
void printPolynomial(Node *poly)
{
    Node *cur = poly;
    while (cur != NULL)
    {
        printf("%dx^%d", cur->coeff, cur->exp);
        cur = cur->next;
        if (cur != NULL)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

int main()
{
    Node *poly1 = NULL;
    Node *poly2 = NULL;

    // Tạo đa thức 1: 3x^2 + 4x^1 + 5x^0
    addTerm(&poly1, 3, 2);
    addTerm(&poly1, 4, 1);
    addTerm(&poly1, 5, 0);

    // Tạo đa thức 2: 4x^5 + 2x^1 + 3x^0
    addTerm(&poly2, 4, 5);
    addTerm(&poly2, 2, 1);
    addTerm(&poly2, 3, 0);

    printf("Polynomial 1: ");
    printPolynomial(poly1);

    printf("Polynomial 2: ");
    printPolynomial(poly2);

    Node *sum = addPolynomial(poly1, poly2);
    printf("Sum: ");
    printPolynomial(sum);

    return 0;
}
