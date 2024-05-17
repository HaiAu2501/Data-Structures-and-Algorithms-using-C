#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *map[7] = {"?", "(", "{", "[", ")", "}", "]"};
char stack[100];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

int is_valid(char *expression)
{
    top = -1;
    for (int i = 0; expression[i] != '\0'; i++)
    {
        char c = expression[i];
        if (c == '(' || c == '{' || c == '[')
        {
            push(c);
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (top == -1)
                return 0;
            char t = pop();
            if ((c == ')' && t != '(') || (c == '}' && t != '{') || (c == ']' && t != '['))
            {
                return 0;
            }
        }
    }
    return top == -1;
}

void generate_valid_expressions(int *a, int n, char *current, int index)
{
    if (index == n)
    {
        if (is_valid(current))
        {
            for (int i = 0; i < n; i++)
            {
                printf("%d", a[i]);
            }
            printf(" ");
        }
        return;
    }

    if (a[index] == 0)
    {
        // Try replacing '?' with each type of bracket
        int original = a[index];
        for (int i = 1; i <= 6; i++)
        {
            a[index] = i;
            current[index] = map[i][0];
            generate_valid_expressions(a, n, current, index + 1);
        }
        a[index] = original;
    }
    else
    {
        current[index] = map[a[index]][0];
        generate_valid_expressions(a, n, current, index + 1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int *a = malloc(n * sizeof(int));
    char *current = malloc(n + 1);
    current[n] = '\0';

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    generate_valid_expressions(a, n, current, 0);
    free(a);
    free(current);
    return 0;
}
