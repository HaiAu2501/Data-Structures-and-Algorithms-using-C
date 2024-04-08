#include <stdio.h>
#include <string.h>

void binaryGen(int n, char a[])
{
    if (strlen(a) == n)
    {
        printf("%s\n", a);
        return;
    }

    char a1[n];
    strcpy(a1, a);
    binaryGen(n, strcat(a, "0"));
    binaryGen(n, strcat(a1, "1"));
}

int main()
{
    int n;
    scanf("%d", &n);

    char a[n];
    a[0] = '\0';
    binaryGen(n, a);
}