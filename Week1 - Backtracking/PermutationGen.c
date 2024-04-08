#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void permute(int *a, int start, int end)
{
    if (start == end)
    {
        printArray(a, end + 1);
    }
    else
    {
        for (int i = end; i >= 0; i--)
        {
            swap(&a[end], &a[i]);
            permute(a, start, end - 1);
            swap(&a[end], &a[i]);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }

    permute(a, 0, n - 1);
    return 0;
}