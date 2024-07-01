#include <stdio.h>
#include <stdlib.h>

/* Đề bài: Cho một xâu các số nguyên không âm và một số nguyên.
 | Yêu cầu: Tìm tất cả các cách thêm dấu "+", "-", "*" giữa các chữ số sao cho giá trị biểu thức thu được bằng số nguyên dương đã cho.
 */

/* Một số lưu ý khi giải:
 | - Số nguyên không âm có thể chứa nhiều hơn một chữ số. Ví dụ 102 -> 10*2.
 | -> Do đó phải tìm toán hạng bằng cách cộng các chữ số liên tiếp lại.
 | - Tại mỗi vị trí giữa các số, có 4 khả năng: không thêm dấu, thêm dấu "+", thêm dấu "-", thêm dấu "*".
 | - Toán tử ưu tiên cao nhất là "*", ví dụ: 12 + 3 * 4 = 24 (ĐÚNG), 12 + 3 * 4 = 15 * 4 = 60 (SAI).
 | -> Do đó khi tính giá trị biểu thức:
 |    - Xét từ trái qua phải, lưu trữ prev.
 |    - Nếu gặp '*' -> lấy (result - prev) + prev * current.
 | Ví dụ: 1 + 2 * 3 * 4 + 5
 | -> 1, prev = 1                  -> result = 1
 | -> 1 + 2, prev = 2              -> result = 3
 | -> 1 + 2 * 3, prev = 6          -> result = (3 - 2) + 6 = 7
 | -> 1 + 2 * 3 * 4, prev = 24     -> result = (7 - 6) + 6 * 4 = 25
 | -> 1 + 2 * 3 * 4 + 5, prev = 5  -> result = 30 (chỉ khi gặp dấu '*' mới - prev + prev * current)
 */

#define MAX_LENGTH 100

char s[MAX_LENGTH];        // Xâu các số nguyên không âm
int value;                 // Số nguyên đã cho
char expr[MAX_LENGTH * 2]; // Xâu biểu thức (dài gấp đôi để chứa toán tử)

// Hàm kiểm tra xem có phải toán tử không
int isOperator(char c)
{
    return c == '+' || c == '-' || c == '*';
}

// Hàm kiểm tra xem biểu thức có bằng kết quả không
int isValid()
{
    int result = 0;
    int prev = 0;
    int operand = 0;
    int i = 0;

    // Lấy toán hạng đầu tiên
    while (expr[i] != '\0' && !isOperator(expr[i]))
    {
        operand = operand * 10 + (expr[i] - '0');
        i++;
    }
    // Kết thúc vòng lặp này, expr[i] đang là toán tử hoặc kết thúc xâu

    result += operand;
    prev = operand;

    while (expr[i] != '\0')
    {
        char op = expr[i]; // Lấy toán tử
        i++;               // Bỏ qua toán tử để lấy toán hạng

        operand = 0;
        while (expr[i] != '\0' && !isOperator(expr[i]))
        {
            operand = operand * 10 + (expr[i] - '0');
            i++;
        } // Kết thúc vòng lặp này, expr[i] đang là toán tử hoặc kết thúc xâu

        if (op == '+')
        {
            result += operand;
            prev = operand;
        }
        else if (op == '-')
        {
            result -= operand;
            prev = -operand;
        }
        else if (op == '*')
        {
            result = (result - prev) + prev * operand;
            prev = prev * operand;
        }
    }
    return result == value;
}

// Hàm cho quay lui -> Time complexity: O(4^n)
/* Tham số:
 * - pos: Vị trí hiện tại trong xâu s
 * - exprPos: Vị trí hiện tại trong xâu expr
 */
void generateExpression(int pos, int exprPos)
{
    if (s[pos] == '\0')
    {
        expr[exprPos] = '\0';
        if (isValid())
        {
            printf("%s\n", expr);
        }
        return;
    }

    // Không thêm dấu
    expr[exprPos] = s[pos];
    generateExpression(pos + 1, exprPos + 1); // Vì có 1 vị trí trong s đã xét, 1 vị trí trong expr đã điền

    // Thêm dấu '+'
    expr[exprPos] = '+';
    expr[exprPos + 1] = s[pos];
    generateExpression(pos + 1, exprPos + 2); // Vì có 1 vị trí trong s đã xét, 2 vị trí trong expr đã điền

    // Thêm dấu '-'
    expr[exprPos] = '-';
    expr[exprPos + 1] = s[pos];
    generateExpression(pos + 1, exprPos + 2); // Vì có 1 vị trí trong s đã xét, 2 vị trí trong expr đã điền

    // Thêm dấu '*'
    expr[exprPos] = '*';
    expr[exprPos + 1] = s[pos];
    generateExpression(pos + 1, exprPos + 2); // Vì có 1 vị trí trong s đã xét, 2 vị trí trong expr đã điền
}

int main()
{
    scanf("%s%d", s, &value);
    expr[0] = s[0];
    generateExpression(1, 1);
    return 0;
}