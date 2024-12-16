#include <stdio.h>

/* ĐỀ BÀI: Cho một dãy ngoặc có một số dấu ?, điền vào các dấu ? sao cho tạo thành dãy ngoặc đúng.
 | - Ví dụ: Dãy ngoặc: ((??)) có thể điền thành: ((())) hoặc (()())
 | - Sử dụng cấu trúc chung của Backtracking.
 */

/* THAM SỐ:
 | - Đầu vào: Dãy ngoặc chứa một số dấu ?.
 | - Đầu ra: Các dãy ngoặc đúng.
 */

int n;

// Hàm kiểm tra dãy ngoặc có hợp lệ không
int isValid(char s[])
{
    int check = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            check++;
        else if (s[i] == ')')
            check--;

        if (check < 0)
            return 0;
    }
    return check == 0;
}

// Hàm in ra dãy ngoặc
void print(char s[])
{
    for (int i = 0; i < n; i++)
        printf("%c", s[i]);
    printf("\n");
}

// Hàm quay lui điền dấu vào dãy ngoặc
void try(int k, char s[])
{
    if (k == n)
    {
        if (isValid(s))
            print(s);
        return;
    }

    if (s[k] == '?')
    {
        // Thử điền vào dấu '(' hoặc ')' vào vị trí k và gọi đệ quy tiếp tục
        s[k] = '(';
        try(k + 1, s);
        s[k] = ')';
        try(k + 1, s);

        // Quay lui, trả lại dấu '?'
        s[k] = '?';
    }
    else
        try(k + 1, s);
}

int main()
{
    scanf("%d", &n);
    char s[n];
    for (int i = 0; i < n; i++)
        scanf(" %c", &s[i]);
    try(0, s);
    return 0;
}