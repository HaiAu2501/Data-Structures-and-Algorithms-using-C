#include <stdio.h>
#include <stdlib.h>

// Đề bài: Cho dãy dấu ngoặc có một số dấu ?, điền vào các dấu ? sao cho tạo thành dãy ngoặc đúng
/*
 * Ví dụ dãy: ((??)) có thể điền thành: ((())) hoặc (()())
 * Nhận xét:
 * - Sử dụng biến check để kiểm tra xem dãy ngoặc hiện tại có đúng không
 * - Nếu gặp '(' thì tăng check lên 1
 * - Nếu gặp ')' thì giảm check đi 1
 * - Nếu gặp '?' thì thử điền vào '(' hoặc ')' và thử các trường hợp
 * - Nếu check < 0 thì dãy ngoặc không hợp lệ
 * - Nếu điền xong mà check = 0 thì in ra dãy ngoặc
 */

int n;

// Hàm kiểm tra dãy ngoặc có hợp lệ không
int isValid(char s[])
{
    int check = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            check++;
        }
        else if (s[i] == ')')
        {
            check--;
        }

        if (check < 0)
        {
            return 0;
        }
    }
    return check == 0;
}

// Hàm in ra dãy ngoặc
void print(char s[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", s[i]);
    }

    printf("\n");
}

// Hàm quay lui điền dấu vào dãy ngoặc
void bracket(char s[], int k)
{
    if (k == n)
    {
        if (isValid(s))
        {
            print(s);
        }
        return;
    }

    if (s[k] == '?')
    {
        s[k] = '(';
        bracket(s, k + 1);
        s[k] = ')';
        bracket(s, k + 1);
        s[k] = '?';
    }
    else
    {
        bracket(s, k + 1);
    }
}

int main()
{
    scanf("%d", &n);

    char s[n];
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &s[i]);
    }

    bracket(s, 0);
    return 0;
}