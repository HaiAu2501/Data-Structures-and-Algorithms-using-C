#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        sum += x;
    }

    printf("%d", sum);
}