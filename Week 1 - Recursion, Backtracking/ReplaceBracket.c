#include <stdio.h>
#include <stdbool.h>

int n, a[100];
char stack[100];
int top = -1;

bool isValid()
{
    int balance = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
            balance++;
        else
            balance--;
        if (balance < 0)
            return false;
    }
    return balance == 0;
}

void printExpression()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
    printf("\n");
}

void solve(int pos)
{
    if (pos == n)
    {
        if (isValid())
        {
            printExpression();
        }
        return;
    }
    if (a[pos] == 0)
    {
        a[pos] = 1; // Thay '?' bằng '('
        solve(pos + 1);
        a[pos] = 2; // Thay '?' bằng ')'
        solve(pos + 1);
        a[pos] = 0; // Phục hồi giá trị ban đầu
    }
    else
    {
        solve(pos + 1);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    solve(0);
    return 0;
}
